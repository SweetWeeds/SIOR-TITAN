#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QFile>
#include <QFileDialog>

#include <QDebug>
#include <QDateTime>

#include "sam160.h"

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

private:
    /** Variables **/
    Ui::MainWindow *ui;
    MyMotor mymotor;
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
