#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QStringList>
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QDebug>
#include <QTimer>
#include <string.h>
using namespace std;

//设置数据库连接，信号和槽
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_tcpserver = new QTcpServer(this);
    m_tcpsocket = new QTcpSocket(this);
    m_tcpserver->listen(QHostAddress::Any,6666);

    connect(m_tcpserver,SIGNAL(newConnection()),
            this,SLOT(newConnect()));



}

//析构函数
Widget::~Widget()
{
    AccountData.close();
    delete ui;

}

//名称：连接函数
//描述：创建列表保存与客户端的连接
//作成日期：2018/9/7
//参数：void
//返回值类型：void
//作者：周于楷
void Widget::newConnect()
{

    m_tcpsocket = m_tcpserver->nextPendingConnection();

    socket_list.append(m_tcpsocket);

    connect(m_tcpsocket,SIGNAL(readyRead()),
            this,SLOT(readMessage()));


}

//接收消息
//调取Function类来分类处理
//作成日期：2018/9/7
//参数：void
//返回值类型：void
//作者：周于楷
void Widget::readMessage()
{

    for(int i = 0;i < socket_list.length();i++)
    {
        qDebug() << "QDataStream " ;
        QDataStream in(socket_list.at(i));
        in.setVersion (QDataStream::Qt_5_4);
        in >> message;
        if(!(message.isEmpty()))
        {
            scoketnumber=i;
            qDebug() << "break "<<i ;
            break;
        }
    }
    ui->textBrowser->append(tr("reveived message: '%1'").arg(message));
    qDebug() << "server message" << message;
    QStringList info = message.split("|");
    Function(info,message,scoketnumber);


}

