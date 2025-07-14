#include "supplierdelegate.h"
#include <QComboBox>

SupplierDelegate::SupplierDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{
    m_supplierList = {
        "Seiko Japan", "Omega SA", "Rolex Geneva", "TAG Heuer SA",
        "Tissot Switzerland", "Longines SA", "Casio Tokyo",
        "Citizen Watch Co.", "Hamilton Watch Company",
        "Breitling SA", "Invicta Watch Group", "Timex USA"
    };
}

QWidget *SupplierDelegate::createEditor(QWidget *parent,
            const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid() && index.column() == 2) {
        QComboBox *editor = new QComboBox(parent);
        editor->setStyleSheet("QComboBox { background-color: black; color: white }");
        for (const auto &supplier : m_supplierList)
            editor->addItem(supplier);
        return editor;
    }
    return QStyledItemDelegate::createEditor(parent, option, index);
}

void SupplierDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.isValid() && index.column() == 2) {
        QString value = index.data(Qt::EditRole).toString();
        QComboBox *comboBox = static_cast<QComboBox*>(editor);
        comboBox->setCurrentText(value);
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void SupplierDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    if (index.isValid() && index.column() == 2) {
        QComboBox *comboBox = static_cast<QComboBox*>(editor);
        QString value = comboBox->currentText();
        model->setData(index, value, Qt::EditRole);
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void SupplierDelegate::updateEditorGeometry(QWidget *editor,
            const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid() && index.column() == 2)
        editor->setGeometry(option.rect);
    else
        QStyledItemDelegate::updateEditorGeometry(editor, option, index);
}

void SupplierDelegate::setSupplierList(const QStringList &newSupplierList)
{
    m_supplierList = newSupplierList;
}

QStringList SupplierDelegate::supplierList() const
{
    return m_supplierList;
}
