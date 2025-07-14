#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <QObject>
#include <QDateTime>
#include <QImage>

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
    void setImage(const QImage &newImage);

    QString productName() const;
    int quantity() const;
    QString supplier() const;
    int rating() const;
    QString description() const;
    QDateTime lastUpdated() const;
    QImage image() const;

private:
    QString   m_productName;
    int       m_quantity;
    QString   m_supplier;
    QImage    m_image;
    int       m_rating;
    QString   m_description;
    QDateTime m_lastUpdated; // TODO: check where and how it is used. Update accordingly
};

#endif // INVENTORYITEM_H
