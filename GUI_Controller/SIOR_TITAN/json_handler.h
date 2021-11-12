#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#define MOTOR_NUM 18

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

class JSON_Handler {
public:
    JSON_Handler();
    ~JSON_Handler();
    void Open(QString fileName);
    void Save(QString fileName);
    QStringList ReadGroupList();
    QJsonObject ReadGroup(QString groupName);
    void LoadGroup(QString groupName);
    void AddGroup(QString groupName);
    void DeleteGroup(QString groupName);
    void AddGesture(QString gestureName, QString SamId, QString Value);
    void DeleteGesture(QString gestureName);
    QStringList ReadGestureList(QString groupName);
    QJsonObject ReadGesture(QString gestureName);
    void ModifyGesture(QString gestureName, int value[], int num);
    void AddGestures(QString gestureNames[], QString SamIds[], QString Values[], int num);
private:
    QString fileName;
    QFile   file;
    QJsonDocument doc;
    QString currentGroup;
};

#endif // JSON_HANDLER_H
