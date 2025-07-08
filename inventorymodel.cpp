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

    InventoryItem *item2 = new InventoryItem;
    item2->setProductName("Omega Speedmaster Moonwatch Professional");
    item2->setQuantity(7);
    item2->setSupplier("Omega SA");
    item2->setRating(5);
    item2->setDescription("Iconic chronograph with manual winding movement, "
                          "hesalite crystal, and tachymeter bezel. Famously worn during Apollo moon missions.");
    m_items.push_back(item2);

    InventoryItem *item3 = new InventoryItem;
    item3->setProductName("Rolex Submariner Date 126610LN");
    item3->setQuantity(5);
    item3->setSupplier("Rolex Geneva");
    item3->setRating(5);
    item3->setDescription("Legendary diving watch featuring a black Cerachrom bezel, "
                          "automatic movement, and 300-meter water resistance. A benchmark in luxury sports timepieces.");
    m_items.push_back(item3);

    InventoryItem *item4 = new InventoryItem;
    item4->setProductName("Tag Heuer Carrera Calibre 5");
    item4->setQuantity(12);
    item4->setSupplier("TAG Heuer SA");
    item4->setRating(4);
    item4->setDescription("Stylish automatic watch with sapphire case back, "
                          "day-date function, and a clean silver dial. Suited for both professional and casual wear.");
    m_items.push_back(item4);

    InventoryItem *item5 = new InventoryItem;
    item5->setProductName("Tissot Le Locle Powermatic 80");
    item5->setQuantity(15);
    item5->setSupplier("Tissot Switzerland");
    item5->setRating(4);
    item5->setDescription("Classic Swiss timepiece with an 80-hour power reserve, "
                          "Roman numerals, and transparent case back. Celebrates traditional watchmaking heritage.");
    m_items.push_back(item5);

    InventoryItem *item6 = new InventoryItem;
    item6->setProductName("Longines Master Collection L2.909.4.78.3");
    item6->setQuantity(8);
    item6->setSupplier("Longines SA");
    item6->setRating(4);
    item6->setDescription("Elegant dress watch featuring moonphase complication, "
                          "automatic movement, and barleycorn-pattern dial. Known for precision and refinement.");
    m_items.push_back(item6);

    InventoryItem *item7 = new InventoryItem;
    item7->setProductName("Casio G-Shock GA-2100-1A1");
    item7->setQuantity(20);
    item7->setSupplier("Casio Tokyo");
    item7->setRating(4);
    item7->setDescription("Durable carbon-core guard structure, analog-digital hybrid display, "
                          "and 200-meter water resistance. A minimalist yet rugged design.");
    m_items.push_back(item7);

    InventoryItem *item8 = new InventoryItem;
    item8->setProductName("Citizen Eco-Drive Promaster Diver BN0150-28E");
    item8->setQuantity(14);
    item8->setSupplier("Citizen Watch Co.");
    item8->setRating(4);
    item8->setDescription("Solar-powered diver's watch with ISO certification, "
                          "black polyurethane strap, and luminous markers. Environmentally friendly and reliable.");
    m_items.push_back(item8);

    InventoryItem *item9 = new InventoryItem;
    item9->setProductName("Hamilton Khaki Field Mechanical H69439931");
    item9->setQuantity(9);
    item9->setSupplier("Hamilton Watch Company");
    item9->setRating(4);
    item9->setDescription("Military-inspired manual wind watch with matte stainless steel case, "
                          "durable NATO strap, and 80-hour power reserve. A rugged, utilitarian classic.");
    m_items.push_back(item9);

    InventoryItem *item10 = new InventoryItem;
    item10->setProductName("Breitling Navitimer B01 Chronograph 43");
    item10->setQuantity(4);
    item10->setSupplier("Breitling SA");
    item10->setRating(5);
    item10->setDescription("Pilot’s chronograph with in-house B01 automatic movement, "
                           "slide rule bezel, and a high-contrast dial. Celebrated for aviation heritage and engineering.");
    m_items.push_back(item10);

    InventoryItem *item11 = new InventoryItem;
    item11->setProductName("Invicta Pro Diver 8926OB");
    item11->setQuantity(18);
    item11->setSupplier("Invicta Watch Group");
    item11->setRating(3);
    item11->setDescription("Affordable automatic diving watch with a stainless steel case, "
                           "unidirectional bezel, and exhibition case back. Offers solid value for entry-level collectors.");
    m_items.push_back(item11);

    InventoryItem *item12 = new InventoryItem;
    item12->setProductName("Timex Weekender Chronograph TW2R42600");
    item12->setQuantity(22);
    item12->setSupplier("Timex USA");
    item12->setRating(3);
    item12->setDescription("Casual quartz chronograph with an interchangeable strap system, "
                           "Indiglo night-light, and classic dial layout. Known for practicality and affordability.");
    m_items.push_back(item12);
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
    if (index.isValid() && role == Qt::DisplayRole || role == Qt::EditRole) {
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

bool InventoryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {

        InventoryItem *item = m_items.at(index.row());

        switch (index.column()) {
        case 0: item->setProductName(value.toString()); break;
        case 1: item->setQuantity(value.toInt()); break;
        case 2: item->setSupplier(value.toString()); break; // TODO: custom delegate
        // TODO case 3: image delegate
        case 4: item->setRating(value.toInt()); break;
        default: return false;
        }

        emit dataChanged(index, index);

        return true;
    }
    return false;
}

Qt::ItemFlags InventoryModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return QAbstractTableModel::flags(index);
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
