#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
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

private:
    Ui::MainWindow *ui;
    void fillPortsInfo();
    MyMotor mymotor;
    bool isConnected = false;
    bool isRecording = false;
    void refreshSerialPortList();
};

#endif // MAINWINDOW_H
