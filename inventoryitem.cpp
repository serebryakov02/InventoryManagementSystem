#include "inventoryitem.h"
#include <QDebug> // TODO: probably remove
#include <QBuffer>

InventoryItem::InventoryItem(QObject *parent)
    : QObject{parent}, m_productName(""), m_quantity(0),
    m_supplier(""), m_rating(0), m_description(""),
    m_imagePath(":/Images/no_image.jpg")
{
    m_lastUpdated = QDateTime::currentDateTime();
    qDebug() << m_lastUpdated;
}

QString InventoryItem::productName() const
{
    return m_productName;
}

void InventoryItem::setProductName(const QString &newProductName)
{
    m_productName = newProductName;
}

int InventoryItem::quantity() const
{
    return m_quantity;
}

void InventoryItem::setQuantity(int newQuantity)
{
    m_quantity = newQuantity;
}

QString InventoryItem::supplier() const
{
    return m_supplier;
}

void InventoryItem::setSupplier(const QString &newSupplier)
{
    m_supplier = newSupplier;
}

int InventoryItem::rating() const
{
    return m_rating;
}

void InventoryItem::setRating(int newRating)
{
    m_rating = newRating;
}

QString InventoryItem::description() const
{
    return m_description;
}

void InventoryItem::setDescription(const QString &newDescription)
{
    m_description = newDescription;
}

QDateTime InventoryItem::lastUpdated() const
{
    return m_lastUpdated;
}

QImage InventoryItem::image() const
{
    if (!m_image.isNull())
        return m_image;

    QImage loaded = QImage(m_imagePath);
    if (!loaded.isNull())
        return loaded;

    return QImage(":/Images/no_image.jpg"); // fallback just in caseс
}

QJsonObject InventoryItem::toJson() const
{
    QJsonObject obj;
    obj["productName"] = m_productName;
    obj["quantity"] = m_quantity;
    obj["supplier"] = m_supplier;
    obj["rating"] = m_rating;
    obj["description"] = m_description;
    // Reason: ISODate is a standardized, portable, and unambiguous format.
    obj["lastUpdated"] = m_lastUpdated.toString(Qt::ISODate);
    obj["imagePath"] = m_imagePath;

    return obj;
}

void InventoryItem::fromJson(const QJsonObject &obj)
{
    m_productName = obj["productName"].toString();
    m_quantity = obj["quantity"].toInt();
    m_supplier = obj["supplier"].toString();
    m_rating = obj["rating"].toInt();
    m_description = obj["description"].toString();
    QString dateStr = obj["lastUpdated"].toString();
    m_lastUpdated = QDateTime::fromString(dateStr, Qt::ISODate);
    m_imagePath = obj["imagePath"].toString();
}

QString InventoryItem::imagePath() const
{
    return m_imagePath;
}

void InventoryItem::setImagePath(const QString &newImagePath)
{
    m_imagePath = newImagePath;
}

void InventoryItem::setImage(const QImage &newImage)
{
    m_image = newImage;
}

void InventoryItem::setLastUpdated(const QDateTime &newLastUpdated)
{
    m_lastUpdated = newLastUpdated;
}
