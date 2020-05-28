#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mediaoption.h"
#include <qtimer.h>

class mediaoption : public QMainWindow
{
    Q_OBJECT

public:
    mediaoption(QWidget *parent = Q_NULLPTR);
    virtual ~mediaoption();

private:
    Ui::mediaoptionClass ui;
    void initWindow(void);
private:
    QTimer* timer, * timer1;
    double Capturetime;
private slots:
    void opencvdisplay(void);
};
