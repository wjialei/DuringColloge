#include "loginmainwindow.h"
#include "ui_loginmainwindow.h"
#include "registmainwindow.h"
#include "roommainwindow.h"

#include <QMessageBox>
#include <QString>

//名称：构造函数
//描述：建立与服务器的连接，实例化所有窗口并与每个窗口建立连接
//参数：该窗口的父窗口（无）
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱、王嘉磊、王明钊
LoginMainWindow::LoginMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginMainWindow)
{
    ui->setupUi(this);
    setWindowTitle("东南大学霸");

    //与服务器建立链接
    m_tcpsocket = new QTcpSocket(this);
    m_tcpsocket->abort();
    m_tcpsocket->connectToHost("47.99.76.252",6666);

    //使用匿名函数来处理收到的消息
    connect(m_tcpsocket,
            &QTcpSocket::readyRead,
            this,
            [=](){
                QDataStream in(m_tcpsocket);
                in.setVersion(QDataStream::Qt_5_4);
                QString greeting;
                in >> greeting;
                QStringList info = greeting.split("|");

                qDebug()<<info;

                MessageJudge(info);
            }
            );

    //实例化每个窗口
    m_registWin = new RegistMainWindow();
    m_roomWin = new RoomMainWindow();
    m_gameWin = new gameWindow();

    //与每个窗口的信号建立connect
    connect(m_registWin, SIGNAL(sendRegistMessage(QString)), this, SLOT(regist(QString)));
    connect(m_roomWin, SIGNAL(sendGameReadyMessage(void)), this, SLOT(gameCreate(void)));
    connect(this, SIGNAL(sendRoundBeginMessage(int)), m_gameWin, SLOT(roundBegin(int)));
    connect(this, SIGNAL(sendName(QString)), m_gameWin, SLOT(setMyName(QString)));
    connect(m_gameWin, SIGNAL(sendDice(int)), this, SLOT(Dice(int)));
    connect(this, SIGNAL(sendDice(int)), m_gameWin, SLOT(Dice(int)));
    connect(this, SIGNAL(sendEventMessage(QStringList)), m_gameWin, SLOT(eventMessage(QStringList)));
    connect(this, SIGNAL(sendGameBeginMessage(QStringList)), m_gameWin, SLOT(gameBeginMessage(QStringList)));
    connect(m_gameWin, SIGNAL(sendEventMessage(QString)), this, SLOT(eventMessage(QString)));
    connect(m_gameWin, SIGNAL(sendRoundEnd(void)), this, SLOT(roundEnd(void)));
    connect(m_gameWin, SIGNAL(sendWinMessage(int)), this, SLOT(winMessage(int)));
    connect(m_gameWin, SIGNAL(sendLoseMessage(int)), this, SLOT(loseMessage(int)));
    connect(this, SIGNAL(sendWinMessage(int)), m_gameWin, SLOT(winMessage(int)));
    connect(this, SIGNAL(sendLoseMessage(int)), m_gameWin, SLOT(loseMessage(int)));
    connect(m_gameWin, SIGNAL(sendReturnRoom(void)), this, SLOT(returnRoom(void)));
    connect(this, SIGNAL(chatreceive(QStringList)),m_roomWin, SLOT(chatAdd(QStringList)));
    connect(m_roomWin,SIGNAL(sendchatMessage(QString)),this,SLOT(chatsender(QString)));
    connect(m_gameWin, SIGNAL(sendHouseMessage(QString)), this, SLOT(houseMessage(QString)));
    connect(this, SIGNAL(sendHouseMessage(QStringList)), m_gameWin, SLOT(houseMessage(QStringList)));

    //设置登录界面gif背景
    QMovie *movie;
    movie = new QMovie(":/image/Waved.gif");
    ui->LoginWavelabel->setMovie(movie);
    movie->start();

    //按键设置
    ui->RegistpushButton->setStyleSheet("QPushButton{border-image: url(:/image/Regist.png);}"
                                            "QPushButton:hover{border-image: url(:/image/RegistHover.png);}"
                                           "QPushButton:pressed{border-image: url(:/image/RegistPush.png);}");
    ui->LoginpushButton->setStyleSheet("QPushButton{border-image: url(:/image/Login.png);}"
                                            "QPushButton:hover{border-image: url(:/image/LoginHover.png);}"
                                           "QPushButton:pressed{border-image: url(:/image/LoginPush.png);}");

    // 设定ID只能包含有大小写字母和数字
    QRegExp  LoginIDrx("[A-Za-z0-9]+$");
    QValidator * LoginIDvalidator = new QRegExpValidator( LoginIDrx, this);
    ui->LoginIDlineEdit->setValidator(LoginIDvalidator);

    // 设定密码只能包含大小写字母、数字和下划线
    QRegExp LoginPsdrx("[A-Za-z0-9_]+$");
    QValidator * LoginPsdvalidator = new QRegExpValidator( LoginPsdrx, this);
    ui->LoginPasswordlineEdit->setValidator(LoginPsdvalidator);

}

