#include "inventoryitemdetailswidget.h"
#include "ui_inventoryitemdetailswidget.h"
#include "inventoryitem.h"

InventoryItemDetailsWidget::InventoryItemDetailsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InventoryItemDetailsWidget)
    , m_prevDetailedDescription("")
{
    ui->setupUi(this);

    initGUI();
}

InventoryItemDetailsWidget::~InventoryItemDetailsWidget()
{
    delete ui;
}

void InventoryItemDetailsWidget::setItemInfo(const InventoryItem *item)
{
    if (item) {
        ui->txtProduct->setText(item->productName());
        ui->txtQuantity->setText(QString::number(item->quantity()));
        ui->txtSupplier->setText(item->supplier());

        QPixmap pixmap(item->imagePath());
        if (!pixmap.isNull()) {
            QSize targetSize = ui->lblPixmap->size();
            QPixmap scaledPixmap = pixmap.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->lblPixmap->setPixmap(scaledPixmap);
        }

        ui->txtRating->setText(QString::number(item->rating()));
        m_prevDetailedDescription = item->description();
        ui->textEditDescription->setText(m_prevDetailedDescription);
    }
}

void InventoryItemDetailsWidget::initGUI()
{
    ui->lblPixmap->setMinimumSize(100, 300);
    ui->lblPixmap->setAlignment(Qt::AlignCenter);
    ui->lblPixmap->setStyleSheet("background-color: white;");
}

void InventoryItemDetailsWidget::on_textEditDescription_textChanged()
{
    QString currentText = ui->textEditDescription->toPlainText();
    if (currentText != m_prevDetailedDescription)
        emit descriptionChanged(currentText);
}

