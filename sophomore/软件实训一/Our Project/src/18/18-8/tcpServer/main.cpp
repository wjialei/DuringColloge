#include <QApplication>
#include "server.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString::fromLocal8Bit ("中文");
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
        //QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
        //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF_8"));
    Server w;
    w.show();

    return a.exec();
}
