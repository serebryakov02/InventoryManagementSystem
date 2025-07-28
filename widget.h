#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class InventoryModel;
class SupplierDelegate;
class InventoryItemDetailsWidget;

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
    void on_tableSelection_changed();
    void on_detailedDescription_changed(const QString &detailedDescription);

private:
    Ui::Widget *ui;
    void initGUI();

    InventoryModel *m_model;
    SupplierDelegate *m_supplierDelegate;
    QStringList m_supplierList;

    InventoryItemDetailsWidget *m_rightPaneWidget;

    // QWidget interface
protected:
    virtual void closeEvent(QCloseEvent *event) override;
};

#endif // WIDGET_H
