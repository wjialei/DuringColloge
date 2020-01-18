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

//�������ݿ����ӣ��źźͲ�
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

//��������
Widget::~Widget()
{
    AccountData.close();
    delete ui;

}

//���ƣ����Ӻ���
//�����������б�����ͻ��˵�����
//�������ڣ�2018/9/7
//������void
//����ֵ���ͣ�void
//���ߣ����ڿ�
void Widget::newConnect()
{

    m_tcpsocket = m_tcpserver->nextPendingConnection();

    socket_list.append(m_tcpsocket);

    connect(m_tcpsocket,SIGNAL(readyRead()),
            this,SLOT(readMessage()));


}

//������Ϣ
//��ȡFunction�������ദ��
//�������ڣ�2018/9/7
//������void
//����ֵ���ͣ�void
//���ߣ����ڿ�
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

//������Ϣ
//���ڽ���Ϣ�������ͻ���
//�������ڣ�2018/9/7
//������infomation(QString)���������scoketnum(int)�������
//����ֵ���ͣ�void
//���ߣ����ڿ�
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

//��ť��������
//���ڲ�����Ϣ���͵İ�ť
//�������ڣ�2018/9/7
//������void
//����ֵ���ͣ�void
//���ߣ����ڿ�
void Widget::on_pushButton_clicked()
{

    string =  ui->lineEdit->text() ;
    sendMessage(string);
    ui->lineEdit->clear();
    qDebug()<<string;
}


int Widget::nowid=0;


//���ຯ��
//�Խ��յ���Ϣ���з��ಢ��ת����Ӧ����
//�������ڣ�2018/9/7
//������info(QStringList)���뺯��,message(QString)���뺯����scoketnum��int�����뺯��
//����ֵ���ͣ�void
//���ߣ����ڿ�
void Widget::Function(QStringList info,QString message,int scoketnumber)
{
    Message=message;
    scoketnum=scoketnumber;
    if (QSqlDatabase::contains("qt_sql_account_connection"))//�������ݿ�����
    {
        AccountData = QSqlDatabase::database("qt_sql_account_connection");
    }
    else
    {
        AccountData = QSqlDatabase::addDatabase("QSQLITE","qt_sql_account_connection");
        AccountData.setDatabaseName("C:/AccountData.db");
        qDebug()<<"db";

    }
    if(info[0]=="sj"||info[0]=="sz"||info[0]=="hs"||info[0]=="lt"||info[0]=="gm")//��ת��Ϣ���亯��
    {MessageTransmissionFunction();return;}
    if(info[0]=="js")//��ת��������
    {JudgeFunction();return;}
    if(info[0]=="zc")//��תע�ắ��
    {RegistrationFunction(info[1],info[2]);return;}
    if(info[0]=="dl")//��ת��¼����
    {SignINFunction(info[1],info[2]);return;}
    if(info[0]=="tc")//��ת�ǳ�����
    {SignOutFunction(info[1]);return;}
    if(info[0]=="cj")//��ת��������
    {GameCreateFunction(info[1]);return;}
    //if(info[0]=="yq")//��ת���뺯��
    //{InviteFriendFunction(info[2]);return;}
    //if(info[0]=="sf")//��ת���뷴������
    //{InviteReturnFunction(info[2]);return;}
    //if(info[0]=="lt")//��ת���캯��
    //{InviteReturnFunction(info[1]);return;}


}



//��Ϣ���ݺ���
//���¼���Ϣ��ɫ����Ϣ�����������ͻ���
//�������ڣ�2018/9/7
//������void
//����ֵ���ͣ�void
//���ߣ����ڿ�
void Widget::MessageTransmissionFunction()
{
    sendMessage(Message);
}

