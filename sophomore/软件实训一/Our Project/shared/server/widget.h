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
    void RegistrationFunction(QString account,QString password);//ע�ắ��
    void SignINFunction(QString account,QString password);//��¼����
    void SignOutFunction(QString id);//�ǳ�����
    void GameCreateFunction(QString account1);//������Ϸ����
    //void InviteFriendFunction(QString invitee);//���뺯��
    //void InviteReturnFunction(QString inviter);//���뷴������
    void JudgeFunction(void);//��һ������жϺ���
    void MessageTransmissionFunction(void);//��Ϣ���亯��
    //void TalkFunction(QString receiver);//���캯��
    QString Message;
    static int nowid;
    int scoketnum;
    QSqlDatabase AccountData;


protected slots:
    void on_pushButton_clicked();//�����������ť
    void newConnect();//�����µ�����ʱ���ź�
    void sendMessage(QString infomation,int id=-1);//��ĳһ���ӵĿͻ��˷����ź�
    void readMessage();//��ȡ�ӿͻ��˽��ܵ��ź�

protected:
    Ui::Widget *ui;
    QString message;
    QString greeting;
    QString string;
    QTcpSocket *m_tcpsocket;
    QTcpServer *m_tcpserver;
    QList<QTcpSocket*> socket_list;//�������г��б���ڵ�ȡ
    int scoketnumber;

};

#endif // WIDGET_H
