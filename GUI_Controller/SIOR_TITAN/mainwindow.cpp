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
    ui->batchExecuteButton->setEnabled(false);
    ui->recordButton->setEnabled(false);
    ui->singleExecuteButton->setEnabled(false);
    // Status Bar
    ui->statusbar->showMessage("Welcome to SIOR-TITAN Controller");
}


MainWindow::~MainWindow() {
    delete ui;
}

/**** Start of Slot Functions ****/
// Print information of program
void MainWindow::About() {
    QMessageBox msgBox;
    msgBox.setText("Made by SweetWeeds");
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


// Clicked Serial Connect Button
void MainWindow::on_serialConnectButton_clicked() {
    if (this->setSerialConnect(!this->isConnected)) {
        QMessageBox msgBox;
        msgBox.setText("Serial Connection Failed.");
    }

    if (this->isConnected)  setRecordMode(true);
    else                    this->setEnableControlButtons(false);
}


// Clicked Record Button
void MainWindow::on_recordButton_clicked() {
    if (this->setRecordMode(!this->isRecording)) {
        QMessageBox msgBox;
        msgBox.setText("Mode change failed.");
    }
}


// Clicked Serial Refresh Button
void MainWindow::on_refreshButton_clicked() {
    this->refreshSerialPortList();
}


// Clicked Test Button
void MainWindow::on_testButton_clicked() {
    QMessageBox msgBox;
    u8 result = 0;
    u16 pos = (u16)ui->testSpinBox->value();
    u16 tmp = this->mymotor.Quick_PosControl_CMD((u8)0x00, 4, pos);
    tmp = this->mymotor.Quick_StatusRead_CMD((u8)0x00);
    result = (u8)(tmp & 0x00FF);
    msgBox.setText(QString("Value:%1").arg(result));
    msgBox.exec();
}
/**** End of Slot Functions ****/


/**** Start of user functions ****/
// Refresh Serial Ports
void MainWindow::refreshSerialPortList() {
    // Get serial port information
    ui->serialComboBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        ui->serialComboBox->addItem(info.portName());
    }
}


// Try to connect serial device.
int MainWindow::setSerialConnect(bool enSerial) {
    if (enSerial)
        this->mymotor.Disconnect();
    else
        this->mymotor.Connect(ui->serialComboBox->currentText(), ui->baudrateSpinBox->value());

    ui->serialConnectButton->setText(enSerial ? "Disconnect" : "Connect");

    ui->recordButton->setEnabled(enSerial);
    ui->refreshButton->setEnabled(!enSerial);
    ui->baudrateSpinBox->setEnabled(!enSerial);
    ui->serialComboBox->setEnabled(!enSerial);

    ui->statusbar->showMessage(enSerial ? "Disconnect Complete" : QString("Connected to %1:%2").arg(ui->serialComboBox->currentText(), ui->baudrateSpinBox->value()));

    if (!enSerial) this->setEnableControlButtons(false);

    this->isConnected = enSerial;

    return 0;
}

// Enable/Disable Control Buttons
void MainWindow::setEnableControlButtons(bool en) {
    ui->recordButton->setEnabled(en);
    ui->captureButton->setEnabled(en);
    ui->singleExecuteButton->setEnabled(en);
    ui->batchExecuteButton->setEnabled(en);
}

// Set Record Mode
int MainWindow::setRecordMode(bool enRecord) {
    // Activate recording mode
    ui->recordButton->setText(enRecord ? "Recording Mode" : "Executing Mode");
    ui->captureButton->setEnabled(enRecord);
    ui->singleExecuteButton->setEnabled(!enRecord);
    ui->batchExecuteButton->setEnabled(!enRecord);
    this->isRecording = enRecord;

    return 0;
}
/**** End of user functions ****/

