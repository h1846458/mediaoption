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
<<<<<<< HEAD
#include "BasicUsageEnvironment.hh"
#include "DynamicRTSPServer.hh"
#include "version.hh"
#define ACCESS_CONTROL
=======
#include "ui_addstream.h"

>>>>>>> dev1.0

class mediaoption : public QMainWindow
{
    Q_OBJECT

public:
    mediaoption(QWidget* parent = Q_NULLPTR);
    virtual ~mediaoption();

private:
    Ui::mediaoptionClass ui;
    Ui::addserverdialog addsr;
<<<<<<< HEAD
    QDialog* addser;
=======
    Ui::addstream addstr;
    QDialog* addser;
    QDialog* addstrm;
>>>>>>> dev1.0
    void initWindow(void);
    void initDb();
    void setScreen(int check);
    void initplay(int index);
    void setdevicetype();
    void startserver();
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
