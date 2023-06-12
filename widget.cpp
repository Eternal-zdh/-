#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//右击控件直接转到槽，就不需要connect连接信号和槽了，QT会自动识别 on_组件名_信号 这个操作格式的
void Widget::on_pushButton_1_clicked()
{
    expression += '1';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_2_clicked()
{
    expression += '2';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_3_clicked()
{
    expression += '3';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_4_clicked()
{
    expression += '4';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_5_clicked()
{
    expression += '5';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_6_clicked()
{
    expression += '6';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_7_clicked()
{
    expression += '7';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_8_clicked()
{
    expression += '8';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_9_clicked()
{
    expression += '9';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_0_clicked()
{
    expression += '0';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_00_clicked()
{
    expression += "00";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_point_clicked()//小数点
{
    expression += '.';
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_div_clicked()//除号
{
    expression += "/";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_mul_clicked()//乘号
{
    expression += "*";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_sub_clicked()//减号
{
    expression += "-";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_add_clicked()//加号
{
    expression += "+";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton_clear_clicked()//清除
{
    expression.clear();
    ui->lineEdit->clear();
    ui->lineEdit_result->clear();
}


void Widget::on_pushButton_back_clicked()//回退表达式
{
    expression.chop(1);
    ui->lineEdit->setText(expression);
    ui->lineEdit_result->clear();
}


void Widget::on_pushButton_equal_clicked()//等号，计算表达式
{

    //调用计算器函数，传入表达式expression，用float接收
    float calculator_result = calculator_method::calculator(expression);
    //将float转换为QString,显示在主窗口
    result = QString("%1").arg(calculator_result);
    ui->lineEdit_result->setText(result);

    //调用函数，在指定位置创建历史记录的文件
    history_method::history(expression,result);
}

void Widget::on_pushButton_percent_clicked()
{

}

void Widget::on_pushButton_history_clicked()    //点击历史记录，跳转到新的wiget
{
    history_widget *configWindow = new history_widget;
    configWindow->show();
}

