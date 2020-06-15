#pragma once

#include <QtWidgets/QMainWindow>
#include "SplitScreen.h"
#include <qtimer.h>
#include "DecoderThread.h"

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
    QTimer* timer[MAXSCREEN];
    DecoderThread* decoderthread[MAXSCREEN];
    SplitScreen* scr;
    int scrindex;
private slots:
    void opencvdisplay(void);

};
