#include "include/object.h"

#include<QBrush>
#include<QDebug>

#include<QBrush>
#include<QDebug>

const int xStart = 400;
const int yStart = 100;
const int itemSize = 80;
const QString objectImage = ":/image/object.png";

object::object(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
  setPixmap(QPixmap(objectImage).scaled(itemSize, itemSize));
  setPos(xStart, yStart);
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
    setPos(x(), y() + itemSize);
  if (event->key() == Qt::Key_Up)
    setPos(x(), y() - itemSize);
  if (event->key() == Qt::Key_Left)
    setPos(x() - itemSize, y());
  if (event->key() == Qt::Key_Right)
    setPos(x() + itemSize, y());
}





