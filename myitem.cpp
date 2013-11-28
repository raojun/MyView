#include "myitem.h"
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QGraphicsEffect>

MyItem::MyItem()
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);

}

QRectF MyItem::boundingRect() const
{
    qreal adjust=0.5;
    return QRectF(-10-adjust,-10-adjust,20+adjust,20+adjust);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//执行实际的绘图操作
{
    if(hasFocus())//如果获得焦点
    {
        painter->setPen(QPen(QColor(255,255,255,200)));
    }
    else
    {
        painter->setPen(QPen(QColor(100,100,100,100)));
    }
    painter->setBrush(brushColor);//使用变量作为画刷的颜色，可以动态指定图形项的填充色
    painter->drawRect(-10,-10,20,20);
}

//鼠标按下事件处理函数，设置边点击的图形项获得焦点，并改变光标外观
void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus();
    setCursor(Qt::ClosedHandCursor);
}

//键盘按下事件处理函数，判断是否是"-"键，如果是，则向下移动图形项
void MyItem::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_S)
    {
        moveBy(0,10);
    }
    else if(event->key()==Qt::Key_W)
    {
        moveBy(0,-10);
    }
    else if(event->key()==Qt::Key_A)
    {
        moveBy(-10,0);
    }
    else if(event->key()==Qt::Key_D)
    {
        moveBy(10,0);
    }

    /*
     *QGraphicsBlurEffect类提供了一个模糊效果
     *QGraphicsColorizeEffect类提供了一个染色效果
     *QGraphicsDropShadowEffect类提供了一个阴影效果
     *QGraphicsOpacityEffect类提供了一个透明效果
     */
    switch (event->key())
    {
        case Qt::Key_1:
        {
            QGraphicsBlurEffect *blurEffect=new QGraphicsBlurEffect;
            blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);//指定模糊怎样来执行
            blurEffect->setBlurRadius(8);//修改细节等级，默认的模糊半径是5像素
            setGraphicsEffect(blurEffect);
            break;
        }
        case Qt::Key_2:
        {
            QGraphicsColorizeEffect *colorizeEffect=new QGraphicsColorizeEffect;
            colorizeEffect->setColor(Qt::white);//修改颜色，默认是浅紫色
            colorizeEffect->setStrength(0.6);//修改效果强度
            setGraphicsEffect(colorizeEffect);
            break;
        }
        case Qt::Key_3:
        {
            QGraphicsDropShadowEffect *dropShadowEffect=new QGraphicsDropShadowEffect;
            dropShadowEffect->setColor(QColor(63,63,63,100));//修改阴影颜色，默认是透明的黑灰色
            dropShadowEffect->setBlurRadius(2);//改变模糊半径
            dropShadowEffect->setOffset(10);//改变阴影偏移值
            setGraphicsEffect(dropShadowEffect);
            break;
        }
        case Qt::Key_4:
        {
            QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
            opacityEffect->setOpacity(0.4);//修改透明度
            setGraphicsEffect(opacityEffect);
            break;
        }
        case Qt::Key_5:
        {
            graphicsEffect()->setEnabled(false);
            break;
        }

    }
}

//悬停事件处理函数，设置光标外观
void MyItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    setToolTip("This is a item");
}

//右键菜单事件处理函数，为图形项添加一个右键菜单
void MyItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *moveAction=menu.addAction("move back");
    QAction *seclectedAction=menu.exec(event->screenPos());
    if(seclectedAction==moveAction)
    {
        setPos(0,0);
    }
}
