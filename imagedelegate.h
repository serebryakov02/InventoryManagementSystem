#ifndef IMAGEDELEGATE_H
#define IMAGEDELEGATE_H

#include <QStyledItemDelegate>

class ImageDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ImageDelegate(QObject *parent = nullptr);

    // QAbstractItemDelegate interface
    virtual void paint(QPainter *painter,
            const QStyleOptionViewItem &option,
            const QModelIndex &index) const override;
    virtual QWidget *createEditor(QWidget *parent,
            const QStyleOptionViewItem &option,
            const QModelIndex &index) const override;
};

#endif // IMAGEDELEGATE_H
