#include "client.h"
#include "ui_client.h"
#include "controldata.h"

static bool isMove=false;

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    showFullScreen();

    //инициализация потока
    th = new MyThread();
    th->start();

    connect(th,&MyThread::showImag,this,&Client::ShowImage);
}

void Client::ShowImage(QImage img)
{
    ui->playerLabel->setScaledContents(true);
    QPixmap pix = QPixmap::fromImage(img);
    ui->playerLabel->setPixmap(pix.scaled(ui->playerLabel->size(),
                                          Qt::KeepAspectRatio,
                                       Qt::SmoothTransformation));
}

void Client::mouseMoveEvent(QMouseEvent *e)
{
    QRect screenrect;
    QDesktopWidget* desktopWidget = QApplication::desktop();//получить разрешение
    screenrect = desktopWidget->screenGeometry();

    QPoint point;
    point=e->pos();
    if( (point-curPoint).manhattanLength() != 0)//получение координатов текущей точки
    {
        isMove = true;
        //выполнить эффект перетаскивания
        double Xpercent=(double)point.x()/screenrect.width();//рассчет
        double Ypercent=(double)point.y()/screenrect.height();
        QByteArray eventArr =  ControlData::controlData(d,Xpercent,Ypercent,MOUSE_MOVE_TO);
        sendData(eventArr);
    }
}

void Client::mouseReleaseEvent(QMouseEvent *e)
{
    isMove = false;
}

void Client::mouseDoubleClickEvent(QMouseEvent *e)
{
    //событие двойного щелчка
    QRect screenrect;
    screenrect = ui->playerLabel->geometry();

    QPoint point;
    point=e->pos();//получить координаты текущего клика

    double Xpercent=(double)point.x()/screenrect.width();//рассчет
    double Ypercent=(double)point.y()/screenrect.height();
    QByteArray eventArr =  ControlData::controlData(d,Xpercent,Ypercent,MOUSE_DOUBLE_CLICK);
    sendData(eventArr);
}

//нажата левая клавиша мыши
void Client::mousePressEvent(QMouseEvent *e)
{
    curPoint = e->pos();
    if(!isMove)
    {
        QRect screenrect;
        screenrect = ui->playerLabel->geometry();

        QPoint point;
        point=e->pos();//координаты текущаго клика

        double Xpercent=(double)point.x()/screenrect.width();
        double Ypercent=(double)point.y()/screenrect.height();
        QByteArray eventArr =  ControlData::controlData(d,Xpercent,Ypercent,MOUSE_LEFT);
        sendData(eventArr);
    }
}

void Client::sendData(QByteArray eventArr)
{
    //отправить данные на tcp
    th->msocket.write(eventArr);
}

void Client::on_actionback_triggered()
{
    //вернуться на глаыный интерфейс
    this->parentWidget()->show();
    this->hide();
}

Client::~Client()
{
    delete ui;
}
