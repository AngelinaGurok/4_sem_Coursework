#include "menu.h"
#include "ui_menu.h"
#include "controldata.h"

QString Menu::ip=nullptr;
QString Menu::port=nullptr;

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    //связываем upd с портом, чтобы отправлять сообщения
    port = ui->portEdit->text();
    udpsocket.bind(port.toInt());

    flag = false;

    //сигнал чтения данных
    connect(&udpsocket, &QUdpSocket::readyRead, this, &Menu::rcevMsg);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    sendMsg();
}

void Menu::sendMsg()
{
    QDateTime time = QDateTime::currentDateTime();              //получить текущее время системы
    QString str = time.toString("hh:mm:ss");                    //задать фортмат отображения

    QString msg = str+":client<"+this->ui->msgEdit->text()+">"; //формат отправляемой строки
    ui->rcvBrowser->append(msg);
    qDebug()<<"Msg"<<msg;
    QByteArray msgArr = ControlData::msgData(msg,SEND_MSG);

    w->th->msocket.write(msgArr);
}

void Menu::rcevMsg()
{
    //получить данные udp
    QByteArray baRecv;
    while(udpsocket.hasPendingDatagrams())
    {
        baRecv.resize(udpsocket.pendingDatagramSize());
        udpsocket.readDatagram(baRecv.data(),baRecv.size());
        QString strRecvData = baRecv;
        ui->rcvBrowser->append(strRecvData);
    }
}

void Menu::on_DesktopBt_clicked()
{
    ip = ui->ipEdit->text();
    port = ui->portEdit->text();
    if(!flag)
    {
        //создаем отображаемый интерфейс
        w = new Client(this);
        flag=true;
    }

    //интерфейс для удаленного контроля
    w->show();
    //скрыть основной интерфейс
    this->hide();
    qDebug("Connected.\n");
}

QJsonObject Menu::JsonParse(QByteArray array)
{
    //парсинг Json
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(array, &error);
    if(error.error != QJsonParseError::NoError)//проверка на правильность формата
    {
        qDebug()<<"json error";
    }
    QJsonObject obj = doc.object();
    return obj;
}

void Menu::on_actionback_triggered()
{
    this->close();
}
