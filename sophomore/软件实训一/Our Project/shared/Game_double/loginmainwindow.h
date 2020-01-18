#ifndef LOGINMAINWINDOW_H
#define LOGINMAINWINDOW_H

#include "classes.h"
#include "gameWindow.h"
#include "registmainwindow.h"
#include "roommainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QtNetwork>
#include <QTcpSocket>
#include <QStringList>
#include <QMovie>

namespace Ui {
class LoginMainWindow;
}

class LoginMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginMainWindow(QWidget *parent = nullptr);
    virtual ~LoginMainWindow();
    void sendMessage(QString Qmessage);

    void MessageJudge(QStringList info);//消息选择函数
    void LoginFeedback(QStringList info);//登陆反馈函数
    void RegistrationFeedback(QStringList info);//注册反馈函数
    void CreateFeedback(QStringList info);//创建反馈函数
    void WinFeedback(QStringList info);//游戏获胜反馈函数
    void LoseFeedback(QStringList info);//游戏失败反馈函数


private slots:
    void on_RegistpushButton_clicked();
    void on_LoginpushButton_clicked();
    void on_LoginPasswordlineEdit_editingFinished();
    void on_LoginIDlineEdit_editingFinished();
    void on_LoginPasswordlineEdit_returnPressed();

public slots:
    void regist(QString);//接受注册消息的槽
    void gameCreate(void);//接受游戏创建消息的槽
    void Dice(int);//接受游戏窗口传来的骰子点数，并传给服务器
    void eventMessage(QString);//接受游戏窗口传来的事件消息，并传给服务器
    void roundEnd(void);//接受游戏窗口传来的回合结束消息，并传给服务器
    void winMessage(int);//接受游戏窗口传来的游戏胜利消息
    void loseMessage(int);//接受游戏窗口传来的游戏失败消息
    void returnRoom(void);//接受游戏窗口传来的重启房间窗口的消息
    void chatsender(QString);//发送聊天消息
    void houseMessage(QString);//接受游戏窗口传来的地产消息

signals:
    void sendName(QString);//向游戏窗口发送本机用户的账号
    void sendRoundBeginMessage(int);//向游戏窗口发送回合ID
    void sendDice(int);//将服务器传来的骰子点数并传给游戏窗口
    void sendEventMessage(QStringList);//将受服务器传来的事件消息传给游戏窗口
    void sendGameBeginMessage(QStringList);//将服务器传来的游戏开始消息传给游戏窗口
    void sendWinMessage(int);//将服务器传来的游戏获胜消息传给游戏窗口
    void sendLoseMessage(int);//将服务器传来的游戏失败消息传给游戏窗口
    void chatreceive(QStringList info);//接收服务器发来的聊天消息
    void sendHouseMessage(QStringList info);//将服务器传来的地产消息传给游戏窗口

public:
    RegistMainWindow *m_registWin;//实例化注册窗口
    RoomMainWindow *m_roomWin;//实例化房间窗口
    gameWindow *m_gameWin;//实例化游戏窗口

private:
    Ui::LoginMainWindow *ui;
    QTcpSocket *m_tcpsocket;
    QString m_user;//记录本机用户的名称（即账号）
};

#endif // LOGINMAINWINDOW_H
