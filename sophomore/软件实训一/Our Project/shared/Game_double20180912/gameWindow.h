#ifndef gameWindow_H
#define gameWindow_H
#include "classes.h"
#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QPoint>


class gameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit gameWindow(); //析构函数
    void move(int);        //人物移动函数

    enum  Type {
        None          = 0,
        Lift,
        Right,
        Up,
        Down,
        Move
    };                  //声明移动类型

private :
    int action;         //移动动作
    int pixW;           //图片宽
    int pixH;           //图片高
    int px = 0;         //初始人物横坐标
    int py = 0;         //初始人物纵坐标
    int m_nowID;        //当前回合的角色ID
    int m_data;         //记录游戏日期

    QPixmap  *pix,*pixx;        //两幅地图指针，分别对应大地图和小地图
    QRect Paint,Paint1;         //绘画区域

    QPoint offset;              //移动图片，一次的图片偏移值
    QPoint Alloffset;           //总偏移

    QLabel credictLabel;        //声明学分标签
    QLabel dateLabel;           //声明时间标签
    QLabel credictStatusLabel;  //声明显示学分标签
    QLabel dateStatusLabel;     //声明显示日期标签
    QLabel showNumberLabel;     //声明所掷骰子数标签

    QPushButton  throwButton;   //声明掷骰子按钮

    CPlayer * players;         //指向玩家数组的指针
    QString m_myName;          //本机角色的名称（即账号）

    void AddComboItem(QComboBox* cmbo);
    bool event(QEvent * event);           //移动事件所对应的函数
    void paintEvent(QPaintEvent *event);  //绘画事件函数

public slots:
    void setMyName(QString);//接受主窗口传来的本机用户的账号
    void roundBegin(int);//接受主窗口传来的回合ID
    void Dice(int);//接受主窗口传来的骰子点数
    void gameBeginMessage(QStringList);//接受主窗口传来的游戏创建消息
    void eventMessage(QStringList);//接受主窗口传来的事件消息
    void winMessage(int);//接受主窗口传来的游戏获胜消息
    void loseMessage(int);//接受主窗口传来的游戏失败消息
    void houseMessage(QStringList);//接受主窗口传来的地产购买消息

private slots:
    void throwDice(void);   //掷骰子槽

signals:
    void sendDice(int);
    void sendEventMessage(QString);
    void sendRoundEnd(void);
    void sendWinMessage(int);
    void sendLoseMessage(int);
    void sendReturnRoom(void);
    void sendHouseMessage(QString);
};
#endif // gameWindow_H
