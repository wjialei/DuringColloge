#include "loginmainwindow.h"
#include "control.h"
#include <QApplication>
#include <QPainter>
#include <QTime>
#include <QMessageBox>
#include <QDebug>
#include <QDesktopWidget>

//名称：构造函数
//描述：初始化地图，人物，按钮，标签
//参数：void
//返回类型：void
//作成日期：2018/9/9
//作者：郑雅璐
gameWindow::gameWindow():
    //初始化按钮，标签
    throwButton("",this),
    credictLabel(tr("学分"),this),
    dateLabel(tr("日期"),this),
    credictStatusLabel(this),
    dateStatusLabel(this),
    showNumberLabel(this),

    //设置绘画区域
    //设置绘画游戏大地图矩形区域
    Paint(10,10,1500,1000),
    //设置绘画小地图矩形区域，缩小比例（3.8,3.7）
    Paint1(1520,680,390,270),

    //设置偏移量
    Alloffset(0,0)
{
    //设置大地图尺寸
    pixW = 4857;
    pixH = 3372;
    //加载大地图
    pix = new QPixmap;
    pix->load(":/image/map.png");
    //加载小地图
    pixx = new QPixmap;
    pixx->load(":/image/maps.png");

    //初始化每个角色的图片
    players = new CPlayer[2];
    players[0].setAppearance(QPixmap(":/image/xm.png"));
    players[1].setAppearance(QPixmap(":/image/xlm.png"));

    //设置按钮，标签的位置，大小
    throwButton.setGeometry(1550,160,150,150);
    credictLabel.setGeometry(1550,40,80,35);
    dateLabel.setGeometry(1550,100,80,35);
    credictStatusLabel.setGeometry(1700,40,200,35);
    dateStatusLabel.setGeometry(1700,100,200,35);
    showNumberLabel.setGeometry(1750,160,150,150);

    //设置标签字体
    QFont zt("华文行楷",20);
    credictLabel.setFont(zt);
    dateLabel.setFont(zt);
    credictStatusLabel.setFont(zt);
    dateStatusLabel.setFont(zt);
    showNumberLabel.setFont(zt);

    //设置标签边框
    credictStatusLabel.setFrameShape(QFrame::Box);
    dateStatusLabel.setFrameShape(QFrame::Box);
    showNumberLabel.setFrameShape(QFrame::Box);

    //设置掷骰子按钮背景
    throwButton.setStyleSheet(tr("background-image: url(:/image/throw.jpg);"));

    //设置状态标签文本内容
    credictStatusLabel.setText(tr(""));
    dateStatusLabel.setText(tr(""));
    showNumberLabel.setText(tr(""));

    //点击掷骰子按钮，信号与槽连接
    connect(&throwButton,SIGNAL(clicked()),this,SLOT(throwDice()));

    //初始化动作状态
    action = gameWindow::None;

    //调节gameWindow（总窗口）大小
    //自适应窗口分辨率
    int currentScreenWid = QApplication::desktop()->width();
    int currentScreenHei  = QApplication::desktop()->height();
    resize(currentScreenWid,currentScreenHei);

}

//名称：事件函数
//描述：当鼠标按下时获取鼠标坐标，改变偏移量，随之改变图片坐标，实现图片的移动
//参数：鼠标事件
//返回类型：bool
//作成日期：2018/9/9
//作者：郑雅璐
bool gameWindow::event(QEvent * event)
{
    //初始化坐标点，默认鼠标没有按下
    static bool press=false;
    static QPoint PreDot;

    //鼠标事件
    if(event->type() == QEvent::MouseButtonPress )
    {
           //强制转换为鼠标事件
           QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);

           //判断鼠标是否是左键按下,且鼠标位置是否在绘画区域
           if(mouse->button()==Qt::LeftButton &&Paint.contains(mouse->pos()))
           {
               press=true;
               //设置鼠标样式
               QApplication::setOverrideCursor(Qt::OpenHandCursor);
               //获取鼠标坐标
               PreDot = mouse->pos();
           }

    }
    else if(event->type() == QEvent::MouseButtonRelease)
   {
           QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);

           //判断鼠标是否是左键释放,且之前是在绘画区域
          if(mouse->button()==Qt::LeftButton && press )
          {
                //改回鼠标样式
                QApplication::setOverrideCursor(Qt::ArrowCursor);
                press=false;
           }
    }

    //移动图片
    if(event->type() == QEvent::MouseMove)
    {
          if(press)
          {
              //强制转换鼠标事件
               QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);

               //设置偏移量
               offset.setX(mouse->x() - PreDot.x());
               offset.setY(mouse->y() - PreDot.y());
               //获取坐标点
               PreDot = mouse->pos();
               //设置动作状态
               action = gameWindow::Move;
               //更新窗口
               this->update();
           }
     }
     return QWidget::event(event);
}

