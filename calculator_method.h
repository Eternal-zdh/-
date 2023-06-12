#ifndef CALCULATOR_METHOD_H
#define CALCULATOR_METHOD_H
#include <QStack>
#include <string.h>
#include <QVector>

class calculator_method
{
public:
    //声明外部调用的成员函数
    static float calculator(QString expression);
private:
    //声明内部用的成员函数
    static float operation(float a, QString op, float b);
    static bool op_prior(QString a, QString b);
    static bool judge(QChar c);
};

#endif // CALCULATOR_METHOD_H
