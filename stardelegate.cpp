#include "stardelegate.h"
#include "stareditorwidget.h"
#include <QPainter>

StarDelegate::StarDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
    m_poly << QPoint(0, 85) << QPoint(75, 75) << QPoint(100, 10)
    << QPoint(125, 75) << QPoint(200, 85) << QPoint(150, 125)
    << QPoint(160, 190) << QPoint(100, 150) << QPoint(40, 190)
    << QPoint(50, 125) << QPoint(0, 85);
}

QWidget *StarDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid() && index.column() == 4) {
        int rating = index.data(Qt::DisplayRole).toInt();
        StarEditorWidget *widget = new StarEditorWidget(parent);
        widget->setStarRating(rating);
        QObject::connect(widget, &StarEditorWidget::editingFinished,
                         this, &StarDelegate::commitAndCloseEditor);
        return widget;
    } else {
        QStyledItemDelegate::createEditor(parent, option, index);
    }
}

void StarDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.isValid() && index.column() == 4) {
        int rating = index.data(Qt::DisplayRole).toInt();
        StarEditorWidget *widget = static_cast<StarEditorWidget*>(editor);
        widget->setStarRating(rating);
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void StarDelegate::setModelData(QWidget *editor,
                                QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.isValid() && index.column() == 4) {
        StarEditorWidget *widget = static_cast<StarEditorWidget*>(editor);
        model->setData(index,
                       QVariant::fromValue(widget->starRating()), Qt::EditRole);
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void StarDelegate::commitAndCloseEditor()
{
    StarEditorWidget *editor = static_cast<StarEditorWidget*>(sender());
    emit commitData(editor);
    emit closeEditor(editor);
}

void StarDelegate::paint(QPainter *painter,
                         const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid() && index.column() == 4) {
        int starNumber = index.data(Qt::DisplayRole).toInt();

        painter->save();

        painter->setRenderHint(QPainter::Antialiasing, true);

        QPen pen;
        pen.setStyle(Qt::SolidLine);
        pen.setColor(QColor(Qt::black));
        painter->setPen(pen);
        painter->setBrush(QBrush(Qt::yellow));

        constexpr double scaleFactor = 0.1;
        int starHeight = 190;

        // Vertically center the star shape within the cell.
        int translatedY = option.rect.y() + (option.rect.height() -
                                             starHeight * scaleFactor) / 2;
        painter->translate(option.rect.x(), translatedY);
        // The coordinate system is scaled down to 10% of its original size.
        painter->scale(scaleFactor, scaleFactor);
        for (int i = 0; i < starNumber; ++i) {
            painter->drawPolygon(m_poly);
            painter->translate(220, 0);
        }

        painter->setBrush(QBrush(Qt::white));

        int unfilledStars = 5 - starNumber;
        for (int i = 0; i < unfilledStars; ++i) {
            painter->drawPolygon(m_poly);
            painter->translate(220, 0);
        }

        painter->restore();
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}
