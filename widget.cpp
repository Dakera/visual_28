#include "widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //setupUi(this);
    //codec = QTextCodec::codecForName("Windows-1251");
    //this->setWindowTitle("Счетчик");
    setWindowTitle("Счетчик"); // разницы нет с пред строчкой

    // создание объектов
    label1 = new QLabel("Cчет по 1", this);
    label2 = new QLabel("Cчет по 5", this);
    edit1 = new Counter("0", this);
    edit2 = new Counter("0", this);
    calcbutton = new QPushButton("+1", this);
    exitbutton = new QPushButton("Выход", this);

    // добавление и заполнение лейаутов (для выравнивания)
    QHBoxLayout *layout1 = new QHBoxLayout();
    layout1->addWidget(label1);
    layout1->addWidget(label2);
    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(edit1);
    layout2->addWidget(edit2);
    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3->addWidget(calcbutton);
    layout3->addWidget(exitbutton);
    QVBoxLayout *layout4 = new QVBoxLayout(this);
    layout4->addLayout(layout1);layout4->addLayout(layout2);
    layout4->addLayout(layout3);

    // связи
    connect(calcbutton, SIGNAL(clicked(bool)), // связь клика и +1
    edit1, SLOT(add_one()) );
    connect(edit1, SIGNAL(tick_signal()), // связь функции и +1 для второго поля (когда вызывается функция tick_signal, второе поле +1)
    edit2, SLOT(add_one()) );
    connect(exitbutton, SIGNAL(clicked(bool)),
    this, SLOT(close()) );
}

Widget::~Widget()
{
}

