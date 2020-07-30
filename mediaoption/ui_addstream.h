/********************************************************************************
** Form generated from reading UI file 'addstream.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTREAM_H
#define UI_ADDSTREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_addstream
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *deviceName1;
    QLineEdit *deviceName;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_3;
    QComboBox *deviceType;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_4;
    QComboBox *streamType;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *deviceid;
    QLineEdit *deviceId;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *user;
    QLineEdit *userName;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_10;
    QLineEdit *passWd;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_11;
    QLineEdit *ipAddr;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit_13;
    QLineEdit *devicePort;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelDevice;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitDevice;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *addstream)
    {
        if (addstream->objectName().isEmpty())
            addstream->setObjectName(QStringLiteral("addstream"));
        addstream->setEnabled(true);
        addstream->resize(326, 278);
        gridLayout_3 = new QGridLayout(addstream);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        deviceName1 = new QLineEdit(addstream);
        deviceName1->setObjectName(QStringLiteral("deviceName1"));
        deviceName1->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        deviceName1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        deviceName1->setReadOnly(true);

        horizontalLayout->addWidget(deviceName1);

        deviceName = new QLineEdit(addstream);
        deviceName->setObjectName(QStringLiteral("deviceName"));

        horizontalLayout->addWidget(deviceName);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_3 = new QLineEdit(addstream);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_3->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_3);

        deviceType = new QComboBox(addstream);
        deviceType->setObjectName(QStringLiteral("deviceType"));

        horizontalLayout_2->addWidget(deviceType);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_4 = new QLineEdit(addstream);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_4->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_4);

        streamType = new QComboBox(addstream);
        streamType->setObjectName(QStringLiteral("streamType"));

        horizontalLayout_3->addWidget(streamType);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        deviceid = new QLineEdit(addstream);
        deviceid->setObjectName(QStringLiteral("deviceid"));
        deviceid->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        deviceid->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        deviceid->setReadOnly(true);

        horizontalLayout_4->addWidget(deviceid);

        deviceId = new QLineEdit(addstream);
        deviceId->setObjectName(QStringLiteral("deviceId"));

        horizontalLayout_4->addWidget(deviceId);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        user = new QLineEdit(addstream);
        user->setObjectName(QStringLiteral("user"));
        user->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        user->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        user->setReadOnly(true);

        horizontalLayout_5->addWidget(user);

        userName = new QLineEdit(addstream);
        userName->setObjectName(QStringLiteral("userName"));

        horizontalLayout_5->addWidget(userName);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lineEdit_10 = new QLineEdit(addstream);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_10->setReadOnly(true);

        horizontalLayout_6->addWidget(lineEdit_10);

        passWd = new QLineEdit(addstream);
        passWd->setObjectName(QStringLiteral("passWd"));

        horizontalLayout_6->addWidget(passWd);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lineEdit_11 = new QLineEdit(addstream);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit_11->setReadOnly(true);

        horizontalLayout_7->addWidget(lineEdit_11);

        ipAddr = new QLineEdit(addstream);
        ipAddr->setObjectName(QStringLiteral("ipAddr"));

        horizontalLayout_7->addWidget(ipAddr);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_7, 6, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        lineEdit_13 = new QLineEdit(addstream);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit_13->setReadOnly(true);

        horizontalLayout_8->addWidget(lineEdit_13);

        devicePort = new QLineEdit(addstream);
        devicePort->setObjectName(QStringLiteral("devicePort"));

        horizontalLayout_8->addWidget(devicePort);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_8, 7, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        cancelDevice = new QPushButton(addstream);
        cancelDevice->setObjectName(QStringLiteral("cancelDevice"));

        horizontalLayout_9->addWidget(cancelDevice);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        submitDevice = new QPushButton(addstream);
        submitDevice->setObjectName(QStringLiteral("submitDevice"));

        horizontalLayout_9->addWidget(submitDevice);

        horizontalSpacer_3 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_9, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(addstream);

        QMetaObject::connectSlotsByName(addstream);
    } // setupUi

    void retranslateUi(QDialog *addstream)
    {
        addstream->setWindowTitle(QApplication::translate("addstream", "\346\267\273\345\212\240\350\247\206\351\242\221\346\272\220", Q_NULLPTR));
        deviceName1->setText(QApplication::translate("addstream", "*\350\256\276\345\244\207\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("addstream", "*\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("addstream", "*\350\247\206\351\242\221\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        deviceid->setText(QApplication::translate("addstream", "*\350\256\276\345\244\207\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        user->setText(QApplication::translate("addstream", "*\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        lineEdit_10->setText(QApplication::translate("addstream", "*\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lineEdit_11->setText(QApplication::translate("addstream", "*IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        lineEdit_13->setText(QApplication::translate("addstream", "*\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        cancelDevice->setText(QApplication::translate("addstream", "\345\217\226\346\266\210", Q_NULLPTR));
        submitDevice->setText(QApplication::translate("addstream", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addstream: public Ui_addstream {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTREAM_H
