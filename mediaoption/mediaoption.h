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
    //double Capturetime;
    string url;
    FFmpegDecoder decoder;
    QImage image;
    SplitScreen* scr;
    int scrindex;
    PlayQlabel* playlabel;
private slots:
    void opencvdisplay(void);

};