//名称：析构函数
//描述：函数体为空
//参数：void
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
LoginMainWindow::~LoginMainWindow()
{
    delete ui;
}


//名称：发送消息函数
//描述：向服务器发送消息
//参数：Qmessage为要发送给服务器的消息，类型为QString
//返回类型：void
//作成日期：2018/9/5
//作者：周于楷
void LoginMainWindow::sendMessage(QString Qmessage)
{
     QString string = Qmessage;

     QByteArray message;
     QDataStream out(&message,QIODevice::WriteOnly);
     out.setVersion(QDataStream::Qt_5_4);
     out<<string;
     qDebug() << "cli string" << string;
     m_tcpsocket->write(message);
}

//名称：消息判断函数
//描述：选择与服务器反馈消息相应的消息处理函数（消息按发生频率从小到大排列）
//参数：info为服务器发来的消息，为QStringList类型
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::MessageJudge(QStringList info)
{
    if(info[0]=="lt")
    {
        chatreceive(info);
        return;
    }
    //回合开始
    if(info[0] == "ks")
    {
        //将服务器传来的当前回合的ID传给游戏窗口
        sendRoundBeginMessage(info[1].toInt());
        return;
    }

    //骰子点数
    if(info[0] == "sz")
    {
        //将骰子点数传给游戏窗口
        sendDice(info[1].toInt());
        return;
    }

    //事件
    if(info[0] == "sj")
    {
        //将事件消息传给游戏窗口
        sendEventMessage(info);
        return;
    }

    //购买地产
    if(info[0] == "gm")
    {
        //将地产消息传给游戏窗口
        sendHouseMessage(info);
        return;
    }

    //注册
    if(info[0] == "zc")
    {
        RegistrationFeedback(info);
        return;
    }

    //创建游戏
    if(info[0] == "cj")
    {
        CreateFeedback(info);
        return;
    }

    //上线
    if(info[0] == "sx")
    {
        LoginFeedback(info);
        return;
    }

    //失败
    if(info[0] == "tc")
    {
        LoseFeedback(info);
        return;
    }

    //获胜
    if(info[0] == "hs")
    {
        WinFeedback(info);
        return;
    }
}

//名称：登陆反馈消息处理函数
//描述：处理服务器传来的登陆反馈消息
//参数：info为服务器发来的消息，为QStringList类型
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::LoginFeedback(QStringList info)
{
    if(info[1].toInt())
    {
        //登陆成功则跳转到房间界面
        m_roomWin->show();

        //发送当前用户
        sendName(m_user);

        //隐藏主窗口
        this->hide();
    }
    else
    {
        QMessageBox::critical(nullptr, "Error!", "登陆失败！", QMessageBox::Ok, QMessageBox::Ok);

        //登陆失败则删去当前用户，重新登录
        m_user = nullptr;
    }
}

//名称：注册反馈消息处理函数
//描述：处理服务器传来的注册反馈消息
//参数：info为服务器发来的消息，为QStringList类型
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::RegistrationFeedback(QStringList info)
{
    if(info[1].toInt())
    {
        QMessageBox::information(nullptr, "Success!", "注册成功！", QMessageBox::Ok, QMessageBox::Ok);
        m_registWin->close();
    }
    else
    {
        QMessageBox::critical(nullptr, "Error!", "注册失败！", QMessageBox::Ok, QMessageBox::Ok);
    }
}

//名称：创建反馈消息处理函数
//描述：处理服务器传来的游戏创建反馈消息
//参数：info为服务器发来的消息，为QStringList类型
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::CreateFeedback(QStringList info)
{
    //显示游戏窗口
    m_gameWin->show();

    //将游戏创建消息传送给游戏窗口
    sendGameBeginMessage(info);

    //关闭房间界面
    m_roomWin->close();
}

//名称：游戏获胜反馈消息处理函数
//描述：处理服务器传来的游戏获胜反馈消息
//参数：info为服务器发来的消息，为QStringList类型
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::WinFeedback(QStringList info)
{
    //将游戏胜利的ID发给游戏窗口
    sendWinMessage(info[1].toInt());
}

//名称：游戏失败反馈消息处理函数
//描述：处理服务器传来的游戏失败反馈消息
//参数：info为服务器发来的消息，为QStringList类型
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::LoseFeedback(QStringList info)
{
    //将失败的ID传给游戏窗口
    sendLoseMessage(info[1].toInt());
}



