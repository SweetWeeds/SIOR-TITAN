#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QFile>
#include <QFileDialog>

#include <QDebug>
#include <QDateTime>

#include <QStringList>
#include <QStringListModel>

#include "sam160.h"
#include "json_handler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void About();
    void Load();
    void Save();
    void on_serialConnectButton_clicked();
    void on_recordButton_clicked();
    void on_refreshButton_clicked();
    void on_testButton_clicked();

    void on_groupListView_clicked(const QModelIndex &index);

private:
    /** Variables **/
    Ui::MainWindow *ui;
    MyMotor mymotor;
    JSON_Handler json_handler;
    bool isConnected = false;
    bool isRecording = false;

    /** Functions **/
    void fillPortsInfo();
    void refreshSerialPortList();
    void setEnableControlButtons(bool en);
    int  setRecordMode(bool enRecord=true);
    int  setSerialConnect(bool enSerial=true);
};

#endif // MAINWINDOW_H
