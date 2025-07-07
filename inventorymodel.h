#ifndef INVENTORYMODEL_H
#define INVENTORYMODEL_H

#include <QAbstractTableModel>

class InventoryItem;

class InventoryModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit InventoryModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent= QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role) const override;
    virtual bool insertRows(int row, int count,
                            const QModelIndex &parent = QModelIndex()) override;
    virtual bool removeRows(int row, int count,
                            const QModelIndex &parent = QModelIndex()) override;

private:
    QVector<InventoryItem*> m_items;
    void initializeItems(); // TODO: Replace it with the JSON file
};

#endif // INVENTORYMODEL_H
