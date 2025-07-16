#include "imagedelegate.h"
#include <QPainter>
#include <QFileDialog>

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

QWidget *ImageDelegate::createEditor(QWidget *parent,
                    const QStyleOptionViewItem &option,
                    const QModelIndex &index) const
{
    QString imagePath = QFileDialog::getOpenFileName(parent, "Select Image", QString(),
                                 "Images (*.png *.jpg *.jpeg *.bmp *.gif)");

    if (!imagePath.isEmpty()) {
        QImage image(imagePath);
        if (!image.isNull()) {
            QAbstractItemModel *model = const_cast<QAbstractItemModel *>(index.model());
            model->setData(index, QVariant::fromValue(image), Qt::EditRole);
            model->setData(index, imagePath, Qt::UserRole + 1);
        }
    }

    return nullptr;
}
