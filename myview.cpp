#include "myview.h"
#include <QKeyEvent>

MyView::MyView(QWidget *parent) :
    QGraphicsView(parent)
{
}

void MyView::keyPressEvent(QKeyEvent *event)//键盘按下事件
{
    switch (event->key())
    {
    case Qt::Key_Up://“上”放大视图
        scale(1.2,1.2);
        break;
    case Qt::Key_Down://"下"缩小视图
        scale(1/1.2,1/1.2);\
        break;
    case Qt::Key_Right://“->”旋转视图
        rotate(10);
        break;
    case Qt::Key_Left://“<-”旋转视图
        rotate(-10);
        break;
    }
    QGraphicsView::keyPressEvent(event);
}
