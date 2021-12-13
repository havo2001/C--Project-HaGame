#ifndef HAGAME_H
#define HAGAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QFontDatabase>
#include "object.h"
#include "questionlist.h"
#include "menu.h"
#include "score.h"

class HaGame : public QGraphicsView {
  Q_OBJECT
 public:
  HaGame(QWidget *parent = 0);
  QGraphicsScene *scene;
  QGraphicsPixmapItem ***question;
  QGraphicsPixmapItem *** rock;
  QGraphicsTextItem *text;
  QGraphicsTextItem *note;
  QGraphicsPixmapItem* questionPosition(int posX, int posY);

  object *mainObject;
  menu *mainMenu;
  questionlist *questionObject;
  score *gameScore;

  int **matrix;
  int posX;
  int posY;

  void WinMenu();
  void LoseMenu();
  void GetQuestion();
  void AnswerQuestion();
  void keyPressEvent(QKeyEvent *event);
  void CheckGameOver();

  bool answerQuestion;
  int variant;
  int numberQuestion;
  bool gameOver;
  int totalQuestion;
  int totalCorrect;

  void Dfs(int **temp, int w, int h, bool &flag);
  int Random(int first, int second);
  int GetCoordX(int posX);
  int GetCoordY(int posY);


 public
  slots:
      void start();
};

#endif // HAGAME_H
