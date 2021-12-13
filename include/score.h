#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
class score : public QGraphicsTextItem {
 public:
  score(QGraphicsItem *parent = 0);
  int getScore();
  void setScore(int value);
 private:
  int total;
};

#endif // SCORE_H
