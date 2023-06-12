#include "calculator_method.h"

float calculator_method::calculator(QString calculator_expression)
{
    QString str = calculator_expression;
    QVector<QString> inStr;
    QVector<QString> postStr;  //存储后缀表达式
    QStack<QString> opStack;
    //将中缀表达式转换为后缀表达式
    int len = str.size();
    QString ans;
    for (int i = 0; i < len; i++) {
        if (judge(str[i])) {
            ans += str[i];
            if (i + 1 < len && judge(str[i + 1])) {

            }
            else {
                inStr.push_back(ans);
                ans.clear();
            }
        }
        else {
            ans += str[i];
            inStr.push_back(ans);
            ans.clear();
        }
    }
    int size = inStr.size();
    for (int i = 0; i < size; i++) {
        if (inStr[i] == "(") {
            opStack.push(inStr[i]);
        }
        else if (inStr[i] == ")") {  //去匹配'('
            while (!opStack.empty()) {
                QString topc = opStack.top();
                opStack.pop();
                if (topc == "(") {
                    break;
                }
                else {
                    postStr.push_back(topc);
                }
            }
        }
        else if (inStr[i] == "+" || inStr[i] == "-" || inStr[i] == "*" || inStr[i] == "/") { //为运算符，入栈
            if (opStack.empty()) {
                opStack.push(inStr[i]);
            }
            else {
                while (!opStack.empty()) {
                    QString topc = opStack.top();
                    if (topc == "(") break;
                    if (op_prior(topc, inStr[i])) {
                        postStr.push_back(topc);
                        opStack.pop();
                    }
                    else {
                        break;
                    }
                }
                opStack.push(inStr[i]);
            }
        }
        else { //数字
            postStr.push_back(inStr[i]);
        }
    }
    //剩下的全部出栈
    while (!opStack.empty()) {
        postStr.push_back(opStack.top());
        opStack.pop();
    }
    //对后缀表达式进行计算(对数字进行入栈)
    size = postStr.size();
    QStack<float> numStack;  //除法可能产生小数，所以用float型
    //stringstream ss;
    for (int i = 0; i < size; i++) {
        if (postStr[i] == "+" || postStr[i] == "-" || postStr[i] == "*" || postStr[i] == "/") {//运算符(后缀表达式肯定不含括号了)
            float n2 = numStack.top();
            numStack.pop();
            float n1 = numStack.top();
            numStack.pop();
            float res = operation(n1, postStr[i], n2);
            numStack.push(res);
        }
        else {
            //ss << postStr[i];
            //将qstring转换为float，之前用的是sstream
            float val = postStr[i].toFloat();
            //ss >> val;
            numStack.push(val);
            //ss.clear();
        }
    }

    return numStack.top();
}

//计算器需要的函数------------------------------------------------
float calculator_method::operation(float a, QString op, float b) {
    if (op == "+") {
        return a + b;
    }
    else if (op == "-") {
        return a - b;
    }
    else if (op == "*") {
        return a * b;
    }
    else {
        return a / b;
    }
}
bool calculator_method::op_prior(QString a, QString b) {  //定义运算符号的优先级，“＋”“－”——1 ， “＊”“／”——2
    int aa, bb;
    if (a == "+" || a == "-") {
        aa = 1;
    }
    else if (a == "*" || a == "/") {
        aa = 2;
    }
    if (b == "+" || b == "-") {
        bb = 1;
    }
    else if (b == "*" || b == "/") {
        bb = 2;
    }
    return aa >= bb;
}
bool calculator_method::judge(QChar c) {
    if (c >= '0' && c <= '9' || c == '.') return true;
    return false;
}
//计算器需要的函数------------------------------------------------
