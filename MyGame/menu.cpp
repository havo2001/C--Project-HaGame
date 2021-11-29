#include "menu.h"

menu::menu(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
  setPixmap(QPixmap(":/image/background1.jpg").scaled(900, 600));
  setPos(0, 0);
}
