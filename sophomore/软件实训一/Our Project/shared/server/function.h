#ifndef FUNCTION_H
#define FUNCTION_H

#include<QString>
#include<QStringList>
#include <QDebug>
#include"widget.h"

class Function:public Widget
{
public:
    Function(QStringList info,QString message,int scoketnumber=-1);
    ~Function();
private:

};


#endif
