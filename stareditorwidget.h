#ifndef STAREDITORWIDGET_H
#define STAREDITORWIDGET_H

#include <QWidget>

class StarEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StarEditorWidget(QWidget *parent = nullptr);

    int starRating() const;
    void setStarRating(int newStarRating);

    // QWidget interface
    //virtual QSize sizeHint() const override;

signals:
    void editingFinished();

    // QWidget interface
protected:
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

private:
    int      m_starRating;
    QPolygon m_poly;
};

#endif // STAREDITORWIDGET_H
