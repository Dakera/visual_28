#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"

#include <QWidget>
#include <QtGui>
#include <QLineEdit>
#include <QPushButton> // если добавить в дизайн едитор кнопки, то это не нужно
#include <QLabel> // если добавить в дизайн едитор лайблы, то это не нужно
#include <QHBoxLayout>
//#include <QTextCodec> // почему-то не подключает

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent = 0) :
        QLineEdit(contents,parent){} // конструктор
signals:
    void tick_signal(); // сигнальная функция
public slots:
    void add_one() // функция +1
    {
        QString str = text();
        int r = str.toInt();
        if (r != 0 && r%5 == 0)
            emit tick_signal(); // emit определяется пустотой. Так что это просто вызов сигнальной функции tick_signal()
        r++; // но emit как для читаемости для сигнальных функций
        str.setNum(r);
        setText(str);
    }
};

class Widget : public QWidget, private Ui::Widget
{
    Q_OBJECT
protected:
    //QTextCodec *codec;
    QLabel *label1, *label2; // надписи
    Counter *edit1, *edit2; // поля
    QPushButton *calcbutton; // кнопки
    QPushButton *exitbutton;
public:
    Widget(QWidget *parent = nullptr); // конструктор
    ~Widget(); // деструктор
};


#endif // WIDGET_H
