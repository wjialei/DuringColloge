#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class Widget;
}


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void Function(QStringList info,QString message,int scoketnumber=-1);
    void RegistrationFunction(QString account,QString password);//注册函数
    void SignINFunction(QString account,QString password);//登录函数
    void SignOutFunction(QString id);//登出函数
    void GameCreateFunction(QString account1);//创建游戏函数
    //void InviteFriendFunction(QString invitee);//邀请函数
    //void InviteReturnFunction(QString inviter);//邀请反馈函数
    void JudgeFunction(void);//下一个玩家判断函数
    void MessageTransmissionFunction(void);//消息传输函数
    //void TalkFunction(QString receiver);//聊天函数
    QString Message;
    static int nowid;
    int scoketnum;
    QSqlDatabase AccountData;


protected slots:
    void on_pushButton_clicked();//测试用输出按钮
    void newConnect();//建立新的连接时的信号
    void sendMessage(QString infomation,int id=-1);//向某一连接的客户端发送信号
    void readMessage();//读取从客户端接受的信号

protected:
    Ui::Widget *ui;
    QString message;
    QString greeting;
    QString string;
    QTcpSocket *m_tcpsocket;
    QTcpServer *m_tcpserver;
    QList<QTcpSocket*> socket_list;//将连接列成列表便于调取
    int scoketnumber;

};

#endif // WIDGET_H
