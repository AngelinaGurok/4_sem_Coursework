#include "server.h"
#include "ui_server.h"
#include "controldata.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    //делаем окно без границ чтобы были только свои значки выйти, свернуть и resize
    setWindowFlags(Qt::FramelessWindowHint);
    //фиксированный размер окна
    setFixedSize(width(),height());

    udpsocket = new QUdpSocket(this);

    mserver.setParent(this);

    //сигнал подключения для клиента
    connect(&mserver, &QTcpServer::newConnection, this, &Server::new_client);
    datasize = 0;
}

void Server::on_connBt_clicked()
{
    //включить сервер
    mserver.listen(QHostAddress::Any,8080);
    //привязать udp1
    udpsocket->bind(8080);
    connect(udpsocket,&QUdpSocket::readyRead,this,&Server::rcvFile);
    qDebug("Waiting for connection...\n");
}

void Server::on_stopBt_clicked()
{
    //остановить поток
    th->terminate();
}

void Server::new_client()
{
    //сокет для связи с клиентом
    msocket = mserver.nextPendingConnection();
    //получение даннных
    connect(msocket,&QTcpSocket::readyRead,this,&Server::reciveData);
    ip =  msocket->peerAddress();
    ui->ipBrowser->append(ip.toString().remove("::ffff:"));
    th = new MyThread(msocket);
    //запустить поток
    th->start();
}

void Server::rcvFile()
{
    //получить данные от upd
    QByteArray baRecv;
    QString httpUrl;
    while(udpsocket->hasPendingDatagrams())
    {
        baRecv.resize(udpsocket->pendingDatagramSize());        //размер
        udpsocket->readDatagram(baRecv.data(),baRecv.size());   //данные (сообщение)
        QString strRecvData = baRecv;
        httpUrl = strRecvData;
        ui->msgBrowser->append(strRecvData);
    }
}

void Server::on_sendmsgBt_clicked()
{
   //сообщение которое хотим отправить
   QString msg = ui->sendEdit->toPlainText();
   //отправить сообщение
   QDateTime time = QDateTime::currentDateTime();       //получить текущее время системы
   QString str = time.toString("hh:mm:ss");             //установить формат отображения
   QString msgArr = str+":server<" + msg + ">";
   udpsocket->writeDatagram(msgArr.toUtf8(),ip, 8080);  //отпарвляем сообщение
   ui->msgBrowser->append(msgArr);
}

void Server::reciveData()
{
    //получение команд от клиента
    eventArr = msocket->readAll();
    QString strJson(eventArr);
    ui->ipBrowser->append(strJson);
    selecEvent();
}

void Server::selecEvent()
{
    //получить разрешение экрана
    QRect screenrect;
    QDesktopWidget* desktopWidget = QApplication::desktop();
    screenrect = desktopWidget->screenGeometry();

    //получить объект Json
    QJsonObject eventobj = JsonParse(eventArr);
    //выбираем событие
    int e = eventobj.value("event").toInt();
    if(e == RCEV_MSG)
    {
        ui->msgBrowser->append(eventobj.value("Msg").toString());
        ui->ipBrowser->append("RCEV_MSG");
    }
    else {
        double percentX = eventobj.value("PointX").toDouble();
        double percentY = eventobj.value("PointY").toDouble();

        pc_x = percentX*screenrect.width();
        pc_y = percentY*screenrect.height();

        switch (e)
        {
            case MOUSE_MOVE_TO:
               mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_MOVE,
                           pc_x*65532/screenrect.width(),
                           pc_y*65532/screenrect.height(), 0, 0);
               ui->ipBrowser->append("MOUSE_MOVE_TO");

            break;

            case MOUSE_LEFT:
                mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE,
                        pc_x*65532/screenrect.width(),
                        pc_y*65532/screenrect.height(), 0, 0);
                mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0, 0, 0);
                ui->ipBrowser->append("MOUSE_LEFT");
            break;

            case MOUSE_DOUBLE_CLICK:
                mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE,
                        pc_x*65532/screenrect.width(),
                        pc_y*65532/screenrect.height(), 0, 0);
                mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0, 0, 0);
                mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0, 0, 0);
                ui->ipBrowser->append("MOUSE_DOUBLE_CLICK");
            break;

            default:
                break;
        }
    }
}

QJsonObject Server::JsonParse(QByteArray array)
{
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(array, &error);
    if(error.error != QJsonParseError::NoError)//проверка на неправильный формат
    {
        qDebug()<<"json error";
    }
    QJsonObject obj = doc.object();
    return obj;
}

Server::~Server()
{
    delete ui;
}


void Server::on_closeBt_clicked()
{
    this->close();
}

void Server::mouseMoveEvent(QMouseEvent *e)
{
    QWidget::mouseMoveEvent(e);

    //постоянное получение позиции мыши
    QPoint y = e->globalPos();
    //постоянное получение позиции окна
    QPoint x = y - this->z;
    this->move(x);
}

void Server::mousePressEvent(QMouseEvent *e)
{
    QWidget::mousePressEvent(e);
    QPoint y = e->globalPos(); //положение мыши относительно верхнего левого угла рабочего стола

    QPoint x = this->geometry().topLeft(); //положение окна относительно верхнего левого угла рабочего стола
    this->z = y - x;   //положение мыши относительно верхнего левого угла окна, фиксированное значение
}

void Server::mouseReleaseEvent(QMouseEvent *e)
{
    QWidget::mouseReleaseEvent(e);
    this->z = QPoint();
}

void Server::on_minBt_clicked()
{
    setWindowState(Qt::WindowMinimized);
}

void Server::on_maxBt_clicked()
{
    setWindowState(Qt::WindowMaximized);
}
