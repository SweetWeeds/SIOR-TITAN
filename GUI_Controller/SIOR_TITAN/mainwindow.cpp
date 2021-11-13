#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    msgBox.setText("Made by Hankyul Kwon");
    msgBox.exec();
}


// Load json file
void MainWindow::Load() {
    // Load json file from file Dialog
    QString file = QFileDialog::getOpenFileName(this, "Select File", "", "Files(*.json)");
    json_handler.Open(file);

    QStringList groupList = json_handler.ReadGroupList();   // Read Group Key List
    qDebug() << groupList[0];
    QStringList gestureList = json_handler.ReadGestureList(groupList[0]);
    qDebug() << gestureList;

    // Update Group List View
    this->updateGroupListView(groupList);

    // Update Gesture List View
    this->updateGestureListView(gestureList);

    //    ui->gestureListView->;
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


// Clicked Group List View
void MainWindow::on_groupListView_clicked(const QModelIndex &index) {
    qDebug() << "index: " << index.data().toString();
    this->currentGroup = index.data().toString();
    QStringList gestureList = this->json_handler.ReadGestureList(this->currentGroup);
    this->updateGestureListView(gestureList);
}

// Add Group
void MainWindow::on_addGroupButton_clicked() {
    QStringList groupList = this->json_handler.ReadGroupList();
    QString newGroupName = QString("NewGroup %1").arg(groupList.size());
    this->json_handler.AddGroup(newGroupName);
    //QStringList gestureList = this->json_handler.ReadGroupList();
    this->updateGroupListView(this->json_handler.ReadGroupList());
}

// Delete Group
void MainWindow::on_deleteGroupButton_clicked() {
    QModelIndex index = ui->groupListView->currentIndex();
    this->json_handler.DeleteGroup(index.data().toString());
    this->updateGroupListView(this->json_handler.ReadGroupList());
}

// Add Gesture
void MainWindow::on_addGestureButton_clicked() {
    QStringList gestureList = this->json_handler.ReadGestureList(this->currentGroup);
    QString newGestureName = QString("NewGesture %1").arg(gestureList.size());
    this->json_handler.AddGesture(this->currentGroup, newGestureName);
    //QStringList gestureList = this->json_handler.ReadGroupList();
    this->updateGestureListView(this->json_handler.ReadGestureList(this->currentGroup));
    qDebug() << "update gesture list: " << this->json_handler.ReadGestureList(this->currentGroup);
}

// Delete Gesture
void MainWindow::on_deleteGestureButton_clicked() {
    QModelIndex index = ui->gestureListView->currentIndex();
    this->json_handler.DeleteGesture(this->currentGroup, index.data().toString());
    this->updateGestureListView(this->json_handler.ReadGestureList(this->currentGroup));
}

// Single Execution
void MainWindow::on_singleExecuteButton_clicked() {
    qDebug() << this->json_handler.ReadGesture(currentGroup, currentGesture);
    // Execute
}

// Capture
void MainWindow::on_captureButton_clicked() {

}

// Batch Execution
void MainWindow::on_batchExecuteButton_clicked() {

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

void MainWindow::updateGroupListView(QStringList groupList) {
    if (this->group_model != nullptr) delete this->group_model;
    this->group_model = new QStringListModel(groupList);
    this->group_model->sort(0);
    ui->groupListView->setModel(this->group_model);
    ui->groupListView->update();
}

void MainWindow::updateGestureListView(QStringList gestureList) {
    if (this->gesture_model != nullptr) delete this->gesture_model;
    gesture_model = new QStringListModel(gestureList);
    gesture_model->sort(0);
    ui->gestureListView->setModel(gesture_model);
    ui->gestureListView->update();
}
/**** End of user functions ****/
