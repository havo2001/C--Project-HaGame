#include "include/score.h"
#include <QFont>
#include <QFontDatabase>

const QString fontPath = ":/font/AmongYou-BWdWw.ttf";
const int initScore = 0;
const int fontSize = 15;
std::pair<int, int> initPos(730 ,70);

score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
  total = initScore;
  QFontDatabase::addApplicationFont(fontPath);
  QFont font("a Among You", fontSize);
  setPos(initPos.first, initPos.second);
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
