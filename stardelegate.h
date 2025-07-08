#ifndef STARDELEGATE_H
#define STARDELEGATE_H

#include <QStyledItemDelegate>

class StarDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    StarDelegate(QObject *parent = nullptr);

    // QAbstractItemDelegate interface
    virtual QWidget *createEditor(QWidget *parent,
                                  const QStyleOptionViewItem &option,
                                  const QModelIndex &index) const override;
    virtual void setEditorData(QWidget *editor,
                               const QModelIndex &index) const override;
    virtual void setModelData(QWidget *editor,
                              QAbstractItemModel *model, const QModelIndex &index) const override;
    virtual void paint(QPainter *painter,
                       const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private slots:
    void commitAndCloseEditor();

private:
    QPolygon m_poly;
};

#endif // STARDELEGATE_H
