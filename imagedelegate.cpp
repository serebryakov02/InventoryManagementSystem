#include "imagedelegate.h"
#include <QPainter>

ImageDelegate::ImageDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{}

void ImageDelegate::paint(QPainter *painter,
        const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QImage image = index.data().value<QImage>();
    if (!image.isNull()) {
        // Scale the image to a fixed size
        QPixmap pixmap = QPixmap::fromImage(image).scaled(64, 64,
                            Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // Calculate x and y to center the image
        int x = option.rect.x() + (option.rect.width() - pixmap.width()) / 2;
        int y = option.rect.y() + (option.rect.height() - pixmap.height()) / 2;

        painter->drawPixmap(x, y, pixmap);
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}
