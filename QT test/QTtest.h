#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTtest.h"

class QTtest : public QMainWindow
{
    Q_OBJECT

public:
    QTtest(QWidget *parent = Q_NULLPTR);

private:
    Ui::QTtestClass ui;
};
