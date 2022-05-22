#ifndef MYTHREAD_H
#define MYTHREAD_H

#include "libs.h"

class MyThread:public QThread
{
    Q_OBJECT

public:
    explicit MyThread(QTcpSocket* socket,QObject *parent = nullptr);
    void shotScreenSlot();
    ~MyThread();
protected:
    void run();

private:
   QTcpSocket* msocket;
   QPixmap pixmap;
};

#endif // MYTHREAD_H
