/********************************************************************************
** Form generated from reading UI file 'mediaoption.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAOPTION_H
#define UI_MEDIAOPTION_H

#include <PushTable.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TreeView.h"

QT_BEGIN_NAMESPACE

class Ui_mediaoptionClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *Play;
    QGridLayout *gridLayout_16;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_9;
    QCheckBox *checkBox_3;
    QSpacerItem *horizontalSpacer_10;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_5;
    QLineEdit *UrllineEdit;
    QComboBox *comboBox_2;
    QGridLayout *gridLayout_2;
    TreeView *playtreeView;
    QWidget *playwidget;
    QWidget *Voplay;
    QGridLayout *gridLayout_6;
    TreeView *vodtreeView;
    QVBoxLayout *verticalLayout;
    QLabel *vodqlabel;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_35;
    QPushButton *pushButton_20;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_19;
    QSpacerItem *horizontalSpacer_34;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_21;
    QWidget *Pusher;
<<<<<<< HEAD
    QGridLayout *pushlayout;
    QHBoxLayout *pushHlayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addServer;
    QSpacerItem *horizontalSpacer_16;
    QLineEdit *lineEdit;
    QComboBox *selectserver;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *startServer;
    QSpacerItem *horizontalSpacer_15;
    PushTable *pushTableView;
    QWidget *Device;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_8;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_13;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_8;
    QLineEdit *deviceName;
    QLineEdit *lineEdit_9;
    QComboBox *deviceType;
    QLineEdit *lineEdit_14;
    QLineEdit *deviceId;
    QLineEdit *lineEdit_10;
    QLineEdit *userName;
    QLineEdit *lineEdit_11;
    QLineEdit *passWd;
    QLineEdit *lineEdit_12;
    QLineEdit *ipAddr;
    QLineEdit *lineEdit_13;
    QLineEdit *devicePort;
    QPushButton *cancelDevice;
    QPushButton *submitDevice;
    QSpacerItem *horizontalSpacer_28;
    QSpacerItem *horizontalSpacer_30;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_2;
=======
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *addServer;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addStream;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *pushAll;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *lineEdit;
    QComboBox *selectserver;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *startServer;
    QSpacerItem *horizontalSpacer_18;
    PushTable *pushTableView;
>>>>>>> dev1.0
    QWidget *Systemset;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mediaoptionClass)
    {
        if (mediaoptionClass->objectName().isEmpty())
            mediaoptionClass->setObjectName(QStringLiteral("mediaoptionClass"));
<<<<<<< HEAD
        mediaoptionClass->resize(1671, 853);
=======
        mediaoptionClass->resize(1627, 1006);
>>>>>>> dev1.0
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        mediaoptionClass->setFont(font);
        mediaoptionClass->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QStringLiteral("res/multimedia.png"), QSize(), QIcon::Normal, QIcon::Off);
        mediaoptionClass->setWindowIcon(icon);
        mediaoptionClass->setAutoFillBackground(true);
        mediaoptionClass->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(mediaoptionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        Play = new QWidget();
        Play->setObjectName(QStringLiteral("Play"));
        gridLayout_16 = new QGridLayout(Play);
        gridLayout_16->setSpacing(0);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        checkBox = new QCheckBox(Play);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        horizontalSpacer_8 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        checkBox_2 = new QCheckBox(Play);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_2->addWidget(checkBox_2);

        horizontalSpacer_9 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        checkBox_3 = new QCheckBox(Play);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_2->addWidget(checkBox_3);

        horizontalSpacer_10 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        comboBox = new QComboBox(Play);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEditable(true);

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);

        pushButton_5 = new QPushButton(Play);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_2->addWidget(pushButton_5);

        UrllineEdit = new QLineEdit(Play);
        UrllineEdit->setObjectName(QStringLiteral("UrllineEdit"));

        horizontalLayout_2->addWidget(UrllineEdit);

        comboBox_2 = new QComboBox(Play);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);

        horizontalLayout_2->setStretch(6, 1);
        horizontalLayout_2->setStretch(10, 1);

        gridLayout_16->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        playtreeView = new TreeView(Play);
        playtreeView->setObjectName(QStringLiteral("playtreeView"));
        playtreeView->setEnabled(true);

        gridLayout_2->addWidget(playtreeView, 0, 0, 1, 1);

        playwidget = new QWidget(Play);
        playwidget->setObjectName(QStringLiteral("playwidget"));
        playwidget->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(playwidget, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(1, 1);

        gridLayout_16->addLayout(gridLayout_2, 1, 0, 1, 1);

        tabWidget->addTab(Play, QString());
        Voplay = new QWidget();
        Voplay->setObjectName(QStringLiteral("Voplay"));
        gridLayout_6 = new QGridLayout(Voplay);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        vodtreeView = new TreeView(Voplay);
        vodtreeView->setObjectName(QStringLiteral("vodtreeView"));

        gridLayout_6->addWidget(vodtreeView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        vodqlabel = new QLabel(Voplay);
        vodqlabel->setObjectName(QStringLiteral("vodqlabel"));
        vodqlabel->setStyleSheet(QStringLiteral("background-color: rgb(62, 62, 62);"));
        vodqlabel->setScaledContents(false);

        verticalLayout->addWidget(vodqlabel);

        horizontalSlider_2 = new QSlider(Voplay);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"border: 1px solid #4A708B;\n"
"background: #C0C0C0;\n"
"height: 5px;\n"
"border-radius: 1px;\n"
"padding-left:-1px;\n"
"padding-right:-1px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 #5DCCFF, stop: 1 #1874CD);\n"
"border: 1px solid #4A708B;\n"
"height: 10px;\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #575757;\n"
"border: 0px solid #777;\n"
"height: 10px;\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal \n"
"{\n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, \n"
"    stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));\n"
"\n"
"    width: 11px;\n"
"    margin-top: -3px;\n"
"    margin-bottom: -3px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"    background: q"
                        "radialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA, \n"
"    stop:0.778409 rgba(255, 255, 255, 255));\n"
"\n"
"    width: 11px;\n"
"    margin-top: -3px;\n"
"    margin-bottom: -3px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #00009C;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_35 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_35);

        pushButton_20 = new QPushButton(Voplay);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setStyleSheet(QStringLiteral("QPushButton { background-color:transparent}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("res/last.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_20->setIcon(icon1);
        pushButton_20->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pushButton_20);

        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_6 = new QPushButton(Voplay);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setStyleSheet(QStringLiteral("QPushButton { background-color:transparent}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("res/player_fast_back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon2);
        pushButton_6->setIconSize(QSize(30, 25));

        horizontalLayout->addWidget(pushButton_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_7 = new QPushButton(Voplay);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setStyleSheet(QStringLiteral("QPushButton { background-color:transparent}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("res/play_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon3);
        pushButton_7->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pushButton_7);

        horizontalSpacer_4 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton_19 = new QPushButton(Voplay);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setStyleSheet(QStringLiteral("QPushButton { background-color:transparent}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("res/player_fast_font.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon4);
        pushButton_19->setIconSize(QSize(30, 25));

        horizontalLayout->addWidget(pushButton_19);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_34);

        pushButton_10 = new QPushButton(Voplay);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setStyleSheet(QStringLiteral("QPushButton { background-color:transparent}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("res/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon5);
        pushButton_10->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pushButton_10);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_8 = new QPushButton(Voplay);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setStyleSheet(QStringLiteral("QPushButton { background-color:transparent}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("res/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon6);
        pushButton_8->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pushButton_8);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        pushButton_21 = new QPushButton(Voplay);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setStyleSheet(QStringLiteral("QPushButton { background-color:transparent}"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("res/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_21->setIcon(icon7);
        pushButton_21->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pushButton_21);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 5);

        gridLayout_6->addLayout(verticalLayout, 0, 1, 1, 1);

        gridLayout_6->setColumnStretch(1, 1);
        tabWidget->addTab(Voplay, QString());
        Pusher = new QWidget();
        Pusher->setObjectName(QStringLiteral("Pusher"));
<<<<<<< HEAD
        pushlayout = new QGridLayout(Pusher);
        pushlayout->setSpacing(0);
        pushlayout->setContentsMargins(11, 11, 11, 11);
        pushlayout->setObjectName(QStringLiteral("pushlayout"));
        pushlayout->setContentsMargins(0, 0, 0, 0);
        pushHlayout = new QHBoxLayout();
        pushHlayout->setSpacing(6);
        pushHlayout->setObjectName(QStringLiteral("pushHlayout"));
        horizontalSpacer_3 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        pushHlayout->addItem(horizontalSpacer_3);

        addServer = new QPushButton(Pusher);
        addServer->setObjectName(QStringLiteral("addServer"));
        addServer->setStyleSheet(QStringLiteral(""));

        pushHlayout->addWidget(addServer);

        horizontalSpacer_16 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        pushHlayout->addItem(horizontalSpacer_16);

        lineEdit = new QLineEdit(Pusher);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);

        pushHlayout->addWidget(lineEdit);

        selectserver = new QComboBox(Pusher);
        selectserver->setObjectName(QStringLiteral("selectserver"));

        pushHlayout->addWidget(selectserver);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        pushHlayout->addItem(horizontalSpacer_11);

        startServer = new QPushButton(Pusher);
        startServer->setObjectName(QStringLiteral("startServer"));
        startServer->setStyleSheet(QStringLiteral(""));

        pushHlayout->addWidget(startServer);

        horizontalSpacer_15 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        pushHlayout->addItem(horizontalSpacer_15);

        pushHlayout->setStretch(2, 5);
        pushHlayout->setStretch(3, 1);
        pushHlayout->setStretch(4, 7);
        pushHlayout->setStretch(5, 2);
        pushHlayout->setStretch(7, 2);

        pushlayout->addLayout(pushHlayout, 0, 0, 1, 1);

        pushTableView = new PushTable(Pusher);
        pushTableView->setObjectName(QStringLiteral("pushTableView"));
        pushTableView->setSelectionMode(QAbstractItemView::NoSelection);
        pushTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        pushTableView->setShowGrid(true);

        pushlayout->addWidget(pushTableView, 1, 0, 1, 1);

        tabWidget->addTab(Pusher, QString());
        Device = new QWidget();
        Device->setObjectName(QStringLiteral("Device"));
        gridLayout_11 = new QGridLayout(Device);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        groupBox_7 = new QGroupBox(Device);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_8 = new QGridLayout(groupBox_7);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 229, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(119, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_13, 1, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
=======
        gridLayout_7 = new QGridLayout(Pusher);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
>>>>>>> dev1.0
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_17);

        addServer = new QPushButton(Pusher);
        addServer->setObjectName(QStringLiteral("addServer"));

        horizontalLayout_12->addWidget(addServer);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);

        addStream = new QPushButton(Pusher);
        addStream->setObjectName(QStringLiteral("addStream"));

        horizontalLayout_12->addWidget(addStream);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_16);

        pushAll = new QPushButton(Pusher);
        pushAll->setObjectName(QStringLiteral("pushAll"));

<<<<<<< HEAD
        gridLayout_11->addWidget(groupBox_7, 0, 0, 1, 1);

        tabWidget->addTab(Device, QString());
=======
        horizontalLayout_12->addWidget(pushAll);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_11);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        lineEdit = new QLineEdit(Pusher);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);

        horizontalLayout_11->addWidget(lineEdit);

        selectserver = new QComboBox(Pusher);
        selectserver->setObjectName(QStringLiteral("selectserver"));

        horizontalLayout_11->addWidget(selectserver);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 4);

        horizontalLayout_12->addLayout(horizontalLayout_11);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_15);

        startServer = new QPushButton(Pusher);
        startServer->setObjectName(QStringLiteral("startServer"));

        horizontalLayout_12->addWidget(startServer);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_18);

        horizontalLayout_12->setStretch(6, 1);
        horizontalLayout_12->setStretch(7, 1);

        gridLayout_7->addLayout(horizontalLayout_12, 0, 0, 1, 1);

        pushTableView = new PushTable(Pusher);
        pushTableView->setObjectName(QStringLiteral("pushTableView"));
        pushTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        pushTableView->setDefaultDropAction(Qt::LinkAction);
        pushTableView->setSelectionMode(QAbstractItemView::NoSelection);
        pushTableView->horizontalHeader()->setStretchLastSection(true);

        gridLayout_7->addWidget(pushTableView, 1, 0, 1, 1);

        tabWidget->addTab(Pusher, QString());
>>>>>>> dev1.0
        Systemset = new QWidget();
        Systemset->setObjectName(QStringLiteral("Systemset"));
        gridLayout_3 = new QGridLayout(Systemset);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(Systemset);
        groupBox->setObjectName(QStringLiteral("groupBox"));

        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(Systemset);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));

        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(Systemset);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));

        gridLayout_3->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(Systemset);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));

        gridLayout_3->addWidget(groupBox_4, 1, 1, 1, 1);

        tabWidget->addTab(Systemset, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        mediaoptionClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(mediaoptionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mediaoptionClass->setStatusBar(statusBar);

        retranslateUi(mediaoptionClass);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(mediaoptionClass);
    } // setupUi

    void retranslateUi(QMainWindow *mediaoptionClass)
    {
        mediaoptionClass->setWindowTitle(QApplication::translate("mediaoptionClass", "VMS\345\271\263\345\217\260", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        Play->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        checkBox->setText(QApplication::translate("mediaoptionClass", "TCP", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("mediaoptionClass", "UDP", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("mediaoptionClass", "\344\272\272\350\204\270\346\243\200\346\265\213", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("mediaoptionClass", "1\345\210\206\345\261\217", Q_NULLPTR)
         << QApplication::translate("mediaoptionClass", "4\345\210\206\345\261\217", Q_NULLPTR)
         << QApplication::translate("mediaoptionClass", "6\345\210\206\345\261\217", Q_NULLPTR)
         << QApplication::translate("mediaoptionClass", "9\345\210\206\345\261\217", Q_NULLPTR)
         << QApplication::translate("mediaoptionClass", "16\345\210\206\345\261\217", Q_NULLPTR)
        );
        comboBox->setCurrentText(QApplication::translate("mediaoptionClass", "1\345\210\206\345\261\217", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("mediaoptionClass", "\346\222\255\346\224\276\345\234\260\345\235\200:", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("mediaoptionClass", "\351\200\211\346\213\251\345\234\260\345\235\200", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(Play), QApplication::translate("mediaoptionClass", "\346\222\255\346\224\276", Q_NULLPTR));
        vodqlabel->setText(QString());
        pushButton_20->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_19->setText(QString());
        pushButton_10->setText(QString());
        pushButton_8->setText(QString());
        pushButton_21->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Voplay), QApplication::translate("mediaoptionClass", "\347\202\271\346\222\255", Q_NULLPTR));
<<<<<<< HEAD
        addServer->setText(QApplication::translate("mediaoptionClass", "\346\267\273\345\212\240\346\265\201\345\252\222\344\275\223\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("mediaoptionClass", "\351\200\211\346\213\251\346\234\215\345\212\241\345\231\250:", Q_NULLPTR));
        startServer->setText(QApplication::translate("mediaoptionClass", "\346\211\223\345\274\200\346\265\201\345\252\222\344\275\223\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Pusher), QApplication::translate("mediaoptionClass", "\346\216\250\346\265\201\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("mediaoptionClass", "\346\267\273\345\212\240\350\256\276\345\244\207", Q_NULLPTR));
        lineEdit_8->setText(QApplication::translate("mediaoptionClass", "\350\256\276\345\244\207\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        lineEdit_9->setText(QApplication::translate("mediaoptionClass", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        lineEdit_14->setText(QApplication::translate("mediaoptionClass", "\350\256\276\345\244\207\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit_10->setText(QApplication::translate("mediaoptionClass", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        lineEdit_11->setText(QApplication::translate("mediaoptionClass", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lineEdit_12->setText(QApplication::translate("mediaoptionClass", "IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        lineEdit_13->setText(QApplication::translate("mediaoptionClass", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        cancelDevice->setText(QApplication::translate("mediaoptionClass", "\345\217\226\346\266\210", Q_NULLPTR));
        submitDevice->setText(QApplication::translate("mediaoptionClass", "\347\241\256\345\256\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Device), QApplication::translate("mediaoptionClass", "\350\256\276\345\244\207\347\256\241\347\220\206", Q_NULLPTR));
=======
        addServer->setText(QApplication::translate("mediaoptionClass", "\346\267\273\345\212\240\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        addStream->setText(QApplication::translate("mediaoptionClass", "\346\267\273\345\212\240\350\247\206\351\242\221", Q_NULLPTR));
        pushAll->setText(QApplication::translate("mediaoptionClass", "\346\211\271\351\207\217\346\216\250\346\265\201or\346\232\202\345\201\234", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("mediaoptionClass", "\351\200\211\346\213\251\346\234\215\345\212\241\345\231\250\357\274\232", Q_NULLPTR));
        startServer->setText(QApplication::translate("mediaoptionClass", "RtspServer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Pusher), QApplication::translate("mediaoptionClass", "\346\216\250\346\265\201\350\256\276\347\275\256", Q_NULLPTR));
>>>>>>> dev1.0
        groupBox->setTitle(QApplication::translate("mediaoptionClass", "\345\233\275\346\240\207", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("mediaoptionClass", "\345\271\263\345\217\260", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("mediaoptionClass", "onvif", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("mediaoptionClass", "\351\242\204\347\225\231", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Systemset), QApplication::translate("mediaoptionClass", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mediaoptionClass: public Ui_mediaoptionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAOPTION_H
