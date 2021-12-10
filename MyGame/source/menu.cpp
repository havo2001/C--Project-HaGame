#include "menu.h"
const int widthSize = 900;
const int heightSize = 600;
menu::menu(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
  setPixmap(QPixmap(":/image/background1.jpg").scaled(widthSize, heightSize));
  setPos(0, 0);
}
