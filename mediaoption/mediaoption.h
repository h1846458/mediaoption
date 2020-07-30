#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QDialog>
#include "SplitScreen.h"
#include <qtimer.h>
#include "DecoderThread.h"
#include "PushThread.h"
#include "SqliteOperate.h"
#include <qmessagebox.h>
#include "ui_addserver.h"
#include "ui_addstream.h"


class mediaoption : public QMainWindow
{
    Q_OBJECT

public:
    mediaoption(QWidget* parent = Q_NULLPTR);
    virtual ~mediaoption();

private:
    Ui::mediaoptionClass ui;
    Ui::addserverdialog addsr;
    Ui::addstream addstr;
    QDialog* addser;
    QDialog* addstrm;
    void initWindow(void);
    void initDb();
    void setScreen(int check);
    void initplay(int index);
    void setdevicetype();
private:
    QTimer* timer;
    DecoderThread* decoderthread[MAXSCREEN];
    PushThread* sr;
    SplitScreen* scr;
    int scrindex;
    QList<int> playlist;
    SqliteOperate *DB;
    

private slots:
    

};
