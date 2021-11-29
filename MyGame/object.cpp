#include "object.h"

#include<QBrush>
#include<QDebug>
#include "hagame.h"

extern HaGame *game;
object::object(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
  setPixmap(QPixmap(":/image/object.png").scaled(80, 80));
  setPos(400, 100);
  setDirection("STOP");
}

QString object::getDirection() {
  return direction;
}

void object::setDirection(QString value) {
  direction = value;
}

void object::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Down)
    setPos(x(), y() + 80);
  if (event->key() == Qt::Key_Up)
    setPos(x(), y() - 80);
  if (event->key() == Qt::Key_Left)
    setPos(x() - 80, y());
  if (event->key() == Qt::Key_Right)
    setPos(x() + 80, y());
}





