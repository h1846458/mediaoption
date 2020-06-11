/********************************************************************************
** Form generated from reading UI file 'mediaoption.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAOPTION_H
#define UI_MEDIAOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaoptionClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTabWidget *tabWidget;
    QWidget *Play;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;
    QCheckBox *checkBox_3;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox;
    QWidget *playwidget;
    QPushButton *pushButton_2;
    QSlider *horizontalSlider;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *Voplay;
    QWidget *Pusher;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuoption;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mediaoptionClass)
    {
        if (mediaoptionClass->objectName().isEmpty())
            mediaoptionClass->setObjectName(QStringLiteral("mediaoptionClass"));
        mediaoptionClass->resize(1343, 906);
        centralWidget = new QWidget(mediaoptionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 218, 829));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        Play = new QWidget();
        Play->setObjectName(QStringLiteral("Play"));
        checkBox = new QCheckBox(Play);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 10, 61, 21));
        checkBox_2 = new QCheckBox(Play);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(90, 10, 51, 21));
        pushButton = new QPushButton(Play);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(860, 10, 75, 23));
        checkBox_3 = new QCheckBox(Play);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(170, 10, 71, 21));
        fontComboBox = new QFontComboBox(Play);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(640, 10, 213, 22));
        comboBox = new QComboBox(Play);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(520, 10, 81, 22));
        comboBox->setEditable(true);
        playwidget = new QWidget(Play);
        playwidget->setObjectName(QStringLiteral("playwidget"));
        playwidget->setGeometry(QRect(0, 40, 1071, 761));
        playwidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 249);"));
        pushButton_2 = new QPushButton(Play);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(960, 10, 75, 23));
        horizontalSlider = new QSlider(Play);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(300, 10, 161, 22));
        horizontalSlider->setAutoFillBackground(false);
        horizontalSlider->setStyleSheet(QLatin1String("QSlider{\n"
"border-color: #bcbcbc;\n"
"}\n"
"QSlider::groove:horizontal {                                \n"
"     border: 1px solid #999999;                             \n"
"     height: 1px;                                           \n"
"    margin: 0px 0;                                         \n"
"     left: 5px; right: 5px; \n"
" }\n"
"\n"
"\n"
"QSlider::handle:horizontal {                               \n"
"     border: 0px ;                           \n"
"     border-image:  url(:/res/vol/p.png);\n"
"     width: 15px;                                           \n"
"     margin: -7px -7px -7px -7px;                  \n"
"} \n"
"QSlider::sub-page:horizontal{                               \n"
" background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);                     \n"
"}\n"
""));
        horizontalSlider->setMinimum(10);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton_3 = new QPushButton(Play);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(260, 10, 41, 23));
        pushButton_3->setStyleSheet(QStringLiteral("selection-background-color: rgb(255, 251, 253);"));
        QIcon icon;
        icon.addFile(QStringLiteral("res/vol/jian.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_4 = new QPushButton(Play);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(460, 10, 41, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral("res/vol/jia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        tabWidget->addTab(Play, QString());
        Voplay = new QWidget();
        Voplay->setObjectName(QStringLiteral("Voplay"));
        tabWidget->addTab(Voplay, QString());
        Pusher = new QWidget();
        Pusher->setObjectName(QStringLiteral("Pusher"));
        tabWidget->addTab(Pusher, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 5);
        mediaoptionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mediaoptionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1343, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuoption = new QMenu(menuBar);
        menuoption->setObjectName(QStringLiteral("menuoption"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        mediaoptionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mediaoptionClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mediaoptionClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mediaoptionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mediaoptionClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuoption->menuAction());
        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(mediaoptionClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mediaoptionClass);
    } // setupUi

    void retranslateUi(QMainWindow *mediaoptionClass)
    {
        mediaoptionClass->setWindowTitle(QApplication::translate("mediaoptionClass", "mediaoption", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        Play->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        checkBox->setText(QApplication::translate("mediaoptionClass", "TCP", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("mediaoptionClass", "UDP", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mediaoptionClass", "Play", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("mediaoptionClass", "\344\272\272\350\204\270\346\243\200\346\265\213", Q_NULLPTR));
        fontComboBox->setCurrentText(QApplication::translate("mediaoptionClass", "\346\222\255\346\224\276\345\234\260\345\235\200", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("mediaoptionClass", "1\345\210\206\345\261\217", Q_NULLPTR)
         << QApplication::translate("mediaoptionClass", "4\345\210\206\345\261\217", Q_NULLPTR)
         << QApplication::translate("mediaoptionClass", "6\345\210\206\345\261\217", Q_NULLPTR)
         << QApplication::translate("mediaoptionClass", "9\345\210\206\345\261\217", Q_NULLPTR)
         << QApplication::translate("mediaoptionClass", "16\345\210\206\345\261\217", Q_NULLPTR)
        );
        comboBox->setCurrentText(QApplication::translate("mediaoptionClass", "1\345\210\206\345\261\217", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("mediaoptionClass", "Stop", Q_NULLPTR));
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Play), QApplication::translate("mediaoptionClass", "\346\222\255\346\224\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Voplay), QApplication::translate("mediaoptionClass", "\347\202\271\346\222\255", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Pusher), QApplication::translate("mediaoptionClass", "\346\216\250\346\265\201", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("mediaoptionClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menuoption->setTitle(QApplication::translate("mediaoptionClass", "\347\274\226\350\276\221", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("mediaoptionClass", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mediaoptionClass: public Ui_mediaoptionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAOPTION_H
