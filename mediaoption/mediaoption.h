#pragma once

#include <QtWidgets/QMainWindow>
#include "SplitScreen.h"
#include <qtimer.h>
#include "ffmpegDecode.h"

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
    FFmpegDecoder *decoder[MAXSCREEN];
    QImage image;
    SplitScreen* scr;
    int scrindex;
private slots:
    void opencvdisplay(void);

};
