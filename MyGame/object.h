#ifndef OBJECT_H
#define OBJECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class object : public QGraphicsPixmapItem {
 public:
  object(QGraphicsItem *parent = 0);
  QString getDirection();
  void setDirection(QString value);
  void keyPressEvent(QKeyEvent *event);

 private:
  QString direction;
};

#endif // OBJECT_H
