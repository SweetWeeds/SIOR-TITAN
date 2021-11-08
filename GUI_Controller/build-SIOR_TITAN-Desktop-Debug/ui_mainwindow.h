/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
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
    QPushButton *refreshButton;
    QLabel *baudrate_label;
    QSpinBox *baudrateSpinBox;
    QMenuBar *menubar;
    QMenu *menuSIOR_TITAN;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1001, 598);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        recordListView = new QListView(centralwidget);
        recordListView->setObjectName(QStringLiteral("recordListView"));
        recordListView->setGeometry(QRect(20, 10, 211, 351));
        positionListView = new QListView(centralwidget);
        positionListView->setObjectName(QStringLiteral("positionListView"));
        positionListView->setGeometry(QRect(250, 10, 431, 351));
        recordButton = new QPushButton(centralwidget);
        recordButton->setObjectName(QStringLiteral("recordButton"));
        recordButton->setGeometry(QRect(20, 370, 211, 181));
        QFont font;
        font.setFamily(QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225"));
        font.setPointSize(17);
        font.setBold(false);
        font.setWeight(50);
        recordButton->setFont(font);
        singleExecuteButton = new QPushButton(centralwidget);
        singleExecuteButton->setObjectName(QStringLiteral("singleExecuteButton"));
        singleExecuteButton->setGeometry(QRect(250, 370, 211, 91));
        singleExecuteButton->setFont(font);
        captureButton = new QPushButton(centralwidget);
        captureButton->setObjectName(QStringLiteral("captureButton"));
        captureButton->setGeometry(QRect(470, 370, 211, 91));
        captureButton->setFont(font);
        continuousExecuteButton = new QPushButton(centralwidget);
        continuousExecuteButton->setObjectName(QStringLiteral("continuousExecuteButton"));
        continuousExecuteButton->setGeometry(QRect(250, 470, 431, 81));
        continuousExecuteButton->setFont(font);
        humanoid_pic = new QLabel(centralwidget);
        humanoid_pic->setObjectName(QStringLiteral("humanoid_pic"));
        humanoid_pic->setGeometry(QRect(710, 10, 281, 331));
        serialConnectButton = new QPushButton(centralwidget);
        serialConnectButton->setObjectName(QStringLiteral("serialConnectButton"));
        serialConnectButton->setGeometry(QRect(700, 410, 291, 141));
        serialConnectButton->setFont(font);
        serialComboBox = new QComboBox(centralwidget);
        serialComboBox->setObjectName(QStringLiteral("serialComboBox"));
        serialComboBox->setGeometry(QRect(780, 380, 141, 21));
        serial_label = new QLabel(centralwidget);
        serial_label->setObjectName(QStringLiteral("serial_label"));
        serial_label->setGeometry(QRect(700, 380, 81, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225"));
        font1.setBold(false);
        font1.setWeight(50);
        serial_label->setFont(font1);
        refreshButton = new QPushButton(centralwidget);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));
        refreshButton->setGeometry(QRect(930, 350, 61, 51));
        baudrate_label = new QLabel(centralwidget);
        baudrate_label->setObjectName(QStringLiteral("baudrate_label"));
        baudrate_label->setGeometry(QRect(700, 350, 81, 16));
        baudrate_label->setFont(font1);
        baudrateSpinBox = new QSpinBox(centralwidget);
        baudrateSpinBox->setObjectName(QStringLiteral("baudrateSpinBox"));
        baudrateSpinBox->setGeometry(QRect(780, 350, 141, 26));
        baudrateSpinBox->setMinimum(9200);
        baudrateSpinBox->setMaximum(3000000);
        baudrateSpinBox->setSingleStep(1000);
        baudrateSpinBox->setValue(1500000);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1001, 22));
        menuSIOR_TITAN = new QMenu(menubar);
        menuSIOR_TITAN->setObjectName(QStringLiteral("menuSIOR_TITAN"));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSIOR_TITAN->menuAction());
        menubar->addAction(menu->menuAction());
        menuSIOR_TITAN->addAction(actionLoad);
        menuSIOR_TITAN->addAction(actionSave);
        menu->addAction(actionInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SIOR-TITAN", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionInfo->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        recordButton->setText(QApplication::translate("MainWindow", "Recording Mode", Q_NULLPTR));
        singleExecuteButton->setText(QApplication::translate("MainWindow", "Single Execute", Q_NULLPTR));
        captureButton->setText(QApplication::translate("MainWindow", "Capture", Q_NULLPTR));
        continuousExecuteButton->setText(QApplication::translate("MainWindow", "Batch Execute", Q_NULLPTR));
        humanoid_pic->setText(QString());
        serialConnectButton->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        serial_label->setText(QApplication::translate("MainWindow", "Serial Dev", Q_NULLPTR));
        refreshButton->setText(QApplication::translate("MainWindow", "Refresh", Q_NULLPTR));
        baudrate_label->setText(QApplication::translate("MainWindow", "Baudrate", Q_NULLPTR));
        menuSIOR_TITAN->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "Info", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
