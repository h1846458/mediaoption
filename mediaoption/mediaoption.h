#pragma once

#include <QtWidgets/QMainWindow>
#include "SplitScreen.h"
#include <qtimer.h>
#include "DecoderThread.h"
#include <qmessagebox.h>

class mediaoption : public QMainWindow
{
    Q_OBJECT

public:
    mediaoption(QWidget* parent = Q_NULLPTR);
    virtual ~mediaoption();

private:
    Ui::mediaoptionClass ui;
    void initWindow(void);
    void setScreen(int check);
private:
    QTimer* timer;
    DecoderThread* decoderthread[MAXSCREEN];
    SplitScreen* scr;
    int scrindex;
    QList<int> playlist;
    void initplay(int index);

private slots:
    

};
