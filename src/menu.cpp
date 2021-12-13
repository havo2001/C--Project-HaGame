#include "include/menu.h"

const int widthSize = 900;
const int heightSize = 600;
const std::pair <int, int> initPos(0, 0);

menu::menu(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
  setPixmap(QPixmap(":/image/background1.jpg").scaled(widthSize, heightSize));
  setPos(initPos.first, initPos.second);
}
