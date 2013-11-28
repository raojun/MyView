#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>

class MyItem : public QGraphicsItem
{
public:
    MyItem();
    void advance(int phase);//使用QGraphicsScene::advance()推进场景，实现动画效果
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setColor(const QColor &color)//用于设置图形项填充颜色
    {
        brushColor=color;
    }

    QPainterPath shape();

private:
    QColor brushColor;//保存图形项的填充颜色

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
};

#endif // MYITEM_H
