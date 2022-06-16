#include "QTtest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTtest w;
    w.show();
    return a.exec();
}
