#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initGUI();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initGUI()
{
    ui->txtSearch->setPlaceholderText("Enter search terms...");
}
