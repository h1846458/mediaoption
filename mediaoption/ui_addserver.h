/********************************************************************************
** Form generated from reading UI file 'addserver.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSERVER_H
#define UI_ADDSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addserverdialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_10;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *addsrpushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cancelpushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *addserverdialog)
    {
        if (addserverdialog->objectName().isEmpty())
            addserverdialog->setObjectName(QStringLiteral("addserverdialog"));
        addserverdialog->resize(452, 311);
        addserverdialog->setLayoutDirection(Qt::LeftToRight);
        widget = new QWidget(addserverdialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 421, 281));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout->addWidget(lineEdit_6);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setLayoutDirection(Qt::LeftToRight);
        lineEdit_4->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit_4->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        lineEdit_4->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_4);

        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        horizontalLayout_2->addWidget(lineEdit_7);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit_5->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        lineEdit_5->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_5);

        lineEdit_8 = new QLineEdit(widget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        horizontalLayout_3->addWidget(lineEdit_8);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        lineEdit_2->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEdit_2);

        lineEdit_9 = new QLineEdit(widget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        horizontalLayout_4->addWidget(lineEdit_9);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setStyleSheet(QLatin1String("QLineEdit{background-color:transparent}\n"
"QLineEdit{border-width:0;border-style:outset}"));
        lineEdit_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        lineEdit_3->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEdit_3);

        lineEdit_10 = new QLineEdit(widget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        horizontalLayout_5->addWidget(lineEdit_10);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        addsrpushButton = new QPushButton(widget);
        addsrpushButton->setObjectName(QStringLiteral("addsrpushButton"));

        horizontalLayout_6->addWidget(addsrpushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        cancelpushButton = new QPushButton(widget);
        cancelpushButton->setObjectName(QStringLiteral("cancelpushButton"));

        horizontalLayout_6->addWidget(cancelpushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(addserverdialog);

        QMetaObject::connectSlotsByName(addserverdialog);
    } // setupUi

    void retranslateUi(QDialog *addserverdialog)
    {
        addserverdialog->setWindowTitle(QApplication::translate("addserverdialog", "\346\267\273\345\212\240\346\265\201\345\252\222\344\275\223\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("addserverdialog", "*Server\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("addserverdialog", "*\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        lineEdit_5->setText(QApplication::translate("addserverdialog", "*\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("addserverdialog", "*IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("addserverdialog", "*\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        addsrpushButton->setText(QApplication::translate("addserverdialog", "\347\241\256\345\256\232", Q_NULLPTR));
        cancelpushButton->setText(QApplication::translate("addserverdialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addserverdialog: public Ui_addserverdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSERVER_H
