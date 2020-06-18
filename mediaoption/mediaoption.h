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
    QTimer* timer[MAXSCREEN];
    DecoderThread* decoderthread[MAXSCREEN];
    QImage image[MAXSCREEN];
    SplitScreen* scr;
    int scrindex;
    QList<int> playlist;

private slots:
    void opencvdisplay(void);

};
