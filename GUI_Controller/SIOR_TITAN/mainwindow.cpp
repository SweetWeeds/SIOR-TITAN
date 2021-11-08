#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sam160.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Init window
    this->refreshSerialPortList();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::refreshSerialPortList() {
    // Get serial port information
    ui->serialComboBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        ui->serialComboBox->addItem(info.portName());
    }
}

void MainWindow::on_serialConnectButton_clicked() {
    int ret = 0;
    if (this->isConnected == true) {
        // Try disconnect
        this->mymotor.Disconnect();
        ui->serialConnectButton->setText("Connect");
    } else {
        // Try connect
        ret = this->mymotor.Connect(ui->serialComboBox->currentText(), ui->baudrateSpinBox->value());
        if (ret == -1) {
            QMessageBox msgBox;
            msgBox.setText("[ERROR] Can't connect serial port.");
            msgBox.exec();
            return;
        }
        ui->serialConnectButton->setText("Disconnect");
    }
    this->isConnected = !this->isConnected;
}


void MainWindow::on_recordButton_clicked() {
    if (this->isRecording == true) {
        // Try disconnect
        ui->serialConnectButton->setText("Recording Mode");
    } else {
        // Try connect
        ui->serialConnectButton->setText("Execution Mode");
    }
    this->isRecording = !this->isRecording;
}


void MainWindow::on_pushButton_clicked()
{
    this->refreshSerialPortList();
}

