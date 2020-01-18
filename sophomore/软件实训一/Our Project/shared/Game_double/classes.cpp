#include "classes.h"
#include <QString>
#include <QMessageBox>
#include <QTimer>
#include "control.h"


/**************坐标点类**************/
//名称：构造函数
//描述：函数体为空
//参数：x坐标，y坐标，事件数，事件数组，是否为三叉点，直行的下一个点，转弯的下一个点
//返回类型：void
//作成日期：2018/9/3
//作者：王嘉磊
CPoint::CPoint(int x, int y, int num, CEvent* *e, bool is, CPoint* n, CPoint* t)
:QPoint(x, y), m_numOfEvents(num), m_events(e), m_next(n), m_turn(t), m_isBranchPoint(is)
{

}

//名称：默认构造函数
//描述：初始化数据成员
//参数：void
//返回类型：void
//作成日期：2018/9/3
//作者：王嘉磊
CPoint::CPoint():QPoint(0, 0)
{
    m_next = nullptr;
    m_turn = nullptr;
    m_events = nullptr;
    m_numOfEvents = 0;
}

//名称：拷贝构造函数
//描述：防止拷贝中数据丢失
//参数：要拷贝的对象p
//返回类型：void
//作成日期：2018/9/8
//作者：胡昱
CPoint::CPoint(CPoint & p)
{
    this->setX(p.rx());
    this->setY(p.ry());
    m_numOfEvents = p.m_numOfEvents;
    m_isBranchPoint = p.m_isBranchPoint;
    m_events = p.m_events;
    m_next = p.m_next;
    m_turn = p.m_turn;
}

//名称：析构函数
//描述：函数体为空
//参数：void
//返回类型：void
//作成日期：2018/9/3
//作者：王嘉磊
CPoint::~CPoint()
{

}

//名称：返回事件个数函数
//描述：返回某点包含的事件个数
//参数：void
//返回类型：int
//作成日期：2018/9/3
//作者：胡昱
int CPoint::getNumOfEvents(void) const
{
    return m_numOfEvents;
}

//名称：返回事件ID函数
//描述：返回值为该事件的ID
//参数：参数为事件序号，为int&类型
//返回类型：QString
//作成日期：2018/9/3
//作者：胡昱
QString CPoint::getEventName(int & e) const
{
    return m_events[e-1]->getID();
}

//名称：设置下一个点函数
//描述：设置直行的下一个点
//参数：要设置成下一个点的点，类型为CPoint *
//返回类型：int
//作成日期：2018/9/5
//作者：王嘉磊
void CPoint::setNext(CPoint * n)
{
    m_next = n;
}

//名称：判断三叉点函数
//描述：判断该点是不是三叉点
//参数：void
//返回类型：bool
//作成日期：2018/9/3
//作者：王嘉磊
bool CPoint::isBranch(void) const
{
    return m_isBranchPoint;
}

/**************玩家类**************/
//名称：构造函数
//描述：初始化所有数据成员
//参数：角色的名称（即账号），类型为QString &
//返回类型：void
//作成日期：2018/9/3
//作者：胡昱
CPlayer::CPlayer(QString & n):m_name(n), m_location(p0), m_appearance(":/image/xm.png")
{
    //初始化疲劳值为0
    m_fatigueValue = 0;

    //初始化学分为100
    m_credit = 50;
}

//名称：默认构造函数
//描述：初始化所有数据成员
//参数：void
//返回类型：void
//作成日期：2018/9/3
//作者：胡昱
CPlayer::CPlayer(void):m_name(""), m_location(p0), m_appearance(":/image/xm.png")
{
    //初始化疲劳值为0
    m_fatigueValue = 0;

    //初始化学分为100
    m_credit = 50;
}

//名称：析构函数
//描述：函数体为空
//参数：void
//返回类型：void
//作成日期：2018/9/3
//作者：胡昱
CPlayer::~CPlayer()
{

}

