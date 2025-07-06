#include "inventoryitem.h"
#include <QDebug>

InventoryItem::InventoryItem(QObject *parent)
    : QObject{parent}, m_productName(""), m_quantity(0),
    m_supplier(""), m_rating(0), m_description("")
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

void InventoryItem::setLastUpdated(const QDateTime &newLastUpdated)
{
    m_lastUpdated = newLastUpdated;
}