//名称：绘画事件函数
//描述：绘制地图及人物
//参数：绘画事件
//返回类型：void
//作成日期：2018/9/9
//作者：郑雅璐
void gameWindow::paintEvent(QPaintEvent *event)
{
  //声明画家
  QPainter painter(this);

  //当前图片大小
  int NowW = pixW;
  int NowH = pixH;

  //当动作为移动时
  if(action==gameWindow::Move)
  {
      //设置x偏移量
     int offsetx=Alloffset.x()+offset.x();
     Alloffset.setX(offsetx);

     //设置y偏移量
     int offsety=Alloffset.y()+offset.y();
     Alloffset.setY(offsety);

     action=gameWindow::None;
  }

  //限制X偏移值
  if(abs(Alloffset.x())>=(Paint.width()/2 + NowW/2 -10))
  {
     if(Alloffset.x()>0)
        Alloffset.setX(Paint.width()/2 + NowW/2 -10);
     else
        Alloffset.setX(-Paint.width()/2 + -NowW/2 +10);
  }

  //限制Y偏移值
  if(abs(Alloffset.y())>=(Paint.height()/2 + NowH/2 -10))
  {
     if(Alloffset.y()>0)
         Alloffset.setY(Paint.height()/2 + NowH/2 -10);
     else
         Alloffset.setY(-Paint.height()/2 + -NowH/2 +10);
  }

  //设置地图位于矩形框内的x坐标
  int x = Paint.width()/2 + Alloffset.x() -NowW/2;
  if(x<0)
     x=0;
  //设置地图位于矩形框内的y坐标
  int y = Paint.height()/2 + Alloffset.y() -NowH/2;
  if(y<0)
     y=0;

  //设置地图相对于矩形框左上角x坐标变化
  int sx = NowW/2 - Paint.width()/2 - Alloffset.x();
  if(sx<0)
     sx=0;
  //设置地图相对于矩形框左上角y坐标变化
  int sy = NowH/2 - Paint.height()/2 - Alloffset.y();
  if(sy<0)
     sy=0;

  //设置地图宽度
  int w =(NowW - sx)>Paint.width()? Paint.width() : (NowW - sx);
  if(w>(Paint.width()-x))
      w = Paint.width()-x;
  //设置地图高度
  int h =(NowH - sy)>Paint.height()? Paint.height() : (NowH - sy);
  if(h>(Paint.height()-y))
      h = Paint.height()-y;

  //画大地图
  //画大矩形框
  painter.drawRect(Paint.x()-1,Paint.y()-1,Paint.width()+1,Paint.height()+1);
  //画大地图
  painter.drawTiledPixmap(x+Paint.x(),y+Paint.y(),w,h,*pix,sx,sy);

  //画小地图
  //画小矩形框
  painter.drawRect(Paint1.x()-1,Paint1.y()-1,Paint1.width()+1,Paint1.height()+1);
  //画小地图
  painter.drawTiledPixmap(Paint1.x(),Paint1.y(),Paint1.width(),Paint1.height(),*pixx,0,0);

  //画人物
  for(int i = 0; i<2; ++i)
      painter.drawPixmap(Alloffset.x() + players[i].getPoint().rx() + 140, Alloffset.y() + players[i].getPoint().ry() + 320, players[i].getAppearance());

}

