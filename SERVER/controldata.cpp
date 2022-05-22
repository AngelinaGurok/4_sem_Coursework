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
    //строим документ JSON
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    return byteArray;
}