//名称：注册按钮槽函数
//描述：槽函数，点击注册按钮后显示注册窗口
//参数：void
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::on_RegistpushButton_clicked()
{
    //显示注册窗口
    m_registWin->show();
}

//名称：登陆按钮槽函数
//描述：槽函数，将密码加密后与账号一起发送给服务器验证
//参数：void
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱、王嘉磊
void LoginMainWindow::on_LoginpushButton_clicked()
{
    //登录密码加密
    QByteArray LoginPsd;
    LoginPsd = QCryptographicHash::hash(ui->LoginPasswordlineEdit->text().toLatin1(),QCryptographicHash::Md5);    

    //发送账号密码给服务器验证
    QString message="dl|"+ui->LoginIDlineEdit->text()+"|"+LoginPsd.toHex();
    sendMessage(message);

    //保存当前用户的账号
    m_user = ui->LoginIDlineEdit->text();
}

//名称：回车键实现登录函数
//描述：让用户输入完成密码后可按下回车键实现登陆
//参数：void
//返回类型：void
//作成日期：2018/9/5
//作者：王嘉磊
void LoginMainWindow::on_LoginPasswordlineEdit_returnPressed()
{
    on_LoginpushButton_clicked();
}



//名称：注册消息发送函数
//描述：槽函数，接受注册窗口发来的信号，并发送注册消息给服务器
//参数：message为从注册窗口发来的信号，类型为QString
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::regist(QString message)
{
    sendMessage(message);
}

//名称：游戏创建消息发送函数
//描述：槽函数，接受房间窗口传来的信号，并发送游戏创建消息给服务器
//参数：void
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::gameCreate(void)
{
    QString message = "cj|" + m_user;
    sendMessage(message);
}

//名称：骰子点数发送函数
//描述：槽函数，接受游戏窗口传来的骰子数，并传给服务器
//参数：r为游戏窗口传来的骰子点数，为int类型
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::Dice(int r)
{
    //把r以十进制的形式转化为QString
    sendMessage("sz|" + QString::number(r));
}

//名称：事件消息发送函数
//描述：槽函数，接受游戏窗口传来的事件消息，并传给服务器
//参数：message为从注册窗口发来的信号，类型为QString
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::eventMessage(QString message)
{
    sendMessage(message);
}

//名称：地产消息发送函数
//描述：槽函数，接受游戏窗口传来的地产消息，并传给服务器
//参数：message为从注册窗口发来的信号，类型为QString
//返回类型：void
//作成日期：2018/9/8
//作者：胡昱
void LoginMainWindow::houseMessage(QString message)
{
    sendMessage(message);
}

//名称：回合结束消息发送函数
//描述：槽函数，接受游戏窗口传来的回合结束消息，并传给服务器
//参数：void
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::roundEnd(void)
{
    sendMessage("js");
}

//名称：游戏获胜消息发送函数
//描述：槽函数，接受游戏窗口传来的游戏获胜消息，并传给服务器
//参数：id为游戏窗口传来的获胜的角色ID，为int类型
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::winMessage(int id)
{
    sendMessage("hs|" + QString::number(id));
}

//名称：游戏失败消息发送函数
//描述：槽函数，接受游戏窗口传来的游戏失败消息，并传给服务器
//参数：id为游戏窗口传来的失败的角色ID，为int类型
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::loseMessage(int id)
{
    sendMessage("tc|" + QString::number(id));
}

//名称：重启房间窗口函数
//描述：槽函数，接受重启房间窗口信息，重新打开房间窗口
//参数：void
//返回类型：void
//作成日期：2018/9/5
//作者：胡昱
void LoginMainWindow::returnRoom(void)
{
    delete m_roomWin;
    m_roomWin = new RoomMainWindow;
    m_roomWin->show();
}




//名称：光标转移函数2
//描述：密码输入完成后光标转到登录按钮上
//参数：void
//返回类型：void
//作成日期：2018/9/5
//作者：王嘉磊
void LoginMainWindow::on_LoginPasswordlineEdit_editingFinished()
{
    ui->LoginpushButton->setFocus();
}

//名称：光标转移函数1
//描述：用户名输入完成后光标移至输入密码框内
//参数：void
//返回类型：void
//作成日期：2018/9/5
//作者：王嘉磊
void LoginMainWindow::on_LoginIDlineEdit_editingFinished()
{
    ui->LoginPasswordlineEdit->setFocus();
}

//名称：聊天消息发送函数
//描述：发送聊天消息
//参数：QString
//返回类型：void
//作成日期：2018/9/10
//作者：周于楷
void LoginMainWindow::chatsender(QString message)
{
    message="lt|"+m_user+"|"+message;
    sendMessage(message);
}

