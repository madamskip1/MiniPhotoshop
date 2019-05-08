#ifndef DISPLAYIMAGELABEL_H
#define DISPLAYIMAGELABEL_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class DisplayImageLabel : public QLabel
{
    Q_OBJECT
public:
    explicit DisplayImageLabel(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
signals:
    void mouseLeftClick(QMouseEvent*);
    void mouseRightClick(QMouseEvent*);
    void mouseMiddleClick(QMouseEvent*);
    void mouseMove(QMouseEvent*);
    void mouseLeftRelease(QMouseEvent*);
    void mouseRightRelease(QMouseEvent*);
public slots:

};

#endif // DISPLAYIMAGELABEL_H
