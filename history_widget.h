#ifndef HISTORY_WIDGET_H
#define HISTORY_WIDGET_H

#include <QWidget>
#include <QFile>
#include <QDomDocument>
#include <QtXml>

namespace Ui {
class history_widget;
}

class history_widget : public QWidget
{
    Q_OBJECT

public:
    explicit history_widget(QWidget *parent = nullptr);
    ~history_widget();
    //void history_widget::insertHistoryItems(void);

private:
    Ui::history_widget *ui;
};

#endif // HISTORY_WIDGET_H
