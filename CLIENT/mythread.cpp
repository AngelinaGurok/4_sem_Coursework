#include "mythread.h"
#include "menu.h"


MyThread::MyThread(QObject *parent):QThread (parent)
{
    //отправление данные
    datasize=0;
    //соединение с сервером
   msocket.connectToHost(QHostAddress(Menu::ip),
                           Menu::port.toUShort());
//   msocket.connectToHost(QHostAddress("192.168.43.93"),8080);
//    сигнал и слот подключения
    connect(&msocket, SIGNAL(readyRead()), this, SLOT(ReadMessage()));
}

void MyThread::run()
{
    QThread::run();
}

void MyThread::ReadMessage()
{
    fetchPicturesSlot();
}

void MyThread::fetchPicturesSlot()
{
    //читаем размер скриншота
    if(datasize == 0)
    {
        QDataStream in(&msocket);
        in.setVersion( QDataStream::Qt_4_6);
        if(msocket.bytesAvailable() < sizeof(quint32))
        {
            return;
        }
        in>>datasize;
    }
    //затем получение изображение фромата JPG в соответствии с информацией о размере изображения
    if(datasize > msocket.bytesAvailable())
    {
        return;
    }
    //показать изображение
    QByteArray Data =msocket.read(datasize);

    QBuffer buffer(&Data);

    buffer.open(QIODevice::ReadOnly);
    QImageReader reader(&buffer,"jpg");
    QImage img = reader.read();
    if(!img.isNull())
    {
//        отправить сигнал отображения картинки(изображения)
        emit showImag(img);
    }
    datasize = 0;
 }
