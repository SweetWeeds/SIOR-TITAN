/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionInfo;
    QAction *actionSave_As;
    QWidget *centralwidget;
    QListView *groupListView;
    QListView *gestureListView;
    QPushButton *recordButton;
    QPushButton *singleExecuteButton;
    QPushButton *captureButton;
    QPushButton *batchExecuteButton;
    QLabel *humanoid_pic;
    QPushButton *serialConnectButton;
    QComboBox *serialComboBox;
    QLabel *serial_label;
    QPushButton *refreshButton;
    QLabel *baudrate_label;
    QSpinBox *baudrateSpinBox;
    QPushButton *testButton;
    QSpinBox *testSpinBox;
    QPushButton *deleteGestureButton;
    QPushButton *addGestureButton;
    QPushButton *addGroupButton;
    QPushButton *deleteGroupButton;
    QMenuBar *menubar;
    QMenu *menuSIOR_TITAN;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1001, 676);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupListView = new QListView(centralwidget);
        groupListView->setObjectName(QString::fromUtf8("groupListView"));
        groupListView->setGeometry(QRect(20, 10, 211, 351));
        gestureListView = new QListView(centralwidget);
        gestureListView->setObjectName(QString::fromUtf8("gestureListView"));
        gestureListView->setGeometry(QRect(250, 10, 431, 351));
        recordButton = new QPushButton(centralwidget);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        recordButton->setGeometry(QRect(20, 450, 211, 181));
        QFont font;
        font.setFamily(QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225"));
        font.setPointSize(17);
        font.setBold(false);
        font.setWeight(50);
        recordButton->setFont(font);
        singleExecuteButton = new QPushButton(centralwidget);
        singleExecuteButton->setObjectName(QString::fromUtf8("singleExecuteButton"));
        singleExecuteButton->setGeometry(QRect(250, 450, 211, 91));
        singleExecuteButton->setFont(font);
        captureButton = new QPushButton(centralwidget);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        captureButton->setGeometry(QRect(470, 450, 211, 91));
        captureButton->setFont(font);
        batchExecuteButton = new QPushButton(centralwidget);
        batchExecuteButton->setObjectName(QString::fromUtf8("batchExecuteButton"));
        batchExecuteButton->setGeometry(QRect(250, 550, 431, 81));
        batchExecuteButton->setFont(font);
        humanoid_pic = new QLabel(centralwidget);
        humanoid_pic->setObjectName(QString::fromUtf8("humanoid_pic"));
        humanoid_pic->setGeometry(QRect(690, 10, 291, 431));
        serialConnectButton = new QPushButton(centralwidget);
        serialConnectButton->setObjectName(QString::fromUtf8("serialConnectButton"));
        serialConnectButton->setGeometry(QRect(690, 550, 291, 81));
        serialConnectButton->setFont(font);
        serialComboBox = new QComboBox(centralwidget);
        serialComboBox->setObjectName(QString::fromUtf8("serialComboBox"));
        serialComboBox->setGeometry(QRect(770, 520, 141, 21));
        serial_label = new QLabel(centralwidget);
        serial_label->setObjectName(QString::fromUtf8("serial_label"));
        serial_label->setGeometry(QRect(690, 520, 81, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225"));
        font1.setBold(false);
        font1.setWeight(50);
        serial_label->setFont(font1);
        refreshButton = new QPushButton(centralwidget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setGeometry(QRect(920, 490, 61, 51));
        baudrate_label = new QLabel(centralwidget);
        baudrate_label->setObjectName(QString::fromUtf8("baudrate_label"));
        baudrate_label->setGeometry(QRect(690, 490, 81, 16));
        baudrate_label->setFont(font1);
        baudrateSpinBox = new QSpinBox(centralwidget);
        baudrateSpinBox->setObjectName(QString::fromUtf8("baudrateSpinBox"));
        baudrateSpinBox->setGeometry(QRect(770, 490, 141, 26));
        baudrateSpinBox->setMinimum(9200);
        baudrateSpinBox->setMaximum(3000000);
        baudrateSpinBox->setSingleStep(1000);
        baudrateSpinBox->setValue(1500000);
        testButton = new QPushButton(centralwidget);
        testButton->setObjectName(QString::fromUtf8("testButton"));
        testButton->setGeometry(QRect(918, 450, 61, 25));
        testSpinBox = new QSpinBox(centralwidget);
        testSpinBox->setObjectName(QString::fromUtf8("testSpinBox"));
        testSpinBox->setGeometry(QRect(690, 450, 221, 26));
        testSpinBox->setMinimum(0);
        testSpinBox->setMaximum(4095);
        testSpinBox->setSingleStep(1000);
        testSpinBox->setValue(100);
        deleteGestureButton = new QPushButton(centralwidget);
        deleteGestureButton->setObjectName(QString::fromUtf8("deleteGestureButton"));
        deleteGestureButton->setGeometry(QRect(470, 370, 211, 71));
        deleteGestureButton->setFont(font);
        addGestureButton = new QPushButton(centralwidget);
        addGestureButton->setObjectName(QString::fromUtf8("addGestureButton"));
        addGestureButton->setGeometry(QRect(250, 370, 211, 71));
        addGestureButton->setFont(font);
        addGroupButton = new QPushButton(centralwidget);
        addGroupButton->setObjectName(QString::fromUtf8("addGroupButton"));
        addGroupButton->setGeometry(QRect(20, 370, 101, 71));
        addGroupButton->setFont(font);
        deleteGroupButton = new QPushButton(centralwidget);
        deleteGroupButton->setObjectName(QString::fromUtf8("deleteGroupButton"));
        deleteGroupButton->setGeometry(QRect(130, 370, 101, 71));
        deleteGroupButton->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1001, 20));
        menuSIOR_TITAN = new QMenu(menubar);
        menuSIOR_TITAN->setObjectName(QString::fromUtf8("menuSIOR_TITAN"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSIOR_TITAN->menuAction());
        menubar->addAction(menu->menuAction());
        menuSIOR_TITAN->addAction(actionLoad);
        menuSIOR_TITAN->addAction(actionSave);
        menuSIOR_TITAN->addAction(actionSave_As);
        menu->addAction(actionInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SIOR-TITAN", nullptr));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionInfo->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", nullptr));
        recordButton->setText(QApplication::translate("MainWindow", "Recording Mode", nullptr));
        singleExecuteButton->setText(QApplication::translate("MainWindow", "Single Execute", nullptr));
        captureButton->setText(QApplication::translate("MainWindow", "Capture Gesture", nullptr));
        batchExecuteButton->setText(QApplication::translate("MainWindow", "Batch Execute", nullptr));
        humanoid_pic->setText(QString());
        serialConnectButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        serial_label->setText(QApplication::translate("MainWindow", "Serial Dev", nullptr));
        refreshButton->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        baudrate_label->setText(QApplication::translate("MainWindow", "Baudrate", nullptr));
        testButton->setText(QApplication::translate("MainWindow", "TEST", nullptr));
        deleteGestureButton->setText(QApplication::translate("MainWindow", "Delete Gesture", nullptr));
        addGestureButton->setText(QApplication::translate("MainWindow", "Add Gesture", nullptr));
        addGroupButton->setText(QApplication::translate("MainWindow", "Add\n"
"Group", nullptr));
        deleteGroupButton->setText(QApplication::translate("MainWindow", "Delete\n"
"Group", nullptr));
        menuSIOR_TITAN->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
