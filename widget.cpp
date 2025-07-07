#include "widget.h"
#include "./ui_widget.h"
#include "inventorymodel.h"
#include <QMessageBox>

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

void Widget::on_btnAdd_clicked()
{
    if (m_model) {
        int rowCount = m_model->rowCount();
        m_model->insertRows(rowCount, 1);
    }
}

void Widget::on_btnDelete_clicked()
{
    if (m_model) {
        auto selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
        if (selectedIndexes.size() == 0) return;

        auto reply = QMessageBox::question(nullptr,
                                      "Confirm Deletion",
                                      "Are you sure you want to delete this row?",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            int rowToRemove = ui->tableView->currentIndex().row();
            m_model->removeRows(rowToRemove, 1);
        }
    }
}
