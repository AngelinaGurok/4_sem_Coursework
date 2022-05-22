#ifndef CONTROLDATA_H
#define CONTROLDATA_H

#include "libs.h"

#define MOUSE_MOVE_TO          1
#define MOUSE_LEFT             2
#define MOUSE_RIGHT            3
#define MOUSE_WHEEL            4
#define MOUSE_DOUBLE_CLICK     5
#define SEND_MSG               6
#define RCEV_MSG               7

class ControlData
{
public:
    ControlData();
    //упакованные данные
    static QByteArray controlData(QDesktopWidget *d, double x, double y, int event);

    static QByteArray msgData(QString msg,int event);
};

#endif // CONTROLDATA_H
