#include "json_handler.h"
#include <QDebug>

JSON_Handler::JSON_Handler() {

}

JSON_Handler::~JSON_Handler() {

}

void JSON_Handler::Open(QString fileName) {
    this->file.setFileName(fileName);
    if (!this->file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open json file to load.");
        return;
    }
    QJsonDocument doc = QJsonDocument::fromJson(this->file.readAll());
    this->root_obj = doc.object();
}

void JSON_Handler::Save(QString fileName) {
    QFile saveFile(fileName);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Could not open json file to save.");
        return;
    }
    QJsonDocument saveDoc(this->root_obj);
    saveFile.write(saveDoc.toJson());
}

QStringList JSON_Handler::ReadGroupList() {
    return this->root_obj.keys();
}

QJsonObject JSON_Handler::ReadGroup(QString groupName) {
    QJsonObject ret = this->root_obj[groupName].toObject();
    qDebug() << "Read Group[" << groupName << "]" << ret;
    return ret;
}

void JSON_Handler::AddGroup(QString groupName) {
    this->root_obj.insert(groupName, QJsonObject());
    //this->root_obj[groupName] = "null";
    qDebug() << "Add Group[" << groupName << "]" << this->root_obj.keys();
}

void JSON_Handler::DeleteGroup(QString groupName) {
    this->root_obj.remove(groupName);
    qDebug() << "Delete Group[" << groupName << "]" << this->root_obj.keys();
}

void JSON_Handler::AddGesture(QString groupName, QString gestureName) {
    QJsonArray arr;
    for (int i = 0; i < MOTOR_NUM; i++) {
        arr.append(0);
    }
    QJsonObject obj = this->root_obj[groupName].toObject();
    obj.insert(gestureName, arr);
    this->root_obj[groupName] = obj;
}

void JSON_Handler::DeleteGesture(QString groupName, QString gestureName) {
    QJsonObject obj = this->root_obj[groupName].toObject();
    obj.remove(gestureName);
    this->root_obj[groupName] = obj;
}

QStringList JSON_Handler::ReadGestureList(QString groupName) {
    return this->root_obj[groupName].toObject().keys();
}

//QJsonObject JSON_Handler::ReadGesture(QString groupName, QString gestureName) {
//    return this->root_obj[groupName].toObject()[gestureName].toObject();
//}

QJsonArray JSON_Handler::ReadGesture(QString groupName, QString gestureName) {
    qDebug() << "groupName:" << groupName << " gestureName:" << gestureName << this->root_obj[groupName].toObject()[gestureName];
    return this->root_obj[groupName].toObject()[gestureName].toArray();
}

void JSON_Handler::ModifyGesture(QString groupName, QString gestureName, u8 data[]) {
    QJsonArray arr;
    for (int i = 0; i <MOTOR_NUM; i++) {
        arr.append(data[i]);
    }
    QJsonObject obj = this->root_obj[groupName].toObject();
    obj.insert(gestureName, arr);
    this->root_obj.insert(groupName, obj);
}
