#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QDialog>
#include "SplitScreen.h"
#include <qtimer.h>
#include "DecoderThread.h"
#include "SqliteOperate.h"
#include <qmessagebox.h>
#include "ui_addserver.h"
#include "BasicUsageEnvironment.hh"
#include "DynamicRTSPServer.hh"
#include "version.hh"
#define ACCESS_CONTROL

class mediaoption : public QMainWindow
{
    Q_OBJECT

public:
    mediaoption(QWidget* parent = Q_NULLPTR);
    virtual ~mediaoption();

private:
    Ui::mediaoptionClass ui;
    Ui::addserverdialog addsr;
    QDialog* addser;
    void initWindow(void);
    void initDb();
    void setScreen(int check);
    void initplay(int index);
    void setdevicetype();
    void startserver();
private:
    QTimer* timer;
    DecoderThread* decoderthread[MAXSCREEN];
    SplitScreen* scr;
    int scrindex;
    QList<int> playlist;
    SqliteOperate *DB;
    

private slots:
    

};
