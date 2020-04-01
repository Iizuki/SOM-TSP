#include "tspsom.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TspSom w;
    w.show();
    return a.exec();
}
