#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <QObject>
#include <QDateTime>

class InventoryItem : public QObject
{
    Q_OBJECT
public:
    explicit InventoryItem(QObject *parent = nullptr);

    void setProductName(const QString &newProductName);
    void setQuantity(int newQuantity);
    void setSupplier(const QString &newSupplier);
    void setRating(int newRating);
    void setDescription(const QString &newDescription);
    void setLastUpdated(const QDateTime &newLastUpdated);

    QString productName() const;
    int quantity() const;
    QString supplier() const;
    int rating() const;
    QString description() const;
    QDateTime lastUpdated() const;

private:
    QString   m_productName;
    int       m_quantity;
    QString   m_supplier;
    // TODO: Define product image field
    int       m_rating;
    QString   m_description;
    QDateTime m_lastUpdated;

};

#endif // INVENTORYITEM_H
