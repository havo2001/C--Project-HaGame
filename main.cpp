#include <QApplication>
#include "include/hagame.h"
#include "include/menu.h"

HaGame *newGame;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  newGame = new HaGame();
  newGame->show();
  newGame->start();
  return a.exec();
}
