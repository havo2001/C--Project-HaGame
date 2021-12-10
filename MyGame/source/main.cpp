#include <QApplication>
#include "../header/hagame.h"
#include "../header/menu.h"

HaGame *newGame;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  newGame = new HaGame();
  newGame->show();
  newGame->start();
  return a.exec();
}
