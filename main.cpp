/*
 *图形视图框架的特征
 *
 *使用QGraphicsScene类的setFoucsItem()函数
 *或者图形项自身调用setFoucs()函数来将其设置为焦点图形项。
 *调用了场景的setFoucs()函数或者场景中的一个图形项获得了焦点，那么场景也会自动获得焦点；
 *如果场景失去了焦点，而它的一个图形项获得有焦点，那么场景会保存这个图形项的焦点信息，
 *当场景重新获得焦点后，就会确保最后一个焦点项目重新获得焦点
 *
 *使用图形效果来改变元素的外观是通过在源对象(如一个图形项)和目标设备(如视图的窗口)之间挂接
 *了渲染通道和一些操作来实现的。
 *图形效果可以实施在任何一个图形项或者非顶层的任何一个窗口部件上。
 *创建一个图形效果对象，调用setGraphicsEffect()使用这个图形效果，
 *setEnabled(false)停止使用效果
 *
 */

#include <QApplication>
#include <QTime>
#include "myitem.h"
#include "myview.h"

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QGraphicsScene scene;
    scene.setSceneRect(-200,-150,400,300);
    for(int i=0;i<5;i++)//在场景中添加了5个图形项
    {
        MyItem *item=new MyItem;
        item->setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
        item->setPos(i*50-90,-50);
        scene.addItem(item);
    }
    MyView view;
    view.setScene(&scene);
    view.setBackgroundBrush(QPixmap("../myView/background.png"));
    view.show();

    return app.exec();
}
