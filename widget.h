#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class InventoryModel;
class SupplierDelegate;

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnAdd_clicked();
    void on_btnDelete_clicked();
    void on_btnEdit_clicked();
    void on_btnManage_clicked();

private:
    Ui::Widget *ui;
    void initGUI();

    InventoryModel *m_model;
    SupplierDelegate *m_supplierDelegate;
    QStringList m_supplierList;
};

#endif // WIDGET_H
