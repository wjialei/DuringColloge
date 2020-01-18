#ifndef REGISTMAINWINDOW_H
#define REGISTMAINWINDOW_H

#include <QMainWindow>
#include <QMovie>


namespace Ui {
class RegistMainWindow;
}

class RegistMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegistMainWindow(QWidget *parent = nullptr);
    ~RegistMainWindow();

private:
    //定义键盘Esc键
    virtual void keyPressEvent(QKeyEvent *);

    //重新定义界面关闭按钮
    virtual void closeEvent(QCloseEvent * );


private slots:
    //注册按钮单击槽
    void on_RegistRegistpushButton_clicked();

    //名称：用户名注册编辑完成槽
    void on_RegistIDlineEdit_editingFinished();

    //名称：用户密码注册编辑完成槽
    void on_RegistPasswordlineEdit_editingFinished();

    //名称：用户确认密码槽
    void on_RegistAgainPasswordlineEdit_returnPressed();


signals:
    //名称：注册消息发送信号
    void sendRegistMessage(QString);
private:
    Ui::RegistMainWindow *ui;
};

#endif // REGISTMAINWINDOW_H
