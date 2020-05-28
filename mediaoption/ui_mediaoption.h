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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaoptionClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
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
        mediaoptionClass->resize(1578, 1046);
        centralWidget = new QWidget(mediaoptionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(103, 71, 1261, 781));
        label->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        mediaoptionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mediaoptionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1578, 23));
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

        QMetaObject::connectSlotsByName(mediaoptionClass);
    } // setupUi

    void retranslateUi(QMainWindow *mediaoptionClass)
    {
        mediaoptionClass->setWindowTitle(QApplication::translate("mediaoptionClass", "mediaoption", Q_NULLPTR));
        label->setText(QString());
        menuFile->setTitle(QApplication::translate("mediaoptionClass", "File", Q_NULLPTR));
        menuoption->setTitle(QApplication::translate("mediaoptionClass", "Edit", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("mediaoptionClass", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mediaoptionClass: public Ui_mediaoptionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAOPTION_H
