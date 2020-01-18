#include<function.h>
#include<QString>
#include<QStringList>
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QDebug>
#include <string.h>
using namespace std;
int Widget::nowid=1;



//对接收的消息进行分类
Function::Function(QStringList info,QString message,int scoketnumber)
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
        AccountData.setDatabaseName("E:/server/AccountData.db");

    }
    qDebug()<<"FUNC on"<<info[0]<<" "<<info[1]<<" "<<info[2]<<" "<<scoketnum<<endl;
    if(info[0]=="sj")//跳转消息传输函数
    {MessageTransmissionFunction();return;}
    if(info[0]=="js")//跳转结束函数
    {JudgeFunction();return;}
    if(info[0]=="zc")//跳转注册函数
    {RegistrationFunction(info[1],info[2]);return;}
    if(info[0]=="dl")//跳转登录函数
    {SignINFunction(info[1],info[2]);return;}
    if(info[0]=="tc")//跳转登出函数
    {SignOutFunction(info[1],info[2]);return;}
    if(info[0]=="cj")//跳转创建函数
    {GameCreateFunction(info[1]);return;}
    //if(info[0]=="yq")//跳转邀请函数
    //{InviteFriendFunction(info[2]);return;}
    //if(info[0]=="sf")//跳转邀请反馈函数
    //{InviteReturnFunction(info[2]);return;}
    //if(info[0]=="lt")//跳转聊天函数
    //{InviteReturnFunction(info[2]);return;}


}

//Function函数的析构函数，用于关闭数据库的连接
Function::~Function()
{
    AccountData.close();
}

//消息传递函数，将游戏消息传递至其他客户端
void Function::MessageTransmissionFunction()
{
    sendMessage(Message);
}

//下一个玩家判断函数，接收结束消息，发送下一个玩家的消息
void Function::JudgeFunction()
{
    QSqlQuery sql_query;
    int judge=0;
    nowid++;
    static int sum=4;
    if(nowid>sum)
    nowid-=sum;

    QString select_sql = "select id from game where Online = :Online";
    sql_query.bindValue(":Online", 0);
    if(!sql_query.exec(select_sql))
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
        message="ks|"+QString::number(nowid);//广播下一回合的玩家
        sendMessage(message);
    }
else
    {JudgeFunction();}

}

//注册函数，接收账号密码，调整数据库，返回注册成功的消息
void Function::RegistrationFunction(QString account,QString password)
{
    qDebug()<<"zc on"<<endl;

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
        //往数据库中加入新的注册用户
        AccountData.close();
        if (!AccountData.open())
        {
            qDebug() << "Error: Failed to connect database." << AccountData.lastError();
        }
        else
        {
            QSqlQuery sql_query(AccountData);
        //QString insert_sql = "insert into account values (?, ?, ?, ?, ?)";
           QString insert_sql = "insert into account(id) values (:id)";
        sql_query.prepare(insert_sql);
        //sql_query.addBindValue();
        //sql_query.addBindValue("001");
        //sql_query.addBindValue("002");
       // sql_query.addBindValue(0);
       // sql_query.addBindValue(-1);
        sql_query.bindValue(":id",2);
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
}

//登录函数，接收账号密码，发送给该客户端在线信息
void Function::SignINFunction(QString account,QString password)
{
    QSqlQuery sql_query;
    QString Qstr;

    //判断账号密码是否正确，返回TorF给当前连接
    QString select_sql = "select password from account where account = :account";
    sql_query.bindValue(":account", account);
    if(!sql_query.exec(select_sql))
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
void Function::SignOutFunction(QString account,QString password)
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

//登出函数，接受账号和ID，改变数据库
void Function::SignOutFunction(QString account,QString id)
{
    QSqlQuery sql_query;
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


    update_sql = "update account set isOnline = :isOnline where account = :account";
    sql_query.prepare(update_sql);
    sql_query.bindValue(":isOnline", 0);//将该ID的isOnline改为false
    sql_query.bindValue(":account", account);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "updated!";
    }

}

//游戏创建函数，接收四个账号，创建一张新表，发送开始消息
void Function::GameCreateFunction(QString account)
{
    QSqlQuery sql_query;
    QString Qstr;

    static int max_id = 0;

    QString insert_sql = "insert into game values (?, ?, ?)";//将玩家的信息加入到表game中
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(max_id+1);
    sql_query.addBindValue(account);
    sql_query.addBindValue(1);
    max_id++;

    Qstr="cj|";
    Qstr+=QString::number(max_id);
    sendMessage(Qstr,scoketnum);

    if(max_id==4)
    {
        Qstr="cj|t";
        sendMessage(Qstr);
        Qstr="ks|1";
        sendMessage(Qstr);
    }


}

/*
//好友邀请函数，向被邀请的账号发送邀请消息
void Function::InviteFriendFunction(QString invitee)
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
void Function::InviteReturnFunction(QString inviter)
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
void Function::TalkFunction(QString receiver)
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
