#ifndef SUPPLIERDELEGATE_H
#define SUPPLIERDELEGATE_H

#include <QStyledItemDelegate>

class SupplierDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit SupplierDelegate(QObject *parent = nullptr);

    // QAbstractItemDelegate interface
    virtual QWidget *createEditor(QWidget *parent,
                const QStyleOptionViewItem &option,
                const QModelIndex &index) const override;
    virtual void setEditorData(QWidget *editor,
                const QModelIndex &index) const override;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model,
                const QModelIndex &index) const override;
    virtual void updateEditorGeometry(QWidget *editor,
                const QStyleOptionViewItem &option,
                const QModelIndex &index) const override;

    void setSupplierList(const QStringList &newSupplierList);

private:
    QStringList m_supplierList;
};

#endif // SUPPLIERDELEGATE_H
