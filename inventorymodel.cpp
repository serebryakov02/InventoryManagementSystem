#include "inventorymodel.h"
#include "inventoryitem.h"
#include <QVector>

InventoryModel::InventoryModel(QObject *parent)
    : QAbstractTableModel{parent}, m_items()
{
    initializeItems();
}

void InventoryModel::initializeItems()
{
    InventoryItem *item1 = new InventoryItem;
    item1->setProductName("Seiko Presage Horloge SRPB41J1");
    item1->setQuantity(10);
    item1->setSupplier("Seiko Japan");
    item1->setRating(5);
    item1->setDescription("Elegant men's mechanical watch "
        "featuring a stainless steel case, blue sunburst dial, and"
        " automatic movement. Known for its craftsmanship and classic design.");
    m_items.push_back(item1);
}


int InventoryModel::rowCount(const QModelIndex &parent) const
{
    return m_items.size();
}

int InventoryModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant InventoryModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole) {
        InventoryItem *item = m_items.at(index.row());
        if (index.column() == 0) return item->productName();
        if (index.column() == 1) return item->quantity();
        if (index.column() == 2) return item->supplier();
        // TODO: image field
        if (index.column() == 4) return item->rating();
    }
    return {};
}


QVariant InventoryModel::headerData(int section, Qt::Orientation orientation,
                                    int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        if (section == 0) return QStringLiteral("Product Name");
        if (section == 1) return QStringLiteral("Quantity");
        if (section == 2) return QStringLiteral("Supplier");
        if (section == 3) return QStringLiteral("Image");
        if (section == 4) return QStringLiteral("Rating");
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}