//名称：掷骰子函数
//描述：点击骰子按钮，进行掷骰子
//参数：void
//返回类型：void
//作成日期：2018/9/8
//作者：胡昱
void gameWindow::throwDice(void)
{
    //判断当前是自己的回合吗
    if(players[m_nowID].getName() == m_myName)
    {
        int r = roll(6);

        sendDice(r);
    }
    else
    {
        QMessageBox * msgbox = new QMessageBox(QMessageBox::Critical,tr(""),tr("还在上课呢，别乱动！"));
        msgbox->setStandardButtons(0);
        QTimer::singleShot(1000,msgbox,SLOT(accept()));
        msgbox->exec();
        delete msgbox;
    }
}

//名称：确定当前游戏用户函数
//描述：接受主窗口传来的本机用户的账号
//参数：QString
//返回类型：void
//作成日期：2018/9/8
//作者：胡昱
void gameWindow::setMyName(QString n)
{
    m_myName = n;
}

//名称：初始化游戏对象
//描述：接受主窗口传来的游戏开始的消息
//参数：QStringList
//返回类型：void
//作成日期：2018/9/8
//作者：胡昱
void gameWindow::gameBeginMessage(QStringList info)
{
    //初始化每个角色
    players[0].setName(info[1]);
    players[1].setName(info[2]);

    //初始化游戏日期
    m_data = 1;
}

//名称：初始化游戏对象
//描述：接受主窗口传来的事件消息
//参数：QStringList
//返回类型：void
//作成日期：2018/9/8
//作者：胡昱
void gameWindow::eventMessage(QStringList info)
{
    //检测当前是否是本机角色回合
    bool isMe = (players[m_nowID].getName() == m_myName);
    bool result=true;
    //寻找事件消息相应的事件处理函数
    int i = 0;
    for(; i<g_numOfEvents; ++i)
    {
        if(sj[i]->getID() == info[2])
        {
            result = sj[i]->process(players[info[1].toInt()], isMe);

            //若result是false且说明本机购买地产了，需告知其他角色
            if(!result)
            {
                sendHouseMessage("gm|" + QString::number(m_nowID) + "|" + ((CHouseEvent*)sj[i])->getHouseName());
                return;
            }

            break;
        }
    }

    //发生事件后更新学分
    credictStatusLabel.setText(QString::number(players[m_nowID].getCredit()));

    //判断当前是自己的回合吗，若是:先检测是否获胜或者失败，若正常游戏，则发送回合结束消息
    if(isMe&&result)
    {
        //若获胜
        if(players[m_nowID].getCredit() >= 80)
        {
            //发送获胜消息给主窗口
            sendWinMessage(m_nowID);
        }
        else
        {
            //若失败
            if(players[m_nowID].getCredit() < 20)
            {
                //发送失败消息给主窗口
                sendLoseMessage(m_nowID);
            }
            //若正常游戏
            else
            {
                //停留3s
                QEventLoop eventloop;
                QTimer::singleShot(3000, &eventloop, SLOT(quit()));
                eventloop.exec();

                //发送回合结束消息给主窗口，游戏日期加一
                qDebug()<<"js1";
                sendRoundEnd();
                ++m_data;
            }
        }

    }
}

