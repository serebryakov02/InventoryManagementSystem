#include "widget.h"
#include "./ui_widget.h"
#include "inventorymodel.h"

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

    m_model = new InventoryModel(this);
    ui->tableView->setModel(m_model);
    ui->tableView->resizeColumnsToContents();
}
