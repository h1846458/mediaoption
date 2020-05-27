#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mediaoption.h"

class mediaoption : public QMainWindow
{
    Q_OBJECT

public:
    mediaoption(QWidget *parent = Q_NULLPTR);

private:
    Ui::mediaoptionClass ui;
};
