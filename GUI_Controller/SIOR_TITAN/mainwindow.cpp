#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sam160.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Init window
    this->refreshSerialPortList();
    // Connect Action Bar Signals (Menu)
    connect(ui->actionInfo, SIGNAL(triggered()), this, SLOT(About()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(Load()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(Save()));
    // Buttons
    ui->captureButton->setEnabled(false);
    ui->continuousExecuteButton->setEnabled(false);
    ui->recordButton->setEnabled(false);
    ui->singleExecuteButton->setEnabled(false);
}


MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_serialConnectButton_clicked() {
    if (this->isConnected == true) {
        // Try disconnect
        this->mymotor.Disconnect();
        ui->serialConnectButton->setText("Connect");
        ui->refreshButton->setEnabled(true);
    } else {
        // Try connect
        if (this->mymotor.Connect(ui->serialComboBox->currentText(), ui->baudrateSpinBox->value()) == -1) {
            QMessageBox msgBox;
            msgBox.setText("[ERROR] Can't connect serial port.");
            msgBox.exec();
            return;
        }
        ui->serialConnectButton->setText("Disconnect");
        ui->refreshButton->setEnabled(false);
    }
    this->isConnected = !this->isConnected;
}


void MainWindow::on_recordButton_clicked() {
    if (this->isRecording == false) {
        // Activate recording mode
        ui->recordButton->setText("Recording Mode");
    } else {
        // Deactivate recording mode (activate execution mode)
        ui->recordButton->setText("Execution Mode");
    }
    this->isRecording = !this->isRecording;
}


void MainWindow::on_refreshButton_clicked() {
    this->refreshSerialPortList();
}


// Refresh Serial Ports
void MainWindow::refreshSerialPortList() {
    // Get serial port information
    ui->serialComboBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        ui->serialComboBox->addItem(info.portName());
    }
}


// Print information of program
void MainWindow::About() {
    QMessageBox msgBox;
    msgBox.setText("This program is made by Hankyul Kwon(SIOR, 2016) in 2021.");
    msgBox.exec();
}


// Load json file
void MainWindow::Load() {
    QString file = QFileDialog::getOpenFileName(this, "Select File", "", "Files(*.json)");
    qDebug() << file;
}


// Save json file
void MainWindow::Save() {
    QString filename = QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd_HH:mm:ss");
    QString file = QFileDialog::getSaveFileName(this, "Save File", filename+".json", "Files(*.json)");
    qDebug() << file;
}
