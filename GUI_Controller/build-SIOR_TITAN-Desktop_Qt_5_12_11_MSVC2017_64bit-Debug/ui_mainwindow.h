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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QAction *actionSave;
    QAction *actionInfo;
    QWidget *centralwidget;
    QListView *recordListView;
    QListView *positionListView;
    QPushButton *recordButton;
    QPushButton *singleExecuteButton;
    QPushButton *captureButton;
    QPushButton *continuousExecuteButton;
    QLabel *humanoid_pic;
    QPushButton *serialConnectButton;
    QComboBox *serialComboBox;
    QLabel *serial_label;
    QMenuBar *menubar;
    QMenu *menuSIOR_TITAN;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(922, 610);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QString::fromUtf8("actionFile"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        recordListView = new QListView(centralwidget);
        recordListView->setObjectName(QString::fromUtf8("recordListView"));
        recordListView->setGeometry(QRect(20, 10, 211, 351));
        positionListView = new QListView(centralwidget);
        positionListView->setObjectName(QString::fromUtf8("positionListView"));
        positionListView->setGeometry(QRect(250, 10, 431, 351));
        recordButton = new QPushButton(centralwidget);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        recordButton->setGeometry(QRect(20, 370, 211, 181));
        QFont font;
        font.setFamily(QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225"));
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        recordButton->setFont(font);
        singleExecuteButton = new QPushButton(centralwidget);
        singleExecuteButton->setObjectName(QString::fromUtf8("singleExecuteButton"));
        singleExecuteButton->setGeometry(QRect(250, 370, 211, 91));
        singleExecuteButton->setFont(font);
        captureButton = new QPushButton(centralwidget);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        captureButton->setGeometry(QRect(470, 370, 211, 91));
        captureButton->setFont(font);
        continuousExecuteButton = new QPushButton(centralwidget);
        continuousExecuteButton->setObjectName(QString::fromUtf8("continuousExecuteButton"));
        continuousExecuteButton->setGeometry(QRect(250, 470, 431, 81));
        continuousExecuteButton->setFont(font);
        humanoid_pic = new QLabel(centralwidget);
        humanoid_pic->setObjectName(QString::fromUtf8("humanoid_pic"));
        humanoid_pic->setGeometry(QRect(690, 10, 211, 351));
        serialConnectButton = new QPushButton(centralwidget);
        serialConnectButton->setObjectName(QString::fromUtf8("serialConnectButton"));
        serialConnectButton->setGeometry(QRect(690, 410, 211, 141));
        serialConnectButton->setFont(font);
        serialComboBox = new QComboBox(centralwidget);
        serialComboBox->setObjectName(QString::fromUtf8("serialComboBox"));
        serialComboBox->setGeometry(QRect(760, 380, 141, 21));
        serial_label = new QLabel(centralwidget);
        serial_label->setObjectName(QString::fromUtf8("serial_label"));
        serial_label->setGeometry(QRect(690, 380, 61, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225"));
        font1.setBold(true);
        font1.setWeight(75);
        serial_label->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 922, 20));
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
        menuSIOR_TITAN->addAction(actionFile);
        menuSIOR_TITAN->addAction(actionSave);
        menu->addAction(actionInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionFile->setText(QApplication::translate("MainWindow", "Load", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionInfo->setText(QApplication::translate("MainWindow", "About", nullptr));
        recordButton->setText(QApplication::translate("MainWindow", "\353\205\271\355\231\224 \353\252\250\353\223\234", nullptr));
        singleExecuteButton->setText(QApplication::translate("MainWindow", "\353\213\250\354\235\274 \354\213\244\355\226\211", nullptr));
        captureButton->setText(QApplication::translate("MainWindow", "\354\272\241\354\262\230", nullptr));
        continuousExecuteButton->setText(QApplication::translate("MainWindow", "\354\227\260\354\206\215 \354\213\244\355\226\211", nullptr));
        humanoid_pic->setText(QString());
        serialConnectButton->setText(QApplication::translate("MainWindow", "\354\227\260\352\262\260", nullptr));
        serial_label->setText(QApplication::translate("MainWindow", "Serial Dev", nullptr));
        menuSIOR_TITAN->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
