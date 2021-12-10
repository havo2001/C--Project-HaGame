#include "score.h"
#include <QFont>
#include <QFontDatabase>
score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
  total = 0;
  QFontDatabase::addApplicationFont(":/font/AmongYou-BWdWw.ttf");
  QFont font("a Among You", 15);
  setPos(730, 70);
  setFont(font);
  setDefaultTextColor(QColor(125, 211, 217, 255));

}
int score::getScore() {
  return total;
}
void score::setScore(int value) {
  total = value;
  setPlainText("Score: " + QString::number(total));
}
