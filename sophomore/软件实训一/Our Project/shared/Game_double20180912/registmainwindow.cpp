#include "registmainwindow.h"
#include "ui_registmainwindow.h"
#include <QMessageBox>
#include <QValidator>
#include <QCryptographicHash>
#include <QKeyEvent>

//名称：注册窗口构造函数
//描述：构造注册窗口
//作成日期：2018/08/30
//参数：QWidget *
//返回值类型：void
//作者：王明钊
RegistMainWindow::RegistMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegistMainWindow)
{
    ui->setupUi(this);
    setWindowTitle("东南大学霸");//设置窗口标题
    setWindowFlags(Qt::WindowCloseButtonHint);  //设置窗口只有关闭按钮
    ui->RegistWarnlabel->hide();

    // 设定ID只能包含大小写字母和数字
    QRegExp RegistIDrx("[A-Za-z0-9]+$");
    QValidator * RegistIDvalidator = new QRegExpValidator(RegistIDrx, this);
    ui->RegistIDlineEdit->setValidator(RegistIDvalidator);

    // 设定密码只能包含大小写字母、数字和下划线
    QRegExp RegistPsdrx("[A-Za-z0-9_]+$");
    QValidator * RegistPsdvalidator = new QRegExpValidator(RegistPsdrx, this);
    ui->RegistPasswordlineEdit->setValidator(RegistPsdvalidator);
    ui->RegistAgainPasswordlineEdit->setValidator(RegistPsdvalidator);

    //设置注册界面gif背景
    QMovie *movie;
    movie = new QMovie(":/image/Waved.gif");
    ui->RegistWavelabel->setMovie(movie);
    movie->start();

    //按键设置
    ui->RegistRegistpushButton->setStyleSheet("QPushButton{border-image: url(:/image/Regist.png);}"
                                        "QPushButton:hover{border-image: url(:/image/RegistHover.png);}"
                                       "QPushButton:pressed{border-image: url(:/image/RegistPush.png);}");
}

//名称：注册窗口析构函数
//描述：析构注册窗口
//作成日期：2018/08/30
//参数：void
//返回值类型：void
//作者：王明钊
RegistMainWindow::~RegistMainWindow()
{
    delete ui;
}

//名称：注册按钮单击槽
//描述：用于提交用户的注册信息
//作成日期：2018/8/30
//参数：void
//返回值类型：void
//作者：王明钊
void RegistMainWindow::on_RegistRegistpushButton_clicked()
{
    QString account=ui->RegistIDlineEdit->text();
    QString password=ui->RegistPasswordlineEdit->text();
    QString password2=ui->RegistAgainPasswordlineEdit->text();

    //检测两次输入的密码是否一致
    if(password!=password2)
    {
        QMessageBox *msgBox;
        msgBox = new QMessageBox("Wrong",		//--这里是设置消息框标题
            "Password inconsistent",						//--这里是设置消息框显示的内容
            QMessageBox::Critical,							//--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		//---这里是显示消息框上的按钮情况
            QMessageBox::Cancel | QMessageBox::Escape,	//---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);														//---这里是 定义第三个按钮， 该例子 只是 了显示2个按钮
        msgBox->show();
        return;
    }
    else
    {
         //对密码进行加密
         QByteArray RegistPsd;
         RegistPsd = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5);
         QString md5Psd;
         md5Psd = RegistPsd.toHex();

         //获得发送给服务器的消息(zc|account|password)
         QString message="zc|";
         message+=account;
         message+="|";
         message+=md5Psd;

         //发送注册消息给主窗口
         emit sendRegistMessage(message);
    }


}

//名称：用户名注册编辑完成槽
//描述：当用户名输入完成后光标移至密码框
//作成日期：2018/9/5
//参数：void
//返回值类型：void
//作者：王明钊
void RegistMainWindow::on_RegistIDlineEdit_editingFinished()
{
    ui->RegistPasswordlineEdit->setFocus();
}

//名称：用户密码注册编辑完成槽
//描述：当用户密码输入完成后光标移至确认密码框
//作成日期：2018/9/5
//参数：void
//返回值类型：void
//作者：王明钊
void RegistMainWindow::on_RegistPasswordlineEdit_editingFinished()
{
    //判断密码长度是否达到最小值
    if(ui->RegistPasswordlineEdit->text().length()<6)
    {
        //如果密码长度不足则将光标定位至输入密码框s
        ui->RegistPasswordlineEdit->setFocus();
        //提示密码输入过短
        ui->RegistWarnlabel->show();
    }
    else
    {
        ui->RegistAgainPasswordlineEdit->setFocus();
        ui->RegistWarnlabel->hide();
    }
}

//名称：用户确认密码槽
//描述：用户确认密码后按下回车键等同于单击回车按钮
//作成日期：2018/9/5
//参数：void
//返回值类型：void
//作者：王明钊
void RegistMainWindow::on_RegistAgainPasswordlineEdit_returnPressed()
{
    on_RegistRegistpushButton_clicked();
}

//名称：退出键定义
//描述：用户按下Esc键后关闭注册界面
//作成日期：2018/9/9
//参数：QKeyEvent *
//返回值类型：void
//作者：王明钊
void RegistMainWindow::keyPressEvent(QKeyEvent * event )
{
    if(event->key() == Qt::Key_Escape)
    {
        this->close();
    }
}

//名称：界面关闭按钮重定义
//描述：在用户关闭界面的同时清空已输入的ID和密码
//作成日期：2018/9/9
//参数：QCloseEvent *
//返回值类型：void
//作者：王明钊
void RegistMainWindow::closeEvent(QCloseEvent * cevent)
{
    ui->RegistIDlineEdit->clear();
    ui->RegistPasswordlineEdit->clear();
    ui->RegistAgainPasswordlineEdit->clear();
}