//名称：设置名称函数
//描述：设置角色的名称（即账号）
//参数：n为要传入的角色的名称，类型为QString
//返回类型：void
//作成日期：2018/9/3
//作者：胡昱
void CPlayer::setName(QString n)
{
    m_name = n;
}

//名称：返回角色名称函数
//描述：返回角色名称，为const函数
//参数：void
//返回类型：QString
//作成日期：2018/9/3
//作者：胡昱
QString CPlayer::getName(void) const
{
    return m_name;
}

//名称：返回角色学分函数
//描述：返回角色学分，为const函数
//参数：void
//返回类型：int
//作成日期：2018/9/3
//作者：胡昱
int CPlayer::getCredit(void) const
{
    return m_credit;
}

//名称：加学分函数
//描述：给角色加学分
//参数：参数c为要加减的学分，类型为int &
//返回类型：void
//作成日期：2018/9/3
//作者：胡昱
void CPlayer::addCredit(int c)
{
    m_credit += c;
}

//名称：返回疲劳值函数
//描述：返回角色疲劳值，为const函数
//参数：void
//返回类型：int
//作成日期：2018/9/3
//作者：胡昱
int CPlayer::getFatigueValue(void) const
{
    return m_fatigueValue;
}

//名称：加疲劳值函数
//描述：给角色加疲劳值
//参数：参数c为要加上的疲劳值，类型为int &
//返回类型：void
//作成日期：2018/9/3
//作者：胡昱
void CPlayer::addFatigueValue(int c)
{
    m_fatigueValue += c;
}

//名称：返回角色所在点函数
//描述：返回角色当前所在的点
//参数：void
//返回类型：CPoint
//作成日期：2018/9/3
//作者：胡昱
CPoint CPlayer::getPoint(void)
{
    return m_location;
}

//名称：设置角色所在点函数
//描述：重新设置角色当前所在的点，实现角色移动
//参数：参数p为要前往的点，类型为CPoint
//返回类型：void
//作成日期：2018/9/3
//作者：胡昱
void CPlayer::setPoint(CPoint p)
{
    m_location = p;
}

//名称：设置角色外观函数
//描述：重新设置角色外观
//参数：参数pm为新的角色外观，类型为QPixmap
//返回类型：void
//作成日期：2018/9/3
//作者：胡昱
void CPlayer::setAppearance(QPixmap pm)
{
    m_appearance = pm;
}

//名称：返回角色外观函数
//描述：返回角色外观
//参数：void
//返回类型：QPixmap
//作成日期：2018/9/3
//作者：胡昱
QPixmap CPlayer::getAppearance(void) const
{
    return m_appearance;
}


/**************地产类**************/
//名称：构造函数
//描述：初始化所有数据成员
//参数：参数分别为地产名称（name）、包含每个等级对应的过路费的数组（arr）、地产的价格（p）
//     类型分别为QString，int *，int &
//返回类型：void
//作成日期：2018/9/3
//作者：王明钊
CHouse::CHouse(QString name, const int p):m_name(name), m_owner(nullptr), m_price(p), m_fee(p/2)
{

}

//名称：析构函数
//描述：函数体为空
//参数：void
//返回类型：void
//作成日期：2018/9/3
//作者：王明钊
CHouse::~CHouse(void)
{

}

//名称：返回过路费函数
//描述：返回当前等级的过路费
//参数：void
//返回类型：int
//作成日期：2018/9/3
//作者：王明钊
int CHouse::getFee(void) const
{
    return m_fee;
}

//名称：返回地产名称函数
//描述：返回地产的名称
//参数：void
//返回类型：QString
//作成日期：2018/9/3
//作者：王明钊
QString CHouse::getName(void) const
{
    return m_name;
}

//名称：返回地产价格函数
//描述：返回地产的价格
//参数：void
//返回类型：int
//作成日期：2018/9/3
//作者：王明钊
int CHouse::getPrice(void) const
{
    return m_price;
}

