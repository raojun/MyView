#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>

class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyView(QWidget *parent = 0);

signals:

public slots:

protected:
    void keyPressEvent(QKeyEvent *event);//键盘按下事件

};

#endif // MYVIEW_H