//��һ������жϺ���
//���ս�����Ϣ��������һ����ҵ���Ϣ
//�������ڣ�2018/9/7
//������void
//����ֵ���ͣ�void
//���ߣ����ڿ�
void Widget::JudgeFunction()
{
    qDebug()<<"receive js";

    nowid++;
    static int sum=2;
    if(nowid>1)
    {nowid-=sum;}
    //�ó���ȴ�3s
    QEventLoop eventloop;
    QTimer::singleShot(3000, &eventloop, SLOT(quit()));
    eventloop.exec();
    message="ks|"+QString::number(nowid);//�㲥��һ�غϵ����
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
             if (nowid== sql_query.value(0).toInt())//����nowid���û������ߵ��������������
             {judge=1;}

        }
    }



if(judge==0)
    {
        //�ó���ȴ�3s
        QEventLoop eventloop;
        QTimer::singleShot(3000, &eventloop, SLOT(quit()));
        eventloop.exec();

        message="ks|"+QString::number(nowid);//�㲥��һ�غϵ����
        sendMessage(message);
        qDebug()<<"ksFunc";
    }
else
    {JudgeFunction();}

 */
}

//ע�ắ��
//�����˺����룬�������ݿ⣬����ע��ɹ�����Ϣ
//�������ڣ�2018/9/7
//������account(QString)���뺯��,password(QString)���뺯��
//����ֵ���ͣ�void
//���ߣ����ڿ�
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

        //�ҵ�max_id
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

        //�ж��Ƿ��˻��Ѵ���
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
        if(judge==1)//����Ѿ����ڣ�����ע��ʧ�ܵ���Ϣ
        {
            Qstr="zc|0";
            sendMessage(Qstr,scoketnum);
            qDebug()<<"zc|0"<<endl;
        }
        else
        {
        //�����ݿ��м����µ�ע����
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
            Qstr="zc|1";//����ע��ɹ�����Ϣ
            qDebug()<<"zc|1"<<endl;
            sendMessage(Qstr,scoketnum);

        }
    }
}

//��¼����
//�����˺����룬���͸��ÿͻ���������Ϣ
//�������ڣ�2018/9/7
//������account(QString)�������,password(QString)�������
//����ֵ���ͣ�void
//���ߣ����ڿ�
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
    //�ж��˺������Ƿ���ȷ������TorF����ǰ����
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
                Qstr="sx|1";//������ȷ���������߳ɹ�����Ϣ
                sendMessage(Qstr,scoketnum);
            }
            else
            {
                Qstr="sx|0";//������󣬷�������ʧ�ܵ���Ϣ
                sendMessage(Qstr,scoketnum);
            }

        }
    }
    }
/*
    //�����˺ŵ�������Ϣ��Ϊtrue
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


    //��������������Ϣ������������
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

//�ǳ������������˺����룬���͸����пͻ��˸��˺����ߵ���Ϣ
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

//�ǳ�����
//�����˺ź�ID���ı����ݿ�
//�������ڣ�2018/9/7
//������account(QString)�������,id(QString)�������
//����ֵ���ͣ�void
//���ߣ����ڿ�
void Widget::SignOutFunction(QString id)
{
    QSqlQuery sql_query(AccountData);
    QString update_sql = "update game set Online = :Online where id = :id";
    sql_query.prepare(update_sql);
    sql_query.bindValue(":Online", 0);//����ID��online��Ϊfalse
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

//��Ϸ��������
//�����ĸ��˺ţ�����һ���±����Ϳ�ʼ��Ϣ
//�������ڣ�2018/9/7
//������account(QString)
//����ֵ���ͣ�void
//���ߣ����ڿ�
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
    QString insert_sql = "insert into game values (?, ?, ?)";//����ҵ���Ϣ���뵽��game��
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
        //�ó���ȴ�1s
        QEventLoop eventloop;
        QTimer::singleShot(1000, &eventloop, SLOT(quit()));
        eventloop.exec();
        Qstr="ks|0";
        sendMessage(Qstr);
        max_id=0;
    }


}

/*
//�������뺯������������˺ŷ���������Ϣ
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

//���뷵�غ����������뷢��������������Ϣ
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

//���캯��
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

