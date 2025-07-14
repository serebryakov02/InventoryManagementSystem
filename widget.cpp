#include "widget.h"
#include "./ui_widget.h"
#include "inventorymodel.h"
#include "stardelegate.h"
#include "supplierdelegate.h"
#include "imagedelegate.h"
#include <QMessageBox>
#include <QInputDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), m_model(nullptr)
    , m_supplierDelegate(nullptr)
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

    // We have to call this right here because if we call it later it will
    // mess up the column width setting with the delegate.
    ui->tableView->resizeColumnsToContents();

    StarDelegate *starDelegate = new StarDelegate(this);
    ui->tableView->setItemDelegateForColumn(4, starDelegate);
    ui->tableView->setColumnWidth(4, 110);

    m_supplierDelegate = new SupplierDelegate(this);
    ui->tableView->setItemDelegateForColumn(2, m_supplierDelegate);

    ImageDelegate *imageDelegate = new ImageDelegate(this);
    ui->tableView->setItemDelegateForColumn(3, imageDelegate);
    ui->tableView->setColumnWidth(3, 72);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->verticalHeader()->setDefaultSectionSize(72);

    resize(1024, 768);
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

void Widget::on_btnEdit_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (index.isValid()) {
        ui->tableView->edit(index);
    }
}

void Widget::on_btnManage_clicked()
{
    QString suppliers;
    QStringList listToUse = !m_supplierList.isEmpty()
            ? m_supplierList
            : (m_supplierDelegate ? m_supplierDelegate->supplierList() : QStringList());
    suppliers = listToUse.join(", ");

    bool ok = false;
    QString input = QInputDialog::getText(this, "Enter Supplier List",
                    "Please enter a comma-separated list of supplier names: ",
                    QLineEdit::Normal, suppliers, &ok);
    QStringList list;
    if (ok) {
        m_supplierList.clear();
        list = input.split(",");
        for (auto &supplier : list) {
            supplier = supplier.trimmed(); // trim whitespace
            m_supplierList << supplier;
        }

        if (m_supplierDelegate) // should never be nullptr
            m_supplierDelegate->setSupplierList(m_supplierList);
    }
}