//名称：设置地产拥有者函数
//描述：重新设置该地产的拥有者
//参数：参数owner为新的地产拥有者，类型为CPlayer &
//返回类型：void
//作成日期：2018/9/3
//作者：王明钊
void CHouse::setOwner(CPlayer &owner)
{
    m_owner = &owner;
}

//名称：返回地产拥有者函数
//描述：返回地产当前的拥有者
//参数：void
//返回类型：CPlayer *
//作成日期：2018/9/3
//作者：王明钊
CPlayer* CHouse::getOwner(void) const
{
    return m_owner;
}



/**************事件类**************/
//抽象基类
//名称：构造函数
//描述：函数体为空
//参数：id为事件序号，类型为QString；content为事件内容，类型为QString
//返回类型：void
//作成日期：2018/9/4
//作者：胡昱
CEvent::CEvent(QString id, QString content): m_id(id), m_content(content)
{

}

//名称：析构函数
//描述：函数体为空
//参数：void
//返回类型：void
//作成日期：2018/9/4
//作者：胡昱
CEvent::~CEvent()
{

}

//名称：事件处理函数
//描述：虚函数，显示事件的序号、内容
//参数：p为触发该事件的角色，类型为CPlayer &
//返回类型：bool
//作成日期：2018/9/4
//作者：胡昱
bool CEvent::process(CPlayer & p, bool isMe)
{
    QMessageBox * msgbox = new QMessageBox(QMessageBox::Critical, m_id, m_content);
    msgbox->setStandardButtons(0);
    QTimer::singleShot(2000,msgbox,SLOT(accept()));
    msgbox->exec();
    delete msgbox;

    return true;
}

//名称：返回事件序号函数
//描述：返回事件的序号，为const函数
//参数：void
//返回类型：QString
//作成日期：2018/9/4
//作者：胡昱
QString CEvent::getID(void) const
{
    return m_id;
}

//学分改变的事件
//名称：构造函数函数
//描述：初始化所有数据成员
//参数：id为事件序号，为QString类型；content为事件内容，为QString类型；c为学分改变量，为int类型
//返回类型：void
//作成日期：2018/9/4
//作者：胡昱
CCreditChangeEvent::CCreditChangeEvent(QString  id, QString  content, int c):CEvent (id, content), m_change(c)
{

}

//名称：事件处理函数
//描述：虚函数，显示事件的序号、内容，并改变角色的学分
//参数：p为触发该事件的角色，类型为CPlayer &
//返回类型：bool
//作成日期：2018/9/4
//作者：胡昱
bool CCreditChangeEvent::process(CPlayer & p, bool isMe)
{
    CEvent::process(p, isMe);
    p.addCredit(m_change);

    return true;
}

//名称：析构函数
//描述：虚函数，函数体为空
//参数：void
//返回类型：void
//作成日期：2018/9/4
//作者：胡昱
CCreditChangeEvent::~CCreditChangeEvent()
{

}

//疲劳值改变的事件
//名称：构造函数
//描述：初始化所有数据成员
//参数：id为事件序号，为QString类型；content为事件内容，为QString类型；c为疲劳值改变量，为int类型
//返回类型：void
//作成日期：2018/9/4
//作者：胡昱
CFatigueValueChangeEvent::CFatigueValueChangeEvent(QString  id, QString  content, int c):CEvent (id, content), m_change(c)
{

}

//名称：事件处理函数
//描述：虚函数，显示事件的序号、内容，并改变角色的疲劳值
//参数：p为触发该事件的角色，类型为CPlayer &
//返回类型：bool
//作成日期：2018/9/4
//作者：胡昱
bool CFatigueValueChangeEvent::process(CPlayer & p, bool isMe)
{
    CEvent::process(p, isMe);
    p.addFatigueValue(m_change);

    return true;
}

//名称：析构函数
//描述：虚函数，函数体为空
//参数：void
//返回类型：void
//作成日期：2018/9/4
//作者：胡昱
CFatigueValueChangeEvent::~CFatigueValueChangeEvent()
{

}

