#include "musicwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MusicWindow w;
    w.show();
    return a.exec();
}