//发送消息
//用于将消息发送至客户端
//作成日期：2018/9/7
//参数：infomation(QString)输入参数，scoketnum(int)输入参数
//返回值类型：void
//作者：周于楷
void Widget::sendMessage(QString infomation,int scoketnum)
{
    QString str = infomation;
    QByteArray message1;
    QDataStream out(&message1,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out<<str;

    qDebug()<<"scoketnum"<<scoketnum;
    if(scoketnum==-1)
    {
        for (int i = 0;i < socket_list.length();i ++)
        {
            socket_list.at(i)->write(message1);
            qDebug()<<"sendmessage "<<str<<"number "<<i;
            ui->textBrowser->append(tr("send message: '%1'").arg(str));

        }
    }
    else
    {
        socket_list.at(scoketnum)->write(message1);
        qDebug()<<"sendmessage "<<str;
        ui->textBrowser->append(tr("send message: '%1'").arg(str));
    }
}

//按钮单击函数
//用于测试消息发送的按钮
//作成日期：2018/9/7
//参数：void
//返回值类型：void
//作者：周于楷
void Widget::on_pushButton_clicked()
{

    string =  ui->lineEdit->text() ;
    sendMessage(string);
    ui->lineEdit->clear();
    qDebug()<<string;
}


int Widget::nowid=0;


//分类函数
//对接收的消息进行分类并跳转至对应函数
//作成日期：2018/9/7
//参数：info(QStringList)输入函数,message(QString)输入函数，scoketnum（int）输入函数
//返回值类型：void
//作者：周于楷
void Widget::Function(QStringList info,QString message,int scoketnumber)
{
    Message=message;
    scoketnum=scoketnumber;
    if (QSqlDatabase::contains("qt_sql_account_connection"))//定义数据库连接
    {
        AccountData = QSqlDatabase::database("qt_sql_account_connection");
    }
    else
    {
        AccountData = QSqlDatabase::addDatabase("QSQLITE","qt_sql_account_connection");
        AccountData.setDatabaseName("C:/AccountData.db");
        qDebug()<<"db";

    }
    if(info[0]=="sj"||info[0]=="sz"||info[0]=="hs"||info[0]=="lt"||info[0]=="gm")//跳转消息传输函数
    {MessageTransmissionFunction();return;}
    if(info[0]=="js")//跳转结束函数
    {JudgeFunction();return;}
    if(info[0]=="zc")//跳转注册函数
    {RegistrationFunction(info[1],info[2]);return;}
    if(info[0]=="dl")//跳转登录函数
    {SignINFunction(info[1],info[2]);return;}
    if(info[0]=="tc")//跳转登出函数
    {SignOutFunction(info[1]);return;}
    if(info[0]=="cj")//跳转创建函数
    {GameCreateFunction(info[1]);return;}
    //if(info[0]=="yq")//跳转邀请函数
    //{InviteFriendFunction(info[2]);return;}
    //if(info[0]=="sf")//跳转邀请反馈函数
    //{InviteReturnFunction(info[2]);return;}
    //if(info[0]=="lt")//跳转聊天函数
    //{InviteReturnFunction(info[1]);return;}


}



//消息传递函数
//将事件消息和色子消息传递至其他客户端
//作成日期：2018/9/7
//参数：void
//返回值类型：void
//作者：周于楷
void Widget::MessageTransmissionFunction()
{
    sendMessage(Message);
}

//下一个玩家判断函数
//接收结束消息，发送下一个玩家的消息
//作成日期：2018/9/7
//参数：void
//返回值类型：void
//作者：周于楷
void Widget::JudgeFunction()
{
    qDebug()<<"receive js";

    nowid++;
    static int sum=2;
    if(nowid>1)
    {nowid-=sum;}
    //让程序等待3s
    QEventLoop eventloop;
    QTimer::singleShot(3000, &eventloop, SLOT(quit()));
    eventloop.exec();
    message="ks|"+QString::number(nowid);//广播下一回合的玩家
    sendMessage(message);
    qDebug()<<"ksFunc";
    /*
     QSqlQuery sql_query(AccountData);
    int judge=0;
    nowid++;
    static int sum=4;
    if(nowid>3)
    {nowid-=sum;}


    QString select_sql = "select id from game where Online = :Online";
    sql_query.prepare(select_sql);
    sql_query.bindValue(":Online", 0);

    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
             if (nowid== sql_query.value(0).toInt())//遇到nowid的用户已下线的情况，将其跳过
             {judge=1;}

        }
    }



if(judge==0)
    {
        //让程序等待3s
        QEventLoop eventloop;
        QTimer::singleShot(3000, &eventloop, SLOT(quit()));
        eventloop.exec();

        message="ks|"+QString::number(nowid);//广播下一回合的玩家
        sendMessage(message);
        qDebug()<<"ksFunc";
    }
else
    {JudgeFunction();}

 */
}

//注册函数
//接收账号密码，调整数据库，返回注册成功的消息
//作成日期：2018/9/7
//参数：account(QString)输入函数,password(QString)输入函数
//返回值类型：void
//作者：周于楷
void Widget::RegistrationFunction(QString account,QString password)
{
    qDebug()<<"zc on";

    if (!AccountData.open())
    {
        qDebug() << "Error: Failed to connect database." << AccountData.lastError();
    }
    else
    {
        QSqlQuery sql_query(AccountData);
        QString Qstr;

        //找到max_id
        QString select_max_sql = "select max(id) from account";
        int max_id = 0;
        if(!sql_query.exec(select_max_sql))
        {
            qDebug() <<"1"<< sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {
                max_id = sql_query.value(0).toInt();
                qDebug() << QString("max id:%1").arg(max_id);
            }
        }

        //判断是否账户已存在
        int judge=0;
        QString select_sql = "select account from account";
        if(!sql_query.exec(select_sql))
        {
            qDebug()<<"2"<<sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {
                if (account==sql_query.value(0).toString())
                {judge=1;}

            }
        }
        if(judge==1)//如果已经存在，则发送注册失败的消息
        {
            Qstr="zc|0";
            sendMessage(Qstr,scoketnum);
            qDebug()<<"zc|0"<<endl;
        }
        else
        {
        //往数据库中加入新的注册用
            QString insert_sql = "insert into account values (:id,:account,:password,:isOline,:scoketnumber)";
            sql_query.prepare(insert_sql);
            sql_query.bindValue(":id",max_id+1);
            sql_query.bindValue(":account",account);
            sql_query.bindValue(":password",password);
            sql_query.bindValue(":isOline",0);
            sql_query.bindValue(":scoketnumber",-1);

            if(!sql_query.exec())
            {
                qDebug() <<"3"<<sql_query.lastError();
            }
            else
            {
                qDebug() << "inserted "<<account;
            }
            Qstr="zc|1";//发送注册成功的消息
            qDebug()<<"zc|1"<<endl;
            sendMessage(Qstr,scoketnum);

        }
    }
}

//登录函数
//接收账号密码，发送给该客户端在线信息
//作成日期：2018/9/7
//参数：account(QString)输入参数,password(QString)输入参数
//返回值类型：void
//作者：周于楷
void Widget::SignINFunction(QString account,QString password)
{
    QSqlQuery sql_query(AccountData);
    QString Qstr;

    if (!AccountData.open())
    {
        qDebug() << "Error: Failed to connect database." << AccountData.lastError();
    }
    else
    {
    //判断账号密码是否正确，返回TorF给当前连接
    QString select_sql = "select password from account where account = :account";
    sql_query.prepare(select_sql);
    sql_query.bindValue(":account", account);
    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
            if(password== sql_query.value(0).toString())
            {
                Qstr="sx|1";//密码正确，返回上线成功的消息
                sendMessage(Qstr,scoketnum);
            }
            else
            {
                Qstr="sx|0";//密码错误，返回上线失败的消息
                sendMessage(Qstr,scoketnum);
            }

        }
    }
    }
