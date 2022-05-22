#ifndef SERVER_H
#define SERVER_H

#define DEBUG

#include "libs.h"
#include "mythread.h"

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

    QJsonObject JsonParse(QByteArray array);
    void selecEvent();

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void showPicture(QImage img);
private slots:
    void on_connBt_clicked();
    void on_stopBt_clicked();
    void new_client();
    void reciveData();
    void on_closeBt_clicked();
    void on_sendmsgBt_clicked();
    void rcvFile();
    void on_minBt_clicked();
    void on_maxBt_clicked();

private:
    Ui::Server *ui;
    MyThread *th;
    QTcpServer mserver;
    QTcpSocket *msocket;
    QUdpSocket *udpsocket;
    QByteArray eventArr;
    QHostAddress ip;
    int pc_x;
    int pc_y;
    QPoint z;
    QByteArray picBuffer;
    int datasize;
};

#endif // SERVER_H
