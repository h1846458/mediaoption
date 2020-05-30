#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mediaoption.h"
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
private:
    QTimer* timer;
    //double Capturetime;
    string url;
    FFmpegDecoder decoder;
    QImage image;
private slots:
    void opencvdisplay(void);
};