//名称：接受回合ID函数
//描述：接受主窗口传来的当前回合ID
//参数：i为当前回合的ID，类型为int
//返回类型：void
//作成日期：2018/9/9
//作者：胡昱
void gameWindow::roundBegin(int i)
{
    //设置当前回合的角色ID
    m_nowID = i;

    //显示当前角色的学分
    credictStatusLabel.setText(QString::number(players[m_nowID].getCredit()));

    //显示游戏日期
    dateStatusLabel.setText("第" + QString::number(m_data/7) + "周  第" + QString::number(m_data%7) + "天");

    //检测当前角色可不可以行动
    if(players[m_nowID].getFatigueValue() == 0)
    {
        //若当前角色可以行动，则判断当前是自己的回合吗
        if(players[m_nowID].getName() == m_myName)
        {
            QMessageBox * msgbox = new QMessageBox(QMessageBox::Information, tr(""), tr("下课啦！请掷骰子！"));
            msgbox->setStandardButtons(0);
            QTimer::singleShot(1000,msgbox,SLOT(accept()));
            msgbox->exec();
            delete msgbox;
        }
        else
        {
            QMessageBox * msgbox = new QMessageBox(QMessageBox::Information, tr(""), QString::number(m_nowID) + "号下课啦！看他表演吧！");
            msgbox->setStandardButtons(0);
            QTimer::singleShot(1000,msgbox,SLOT(accept()));
            msgbox->exec();
            delete msgbox;
        }
    }
    //若不可以行动
    else
    {
        //若是本机角色的回合
        if(players[m_nowID].getName() == m_myName)
        {
            //提示你还需休息几天
            QMessageBox * msgbox = new QMessageBox(QMessageBox::Critical, tr(""), "你还需休息" + QString::number(players[m_nowID].getFatigueValue()) + "天！");
            msgbox->addButton(QMessageBox::Ok);
            msgbox->button(QMessageBox::Ok)->hide();
            QTimer::singleShot(2000,msgbox,SLOT(accept()));
            msgbox->exec();
            delete msgbox;

            //发送回合结束消息给主窗口，游戏日期加一
            sendRoundEnd();
            ++m_data;

        }
        else
        {
            //提示该角色还需休息几天
            QMessageBox * msgbox = new QMessageBox(QMessageBox::Critical, tr(""), QString::number(m_nowID) + "号还需休息" + QString::number(players[m_nowID].getFatigueValue()) + "天！");
            msgbox->addButton(QMessageBox::Ok);
            msgbox->button(QMessageBox::Ok)->hide();
            QTimer::singleShot(2000,msgbox,SLOT(accept()));
            msgbox->exec();
            delete msgbox;
        }

        //扣除一点疲劳值
        players[m_nowID].addFatigueValue(-1);
    }
}

//名称：接受骰子点数函数
//描述：接受主窗口传来的此回合的骰子点数
//参数：r为主窗口传来的骰子点数,为int类型
//返回类型：void
//作成日期：2018/9/8
//作者：胡昱
void gameWindow::Dice(int r)
{
    //显示骰子点数
    showNumberLabel.setText(QString::number(r));

    //当前角色移动
    move(r);

    qDebug()<<"move over";

    //判断当前是自己的回合吗，若是则需要判断事件
    if(players[m_nowID].getName() == m_myName)
    {
        //从当前点包含的事件中随机抽取一件
        int e = roll((players[m_nowID].getPoint()).getNumOfEvents());

        //将此事件序号传给主窗口
        QString eventName = (players[m_nowID].getPoint()).getEventName(e);
        sendEventMessage("sj|" + QString::number(m_nowID) + "|" + eventName);
    }


}

//名称：接受购买地产消息函数
//描述：接受主窗口传来的购买地产消息
//参数：info为主窗口传来的购买地产消息，为QStringList类型
//返回类型：void
//作成日期：2018/9/8
//作者：胡昱
void gameWindow::houseMessage(QStringList info)
{
    //若购买者为自己
    if(players[m_nowID].getName() == m_myName)
    {
        //购买相应的地产
        for(int i = 0; i<g_numOfhouses; ++i)
        {
            if(houses[i]->getName() == info[2])
            {
                //扣除相应学分
                houses[i]->setOwner(players[info[1].toInt()]);
                players[info[1].toInt()].addCredit(-houses[i]->getPrice());

                //提示
                QMessageBox * msgbox = new QMessageBox(QMessageBox::Information, "", "您成功购买了" + houses[i]->getName());
                msgbox->addButton(QMessageBox::Ok);
                msgbox->button(QMessageBox::Ok)->hide();
                QTimer::singleShot(2500,msgbox,SLOT(accept()));
                msgbox->exec();
                delete msgbox;
            }
        }

        //发送回合结束消息
        qDebug()<<"js1";
        sendRoundEnd();
    }
    //若购买者为其他角色
    else
    {
        //购买相应的地产
        for(int i = 0; i<g_numOfhouses; ++i)
        {
            if(houses[i]->getName() == info[2])
            {
                //扣除相应学分
                houses[i]->setOwner(players[info[1].toInt()]);
                players[info[1].toInt()].addCredit(-houses[i]->getPrice());

                //提示
                QMessageBox * msgbox = new QMessageBox(QMessageBox::Information, "", info[1] + "号购买了" + houses[i]->getName());
                msgbox->addButton(QMessageBox::Ok);
                msgbox->button(QMessageBox::Ok)->hide();
                QTimer::singleShot(1000,msgbox,SLOT(accept()));
                msgbox->exec();
                delete msgbox;
            }
        }
    }
}