//地产事件
//名称：构造函数
//描述：初始化所有数据成员，函数体为空
//参数：id为事件序号，为QString类型；content为事件内容，为QString类型；h为触发事件的地产，类型为CHouse &
//返回类型：void
//作成日期：2018/9/4
//作者：胡昱
CHouseEvent::CHouseEvent(QString  id, QString  content, CHouse & h):CEvent(id, content), m_house(&h)
{

}

//名称：析构函数
//描述：虚函数，函数体为空
//参数：void
//返回类型：void
//作成日期：2018/9/4
//作者：胡昱
CHouseEvent::~CHouseEvent()
{

}

//名称：事件处理函数
//描述：虚函数，处理地产事件（包括购买、升级、缴纳过路费）；若购买成功则返回false
//参数：p为触发该事件的角色，类型为CPlayer &
//返回类型：bool
//作成日期：2018/9/4
//作者：胡昱
bool CHouseEvent::process(CPlayer & p, bool isMe)
{
    if(isMe)
    {
        //如果当前地产没有拥有者
        if(m_house->getOwner() == nullptr)
        {
            QMessageBox msgbox(QMessageBox::NoIcon,
                               "是否购买" + m_house->getName() +"?", "该地产价格" + QString::number(m_house->getPrice()),
                               QMessageBox::Yes | QMessageBox::No
                               );
            //确认购买
            if(msgbox.exec() == QMessageBox::Yes)
            {
                //检测是否有足够的学分
                if(p.getCredit() <= m_house->getPrice())
                {
                    QMessageBox * msgbox = new QMessageBox(QMessageBox::Critical, "", "没有足够的学分购买" + m_house->getName());
                    msgbox->setStandardButtons(0);
                    QTimer::singleShot(1500,msgbox,SLOT(accept()));
                    msgbox->exec();
                    delete msgbox;

                    return true;
                }
                else
                {
                    //返回false后会向所有角色声明该地产的拥有者
                    return false;

                }
            }
            //不购买
            else
            {
                return true;
            }
        }
        //若有拥有者
        else
        {

            QMessageBox * msgbox = new QMessageBox(QMessageBox::Critical, "", "您经过"+ m_house->getName() + "，需缴纳" + QString::number(m_house->getFee()) + "学分！");
            msgbox->setStandardButtons(0);
            QTimer::singleShot(2000,msgbox,SLOT(accept()));
            msgbox->exec();
            delete msgbox;

            //加减学分
            int c = -m_house->getFee();
            p.addCredit(c);
            c = m_house->getFee();
            (m_house->getOwner())->addCredit(c);

            return true;
        }
    }
    //若不是本机角色的回合
    else
    {
        //如果地产有拥有者
        if(m_house->getOwner() != nullptr)
        {
            QMessageBox * msgbox = new QMessageBox(QMessageBox::Critical, "", "经过"+ m_house->getName() + "，需缴纳" + QString::number(m_house->getFee()) + "学分！");
            msgbox->setStandardButtons(0);
            QTimer::singleShot(2000,msgbox,SLOT(accept()));
            msgbox->exec();
            delete msgbox;

            //加减学分
            int c = -m_house->getFee();
            p.addCredit(c);
            c = m_house->getFee();
            (m_house->getOwner())->addCredit(c);
        }
        return true;
    }
}

//名称：返回地产名称函数
//描述：返回地产名称
//参数：void
//返回类型：QString
//作成日期：2018/9/8
//作者：胡昱
QString CHouseEvent::getHouseName(void) const
{
    return m_house->getName();
}

/**************工具函数**************/

//名称：随机数生成函数
//描述：随机生成1～x中的整数（包括1与x）
//参数：参数x为随机数的范围:[1~x]，类型为int
//返回类型：int
//作成日期：2018/9/3
//作者：胡昱
int roll(int x)
{
    //先用当前时间设置随机数种子
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return (qrand()%x)+1;
}



































