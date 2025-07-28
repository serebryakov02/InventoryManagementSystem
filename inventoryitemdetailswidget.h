#ifndef INVENTORYITEMDETAILSWIDGET_H
#define INVENTORYITEMDETAILSWIDGET_H

#include <QWidget>

class InventoryItem;

namespace Ui {
class InventoryItemDetailsWidget;
}

class InventoryItemDetailsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryItemDetailsWidget(QWidget *parent = nullptr);
    ~InventoryItemDetailsWidget();

    void setItemInfo(const InventoryItem* item);

signals:
    void descriptionChanged(const QString &description);

private slots:
    void on_textEditDescription_textChanged();

private:
    Ui::InventoryItemDetailsWidget *ui;
    QString m_prevDetailedDescription;

    void initGUI();
};

#endif // INVENTORYITEMDETAILSWIDGET_H
