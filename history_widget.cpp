#include "history_widget.h"
#include "ui_history_widget.h"

history_widget::history_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::history_widget)
{
    ui->setupUi(this);
    //设置表格表头
    ui->tableWidget->setColumnCount(4);
    QStringList header;
    header<<"日期"<<"时间"<<"算术表达式"<<"计算结果";
    ui->tableWidget->setHorizontalHeaderLabels(header); //设置表头
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);  //禁止表头自由拖动长度
    ui->tableWidget->setColumnWidth(0,90);
    ui->tableWidget->setColumnWidth(1,90);
    ui->tableWidget->setColumnWidth(2,100);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);  //第四列直接填充空白部分
    ui->tableWidget->verticalHeader()->setVisible(false);   //去掉前面的列表
    ui->tableWidget->horizontalHeader()->setFont(QFont("黑体",12));
    ui->tableWidget->setAlternatingRowColors(true); //表格颜色交替

    //《----------------------------------打开历史记录文件----------------------------------》
    QFile file("D:/calculator_history.xml");    //初始化文件路径
    file.open(QIODevice::ReadWrite);
    // 创建一个XML类
    QDomDocument doc;
    // 解析已存在的xml文件
    doc.setContent(&file);
    file.close();
    //获取根节点对象
    QDomElement root = doc.documentElement();
    QDomNodeList dateList = root.elementsByTagName("Date"); //第二层结点列表 日期
    QDomNodeList calculatorList = root.elementsByTagName("Calculator"); //第三层 节点列表
    QTableWidgetItem *item[4];  //表格有4列
    //添加行数
    int i,nCount;
    for (i = 0; i < calculatorList.count(); i++) {
        nCount = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(nCount);

        //获取当前循环到的第三层节点
        QDomElement element = calculatorList.at(i).toElement();

        //设置日期
        for (int var = 0; var < dateList.count(); var++){
            //获取当前循环到的第二层节点
            QDomElement dateElement = dateList.at(var).toElement();

            //如果第二层节点的第一个子节点与第三层节点所有值都相同，说明是同一个节点
            if( dateElement.firstChildElement().attribute("time") == element.attribute("time") &&
                dateElement.firstChildElement().namedItem("Expression").firstChild().nodeValue() == element.namedItem("Expression").firstChild().nodeValue()  &&
                dateElement.firstChildElement().namedItem("Result").firstChild().nodeValue() == element.namedItem("Result").firstChild().nodeValue() ){

                item[0] = new QTableWidgetItem(dateElement.attribute("date"));
                ui->tableWidget->setItem(i,0,item[0]);
            }
        }

        //设置时间,表达式，计算结果
        item[1] = new QTableWidgetItem(element.attribute("time"));
        ui->tableWidget->setItem(i,1,item[1]);

        item[2] = new QTableWidgetItem(element.namedItem("Expression").firstChild().nodeValue());
        ui->tableWidget->setItem(i,2,item[2]);

        item[3] = new QTableWidgetItem(element.namedItem("Result").firstChild().nodeValue());
        ui->tableWidget->setItem(i,3,item[3]);

    }

}

history_widget::~history_widget()
{
    delete ui;
}
//这种写函数的方法有问题，外接函数死活不好使，还没搞明白 = =
//void history_widget::insertHistoryItems(void){
//    QTableWidgetItem *item[4];  //表格有4列
//    //添加行数
//    int i,nCount;
//    for (i = 0; i < 100; i++) {
//        nCount = ui->tableWidget->rowCount();
//        ui->tableWidget->insertRow(nCount);
//    }
//}