/*
    //将该账号的上线信息改为true
    QString update_sql = "update account set isOnLine = :isOnLine where account = :account and password = :password";
    sql_query.prepare(update_sql);
    sql_query.bindValue(":isOnLine", 1);
    sql_query.bindValue(":scoketnum", scoketnum);
    sql_query.bindValue(":account", account);
    sql_query.bindValue(":password", password);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "updated!";
    }


    //接受所有在线消息发给所有连接
    Qstr="zx";
    select_sql = "select account,isOnLine from account where ID = :ID ";
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
             if(sql_query.value(1).toBool())
             {
                 Qstr+="|";
                 Qstr+=sql_query.value(0).toString();

             }

        }
    }

    sendMessage(Qstr);
*/

}





/*

//登出函数，接受账号密码，发送给所有客户端该账号下线的消息
void Widget::SignOutFunction(QString account,QString password)
{
    QSqlQuery sql_query;
    QString update_sql = "update account set isOnLine = :isOnLine where account = :account and password = :password";
    sql_query.prepare(update_sql);
    sql_query.bindValue(":isOnLine", 0);
    sql_query.bindValue(":account", account);
    sql_query.bindValue(":password", password);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "updated!";
    }
     QString Qstr="xx|";
     Qstr+=account;
     sendMessage(Qstr);

}
*/

//登出函数
//接受账号和ID，改变数据库
//作成日期：2018/9/7
//参数：account(QString)输入参数,id(QString)输入参数
//返回值类型：void
//作者：周于楷
void Widget::SignOutFunction(QString id)
{
    QSqlQuery sql_query(AccountData);
    QString update_sql = "update game set Online = :Online where id = :id";
    sql_query.prepare(update_sql);
    sql_query.bindValue(":Online", 0);//将该ID的online改为false
    sql_query.bindValue(":id", id);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "updated!";
    }
    sendMessage(Message);
}

//游戏创建函数
//接收四个账号，创建一张新表，发送开始消息
//作成日期：2018/9/7
//参数：account(QString)
//返回值类型：void
//作者：周于楷
void Widget::GameCreateFunction(QString account)
{
    QSqlQuery sql_query(AccountData);
    QString Qstr;

    static int max_id = 0;

    if(max_id==0)
    {
        QString clear_sql = "delete from game";
        sql_query.prepare(clear_sql);
        if(!sql_query.exec())
        {
            qDebug() << sql_query.lastError();
        }
        else
        {
            qDebug() << "table cleared";
        }
    }
    QString insert_sql = "insert into game values (?, ?, ?)";//将玩家的信息加入到表game中
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(max_id+1);
    sql_query.addBindValue(account);
    sql_query.addBindValue(1);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "insertsed!";
    }
    max_id++;



    if(max_id==2)
    {

        Qstr="cj";
        QString select_sql = "select account from game";
        if(!sql_query.exec(select_sql))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {
                Qstr+="|";
                Qstr+= sql_query.value(0).toString();
            }
        }

        sendMessage(Qstr);
        //让程序等待1s
        QEventLoop eventloop;
        QTimer::singleShot(1000, &eventloop, SLOT(quit()));
        eventloop.exec();
        Qstr="ks|0";
        sendMessage(Qstr);
        max_id=0;
    }


}

/*
//好友邀请函数，向被邀请的账号发送邀请消息
void Widget::InviteFriendFunction(QString invitee)
{
    QSqlQuery sql_query;
    int num;
    QString select_sql = "select scoketnum from account where account = :account";
    sql_query.bindValue(":account", invitee);
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
             num = sql_query.value(0).toInt();
        }
    }
    sendMessage(message,num);
}

//邀请返回函数，向邀请发出方返回邀请信息
void Widget::InviteReturnFunction(QString inviter)
{
    QSqlQuery sql_query;
    int num;
    QString select_sql = "select scoketnum from account where account = :account";
    sql_query.bindValue(":account", inviter);
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
             num = sql_query.value(0).toInt();
        }
    }
    sendMessage(message,num);
}

//聊天函数
void Widget::TalkFunction(QString receiver)
{
    QSqlQuery sql_query;
    int num;
    QString select_sql = "select scoketnum from account where account = :account";
    sql_query.bindValue(":account", receiver);
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
             num = sql_query.value(0).toInt();
        }
    }
    sendMessage(message,num);
}
*/

