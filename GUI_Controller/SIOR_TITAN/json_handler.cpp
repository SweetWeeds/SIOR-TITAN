#include "json_handler.h"

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
    this->doc = QJsonDocument::fromJson(this->file.readAll());
}

void JSON_Handler::Save(QString fileName) {
    QFile saveFile(fileName);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Could not open json file to save.");
        return;
    }

    saveFile.write(this->doc.toJson());
}

QStringList JSON_Handler::ReadGroupList() {
    return this->doc.object().keys();
}

void JSON_Handler::LoadGroup(QString groupName) {
    this->currentGroup = groupName;
}

QJsonObject JSON_Handler::ReadGroup(QString groupName) {
    return this->doc.object()[this->currentGroup].toObject();
}

void JSON_Handler::AddGroup(QString groupName) {
    this->doc.object().insert(groupName, QJsonObject());
}

void JSON_Handler::DeleteGroup(QString groupName) {
    this->doc.object().remove(groupName);
}

void JSON_Handler::AddGesture(QString gestureName, QString SamId, QString Value) {
    this->doc.object()[this->currentGroup].toObject().constFind(SamId);
}

void JSON_Handler::AddGestures(QString gestureNames[], QString SamIds[], QString Values[], int num) {
    for (int i = 0; i < num; i++) {
        this->AddGesture(gestureNames[i], SamIds[i], Values[i]);
    }
}

void JSON_Handler::DeleteGesture(QString gestureName) {
    this->doc[this->currentGroup].toObject().remove(gestureName);
}

QStringList JSON_Handler::ReadGestureList(QString groupName) {
    return this->doc.object()[groupName].toObject().keys();
}

QJsonObject JSON_Handler::ReadGesture(QString gestureName) {
    return this->doc[this->currentGroup][gestureName].toObject();
}

void JSON_Handler::ModifyGesture(QString gestureName, int value[], int num) {
    QJsonObject obj = this->doc[this->currentGroup][gestureName].toObject();
    for (int i = 0; i < num; i++) {
        obj[QString(i)] = value[i];
    }
}
