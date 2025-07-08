#include "stareditorwidget.h"
#include <QPolygon>
#include <QMouseEvent>
#include <QPainter>

StarEditorWidget::StarEditorWidget(QWidget *parent)
    : QWidget{parent}, m_starRating(0)
{
    // Should be enabled for mouse events.
    setMouseTracking(true);

    m_poly << QPoint(0, 85) << QPoint(75, 75) << QPoint(100, 10)
           << QPoint(125, 75) << QPoint(200, 85) << QPoint(150, 125)
           << QPoint(160, 190) << QPoint(100, 150) << QPoint(40, 190)
           << QPoint(50, 125) << QPoint(0, 85);
}

void StarEditorWidget::mouseReleaseEvent(QMouseEvent *event)
{
    emit editingFinished();
}

// We assume that the editor square has a width of 100 and each
// star will occupy a width of 20. As we move the mouse,
// the star rating changes.
void StarEditorWidget::mouseMoveEvent(QMouseEvent *event)
{
    int rating = (event->position().x()) / 20;

    if (rating != m_starRating && rating < 6) {
        m_starRating = rating;
        update();
    }
}

void StarEditorWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.save();

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::green));
    painter.drawRect(rect());

    painter.setBrush(QBrush(Qt::yellow));

    painter.translate(rect().x(), rect().y() + 5);
    // The coordinate system is scaled down to 10% of its original size.
    painter.scale(0.1, 0.1);

    for (int i = 0; i < m_starRating; ++i) {
        painter.drawPolygon(m_poly);
        painter.translate(220, 0);
    }

    painter.restore();
}

int StarEditorWidget::starRating() const
{
    return m_starRating;
}

void StarEditorWidget::setStarRating(int newStarRating)
{
    m_starRating = newStarRating;
}

// QSize StarEditorWidget::sizeHint() const
// {
//     return QSize(110, 25);
// }
