#include "controldata.h"

ControlData::ControlData()
{

}
QByteArray ControlData::msgData(QString msg,int event)
{
    QJsonObject json;

    //координаты щелчка мыши SEND_MSG
    json.insert("event", event);
    json.insert("Msg", msg);

    //собрать документ JSON
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    return byteArray;
}
QByteArray ControlData::controlData(QDesktopWidget *d, double x, double y,int event)
{
    QJsonObject json;

    //координаты щелчка мыши
    json.insert("PointX", x);
    json.insert("PointY", y);

    //события мыши
    json.insert("event",event);

    //собрать документ JSON
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    return byteArray;
}
