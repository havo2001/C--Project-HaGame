#ifndef QUESTIONLIST_H
#define QUESTIONLIST_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class questionlist : public QGraphicsPixmapItem {
 public:
  questionlist(QGraphicsItem *parent = 0);
  QString content(int i);
  bool answer(int i, int variant);
};
#endif // QUESTIONLIST_H
