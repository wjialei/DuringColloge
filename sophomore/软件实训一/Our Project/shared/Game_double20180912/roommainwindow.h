#ifndef ROOMMAINWINDOW_H
#define ROOMMAINWINDOW_H

#include <QMainWindow>
#include<QMovie>


namespace Ui {
class RoomMainWindow;
}


class RoomMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoomMainWindow(QWidget *parent = nullptr);
    ~RoomMainWindow();
public slots:
    void chatAdd(QStringList);//显示聊天内容
private slots:
    void on_RoomPlaypushButton_clicked();//定义开始游戏信号
    void on_pushButton_clicked();//定义消息发送按钮

signals:
    void sendGameReadyMessage(void);//定义向服务器发送准备就绪信号
    void sendchatMessage(QString);//发送聊天消息
private:
    Ui::RoomMainWindow *ui;
    QMovie *movie;//定义等待动画对象
};

#endif// ROOMMAINWINDOW_H
