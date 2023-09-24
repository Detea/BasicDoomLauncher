#include "QtDoomLauncher.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtDoomLauncher w;
    w.show();
    return a.exec();
}
