#include "include/menu.h"


const int widthSize = 900;
const int heightSize = 600;
const std::pair <int, int> initPos(0, 0);
const QString backgroundImage = ":/image/background1.jpg";

menu::menu(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
  setPixmap(QPixmap(backgroundImage).scaled(widthSize, heightSize));
  setPos(initPos.first, initPos.second);
}
