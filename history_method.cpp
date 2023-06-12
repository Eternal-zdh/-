#include "history_method.h"


//第一个函数，保存历史记录，放入D盘
void history_method::history(QString expression,QString result)
{
    QFile file("D:/calculator_history.xml");    //初始化文件路径

    //判断路径是否存在文件，如果没有记录，就新建文件，添加第一行和根节点
    if(!QFile::exists("D:/calculator_history.xml")){
        file.open(QIODevice::ReadWrite);
        // 创建一个XML类
        QDomDocument doc;
        // 创建XML处理类，通常用于处理第一行描述信息
        QDomProcessingInstruction instruction;
        // 创建XML头部格式
        instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
        // 添加到XML文件中
        doc.appendChild(instruction);
        // 创建根节点
        QDomElement root = doc.createElement("History");
        doc.appendChild(root);
            // 添加二级节点，日期
            QDomElement date = doc.createElement("Date");
            QDate dateNow = QDate::currentDate();   //获取当前日期
            date.setAttribute("date", dateNow.toString("yyyy-MM-dd"));
                // 添加三级节点
                QDomElement calculator = doc.createElement("Calculator");
                date.appendChild(calculator);
                QTime timeNow = QTime::currentTime();   //获取当前时间
                calculator.setAttribute("time",timeNow.toString("hh:mm:ss"));
                    //添加子元素1，表达式
                    QDomElement expressionXML = doc.createElement("Expression");
                    QDomText text1 = doc.createTextNode(expression);
                    expressionXML.appendChild(text1);
                    calculator.appendChild(expressionXML);
                    // 添加子元素2，结果
                    QDomElement resultXML = doc.createElement("Result");
                    QDomText text2 = doc.createTextNode(result);
                    resultXML.appendChild(text2);
                    calculator.appendChild(resultXML);
                    root.appendChild(date);
        // 将其写入到xml文件中
        QTextStream stream(&file);
        doc.save(stream, 4);		// 缩进四格
        //关闭文件
        file.close();
    }else{
        file.open(QIODevice::ReadWrite);
        // 创建一个XML类
        QDomDocument doc;
        // 解析已存在的xml文件
        doc.setContent(&file);
        file.close();
        //获取根节点对象
        QDomElement root = doc.documentElement();

        // 获取所有Date节点,将记录放在同一日期内
        QDomNodeList list = root.elementsByTagName("Date");
        for (int i = 0; i < list.count(); i++) {
            // 获取二级节点，element就是当前的二级节点
            QDomElement element = list.at(i).toElement();
            // 找到日期的节点
            QDate dateNow = QDate::currentDate();   //获取当前日期，找到相同的日期
            if (element.attribute("date") == dateNow.toString("yyyy-MM-dd")) {

                // 添加三级节点
                QDomElement calculator = doc.createElement("Calculator");
                element.appendChild(calculator);
                QTime timeNow = QTime::currentTime();   //获取当前时间
                calculator.setAttribute("time",timeNow.toString("hh:mm:ss"));
                    //添加子元素1，表达式
                    QDomElement expressionXML = doc.createElement("Expression");
                    QDomText text1 = doc.createTextNode(expression);
                    expressionXML.appendChild(text1);
                    calculator.appendChild(expressionXML);
                    // 添加子元素2，结果
                    QDomElement resultXML = doc.createElement("Result");
                    QDomText text2 = doc.createTextNode(result);
                    resultXML.appendChild(text2);
                    calculator.appendChild(resultXML);
                // 将其写入到xml文件中
                file.open(QFileDevice::WriteOnly);
                QTextStream stream(&file);
                doc.save(stream, 4);		// 缩进四格
                //关闭文件
                file.close();

                //已经加好记录了，结束当前函数
                return;
            }
        }

        // 遍历记录后没有相同的日期，添加新的日期二级节点
        QDomElement date = doc.createElement("Date");
        QDate dateNow = QDate::currentDate();   //获取当前日期
        date.setAttribute("date", dateNow.toString("yyyy-MM-dd"));
            // 添加三级节点
            QDomElement calculator = doc.createElement("Calculator");
            date.appendChild(calculator);
            QTime timeNow = QTime::currentTime();   //获取当前时间
            calculator.setAttribute("time",timeNow.toString("hh:mm:ss"));
                //添加子元素1，表达式
                QDomElement expressionXML = doc.createElement("Expression");
                QDomText text1 = doc.createTextNode(expression);
                expressionXML.appendChild(text1);
                calculator.appendChild(expressionXML);
                // 添加子元素2，结果
                QDomElement resultXML = doc.createElement("Result");
                QDomText text2 = doc.createTextNode(result);
                resultXML.appendChild(text2);
                calculator.appendChild(resultXML);
            root.appendChild(date);
        // 将其写入到xml文件中
        file.open(QFileDevice::WriteOnly);
        QTextStream stream(&file);
        doc.save(stream, 4);		// 缩进四格
        //关闭文件
        file.close();
    }
}
