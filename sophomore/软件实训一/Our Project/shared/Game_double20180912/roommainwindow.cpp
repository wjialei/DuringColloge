#include "roommainwindow.h"
#include "ui_roommainwindow.h"

//名称：注册窗口构造函数
//描述：用于注册窗口的建立
//作成日期：2018/9/1
//参数：QWeight
//返回值类型：void
//作者：王明钊
RoomMainWindow::RoomMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomMainWindow)
{
     ui->setupUi(this);

     //改变窗口名称
     setWindowTitle("东南大学霸");

     //隐藏等待文本
     this->ui->RoomCominglabel->hide();

     //进入房间后光标定位在Study
     ui->RoomPlaypushButton->setFocus();
     //将房间界面的Study按钮与回车键连接
     ui->RoomPlaypushButton->setShortcut(Qt::Key_Return);

      //将gif对象赋给movie
      movie = new QMovie(":/image/stay.gif");

      //对房间窗口背景进行设置
      QMovie *moviea;
      moviea = new QMovie(":/image/PassageWay.gif");
      ui->RoomPassageWaylabel->setMovie(moviea);
      moviea->start();

      //按键背景设置，实现按钮三态
      ui->RoomPlaypushButton->setStyleSheet("QPushButton{border-image: url(:/image/Study.png);}"
                                              "QPushButton:hover{border-image: url(:/image/StudyHover.png);}"
                                             "QPushButton:pressed{border-image: url(:/image/StudyPush.png);}");
}

RoomMainWindow::~RoomMainWindow()
{
    delete ui;
}

//名称：游戏开始按钮单机槽
//描述：用于发送游戏开始的信息
//作成日期：2018/9/1
//参数：void
//返回值类型：void
//作者：王明钊
void RoomMainWindow::on_RoomPlaypushButton_clicked()
{
    //发送游戏创建消息给主窗口
    sendGameReadyMessage();

    //显示等待动画，隐藏开始按钮
    this->ui->RoomLoadinglabel->setMovie(movie);
    movie->start();
    this->ui->RoomCominglabel->show();
    this->ui->RoomPlaypushButton->hide();
}

//名称：聊天消息显示函数
//描述：显示聊天消息
//作成日期：2018/9/10
//参数：QStringList
//返回值类型：void
//作者：周于楷
void RoomMainWindow::chatAdd(QStringList info)
{
    ui->textBrowser->append(tr("'%1' say :").arg(info[1]));
    ui->textBrowser->append(tr("	'%1'").arg(info[2]));
}


//名称：消息发送按钮单击槽
//描述：用于发送聊天开始的信息
//作成日期：2018/9/10
//参数：void
//返回值类型：void
//作者：周于楷
void RoomMainWindow::on_pushButton_clicked()
{
    sendchatMessage(ui->senderLine->text());
    ui->senderLine->clear();
}
