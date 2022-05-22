#include "mythread.h"

MyThread::MyThread(QTcpSocket* socket,QObject *parent):QThread (parent)
{
    msocket = socket;
}

void MyThread:: run()
{
    qDebug()<<"run"<<endl;
    while (1) {
        shotScreenSlot();
        msleep(200);    //5 FPS
                        //больше ставить не рекомендуется, потому что пакеты, которые передаются через
                        //TCP сокет, не успевают приходить и обрабатываться за это время
                        //соответственно, пакеты будут скапливаться
    }
}

void MyThread::shotScreenSlot()
{
    //скриншот
    this->pixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
    //преобразовать изображение в поток байтов
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);

    this->pixmap.save(&buffer,"jpg");

    quint32 pix_len = (quint32)buffer.data().size();
    qDebug("image size:%d",pix_len);

    QByteArray dataArray;
    //Связывающий поток данных
    QDataStream out(&dataArray,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_6);
    out<<pix_len;
    dataArray.append(buffer.data());

    //отправить dataArra
    msocket->write(dataArray);
    msocket->flush();

    dataArray.resize(0);
    buffer.reset();
}

MyThread::~MyThread()
{
    msocket->close();
    delete msocket;
}
