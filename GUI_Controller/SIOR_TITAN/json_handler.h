#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#define MOTOR_NUM 18

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

typedef unsigned char u8;

class JSON_Handler {
public:
    JSON_Handler();
    ~JSON_Handler();
    void Open(QString fileName);
    void Save(QString fileName);
    QStringList ReadGroupList();
    QJsonObject ReadGroup(QString groupName);
    void AddGroup(QString groupName);
    void DeleteGroup(QString groupName);
    void AddGesture(QString groupName, QString gestureName);
    void DeleteGesture(QString groupName, QString gestureName);
    QStringList ReadGestureList(QString groupName);
    QJsonArray  ReadGesture(QString groupName, QString gestureName);
    //void ModifyGesture(QString groupName, QString gestureName, QJsonValue data);
    void ModifyGesture(QString groupName, QString gestureName, u8 data[]);
private:
    QString fileName;
    QFile   file;
    QJsonObject     root_obj;
};

#endif // JSON_HANDLER_H
