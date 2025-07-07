#include "inventorymodel.h"
#include "inventoryitem.h"
#include <QVector>
#include <QInputDialog>

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

bool InventoryModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(count);

    if (row == m_items.size()) {
        QString productName = QInputDialog::getText(nullptr,
                                    "Product Name", "Enter product name: ");
        int quantity = QInputDialog::getInt(nullptr, "Quantity",
                                    "Enter quantity: ", 0, 0);
        QString supplier = QInputDialog::getText(nullptr, "Supplier",
                                                 "Enter supplier name: ");
        int rating = QInputDialog::getInt(nullptr, "Rating",
                                "Enter product rating (1-5): ", 1, 1, 5);
        QString description = QInputDialog::getMultiLineText(nullptr,
                                "Description", "Enter product description: ");

        InventoryItem *item = new InventoryItem;
        item->setProductName(productName);
        item->setQuantity(quantity);
        item->setSupplier(supplier);
        item->setRating(rating);
        item->setDescription(description);

        emit beginInsertRows(parent, row, row);
        m_items.push_back(item);
        emit endInsertRows();

        return true;
    }
    return false;
}

bool InventoryModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(count);

    if (row >= 0 && row < m_items.size()) {
        InventoryItem *item = m_items.at(row);
        delete item;
        emit beginRemoveRows(parent, row, row);
        m_items.removeAt(row);
        emit endRemoveRows();
        return true;
    }
    return false;
}
