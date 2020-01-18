#include "loginmainwindow.h"
#include <QApplication>
#include "gameWindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   LoginMainWindow w;

    w.show();

    return a.exec();
}