//名称：接受获胜消息函数
//描述：接受主窗口传来的游戏获胜消息
//参数：id为获胜角色的id，类型为int
//返回类型：void
//作成日期：2018/9/9
//作者：胡昱
void gameWindow::winMessage(int id)
{
    //显示胜利消息
    QMessageBox message(QMessageBox::NoIcon, "录取通知书", "恭喜" + QString::number(id) + "号同学在千军万马中顺利毕业，喜提毕业证书！");
    message.setIconPixmap(QPixmap(":/image/graduate.jpg"));
    message.exec();

    //关闭游戏窗口
    this->close();

    //发送消息给主窗口重新打开房间窗口
    sendReturnRoom();
}

//名称：接受失败消息函数
//描述：接受主窗口传来的游戏失败消息
//参数：id为获胜角色的id，类型为int
//返回类型：void
//作成日期：2018/9/9
//作者：胡昱
void gameWindow::loseMessage(int id)
{
    //显示失败消息
    QMessageBox message(QMessageBox::NoIcon, "退学通知书", QString::number(id) + "号同学沉迷游戏无法自拔，几乎挂掉所有科目，被强制退学了！！！");
    message.exec();

    //若是本机失败，则关闭游戏窗口，并返回房间界面
    if(players[id].getName() == m_myName)
    {
        this->close();
        sendReturnRoom();
    }
    //若是其他角色失败，则将其外观设为空白
    else
    {
        players[id].setAppearance(QPixmap());
    }
}

//名称：角色移动的函数
//描述：负责角色移动
//参数：r为需要走几步，为int类型
//返回类型：void
//作成日期：2018/9/10
//作者：胡昱
void gameWindow::move(int r)
{

    for(int i = 0; i < r; ++i)
    {
        //因地图路径设置不合理，人物行至p47与p55时需进行特殊处理
        //行至p55时
        if((players[m_nowID].getPoint().rx() == 208) && (players[m_nowID].getPoint().ry() == 93))
        {
            players[m_nowID].setPoint(p0);
        }
        else
        {
            //行至p47时
            if((players[m_nowID].getPoint().rx() == 502) && (players[m_nowID].getPoint().ry() == 993))
            {
                //偶数则转弯
                if((r%2) == 0)
                {
                    players[m_nowID].setPoint(p48);
                }
                //奇数则直行
                else
                {
                    players[m_nowID].setPoint(p70);
                }
            }
            //行至其他点
            else
            {
                //判断是否为三叉点
                if((players[m_nowID].getPoint()).isBranch())
                {
                    //偶数则转弯
                    if((r%2) == 0)
                    {
                        players[m_nowID].setPoint(*(((players[m_nowID].getPoint())).m_turn));
                    }
                    //奇数则直行
                    else
                    {
                        players[m_nowID].setPoint(*(((players[m_nowID].getPoint())).m_next));
                    }
                }
                //若不是三叉点则直行
                else
                {
                    players[m_nowID].setPoint(*(((players[m_nowID].getPoint())).m_next));
                }
            }
        }


        //绘图
        this->update();

        //每走一步停留0.5s
        QEventLoop eventloop;
        QTimer::singleShot(500, &eventloop, SLOT(quit()));
        eventloop.exec();
    }
}



