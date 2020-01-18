#ifndef CLASSES_H
#define CLASSES_H

#include <QPixmap>
#include <QString>
#include <QPoint>
#include <QTime>
#include <QtGlobal>

class CPlayer;
class CPoint;
class CHouse;
class CEvent;

//成员函数的注释均在.cpp文件中

/**************坐标点类**************/
class CPoint:public QPoint
{
public:
    CPoint();
    CPoint(int , int , int , CEvent**,bool, CPoint*, CPoint*);
    CPoint(CPoint &);
    ~CPoint();

    bool isBranch() const;
    void setNext(CPoint *);
    int getNumOfEvents(void) const;
    QString getEventName(int &) const;

public:
    CPoint * m_next;//直行的下一个点
    CPoint * m_turn;//转弯的下一个点

private:
    int m_numOfEvents;//该点包含的事件数量
    CEvent * *m_events;//包含事件指针的数组
    bool m_isBranchPoint;//是否为三叉点
};

/**************玩家类**************/
 class CPlayer
{
public:
    CPlayer(QString &);
    CPlayer(void);
    ~CPlayer();

    QString getName(void) const;
    void setName(QString);

    int getCredit(void) const;
    void addCredit(int);

    int getFatigueValue(void) const;
    void addFatigueValue(int);

    CPoint getPoint(void);
    void setPoint(CPoint);

    void setAppearance(QPixmap);
    QPixmap getAppearance(void) const;

 private:
    QString m_name;//角色的名称（即账号）
    CPoint m_location;//角色所在的点
    int m_credit;//角色拥有的学分
    int m_fatigueValue;//角色当前的疲劳值
    QPixmap m_appearance;//角色外观
};

/**************地产类**************/
class CHouse
{
public:
    CHouse(QString, const int);
    ~CHouse(void);
    int getFee(void) const;
    void setOwner(CPlayer &);
    int getPrice(void) const;
    QString getName(void) const;
    CPlayer * getOwner(void) const;

private:
    QString m_name;//地产的名称
    CPlayer * m_owner;//指向地产拥有者的指针
    int m_price;//地产的价格
    int m_fee;//过路费
};

/**************事件类**************/
//抽象基类
class CEvent
{
public:
    CEvent(QString , QString);
    virtual ~CEvent(void);
    virtual bool process(CPlayer &, bool);
    QString getID(void) const;
private:
    QString m_id;//事件的序号
    QString m_content;//事件的内容
};

//学分改变的事件
class CCreditChangeEvent: public CEvent
{
public:
    CCreditChangeEvent(QString , QString , int);
    virtual ~CCreditChangeEvent();
    virtual bool process(CPlayer &, bool);
private:
    int m_change;//学分的改变量
};

//疲劳值改变的事件
class CFatigueValueChangeEvent: public CEvent
{
public:
    CFatigueValueChangeEvent(QString , QString , int );
    virtual ~CFatigueValueChangeEvent();
    virtual bool process(CPlayer &, bool);
private:
    int m_change;//疲劳值的改变量
};

//地产事件
class CHouseEvent:public CEvent
{
public:
    CHouseEvent(QString , QString , CHouse &);
    virtual ~CHouseEvent();
    virtual bool process(CPlayer &, bool);
    QString getHouseName(void) const;
private:
    CHouse * m_house;//发生事件的地产
};




/**************工具函数**************/
//随机数生成函数，参数为随机数的范围[1~x]
int roll(int);




#endif // CLASSES_H
