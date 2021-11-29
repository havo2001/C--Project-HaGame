#include "hagame.h"
const int fixed_size = 6;

HaGame::HaGame(QWidget *parent) : QGraphicsView(parent) {
  // Set value x,y:
  posX = 400;
  posY = 100;

  // Set up the matrix
  matrix = new int *[fixed_size];
  for (int i = 0; i < fixed_size; i++) {
    matrix[i] = new int[fixed_size];
  }
  for (int i = 0; i < fixed_size; i++) {
    for (int j = 0; j < fixed_size; j++) {
      matrix[i][j] = 0;
    }
  }
  // set value for matrix:
  // 1: rocks
  // 2: question
  matrix[5][0] = 1;
  matrix[3][1] = 1;
  matrix[1][2] = 1;
  matrix[3][2] = 1;
  matrix[5][2] = 1;
  matrix[3][3] = 1;
  matrix[1][4] = 1;
  matrix[3][4] = 1;
  matrix[4][4] = 1;

  matrix[2][0] = 2;
  matrix[0][2] = 2;
  matrix[2][2] = 2;
  matrix[4][2] = 2;
  matrix[1][3] = 2;
  matrix[1][5] = 2;
  matrix[3][5] = 2;
  matrix[1][1] = 2;
  matrix[0][4] = 2;
  matrix[2][4] = 2;
  matrix[5][4] = 2;

  matrix[5][5] = 3;


  // Make an array of questions
  question = new QGraphicsPixmapItem **[fixed_size];
  for (int i = 0; i < fixed_size; i++) {
    question[i] = new QGraphicsPixmapItem *[fixed_size];
  }

  setFixedSize(900, 600);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


  // Set background
  scene = new QGraphicsScene(this);
  scene->setSceneRect(0, 0, 900, 600);
  QGraphicsPixmapItem *bg = new QGraphicsPixmapItem();
  bg->setPixmap(QPixmap(":/image/background.jpg").scaled(900, 600));


  //Set matrix
  QGraphicsPixmapItem *matrix = new QGraphicsPixmapItem();
  matrix->setPixmap(QPixmap(":/image/matrix.png").scaled(480, 480));
  matrix->setPos(400, 100);


  //Set rocks
  QGraphicsPixmapItem *rock61 = new QGraphicsPixmapItem();
  rock61->setPixmap(QPixmap(":/image/rock.png").scaled(78, 78));
  rock61->setPos(801, 100);

  QGraphicsPixmapItem *rock42 = new QGraphicsPixmapItem();
  rock42->setPixmap(QPixmap(":/image/rock.png").scaled(78, 78));
  rock42->setPos(640, 180);

  QGraphicsPixmapItem *rock23 = new QGraphicsPixmapItem();
  rock23->setPixmap(QPixmap(":/image/rock.png").scaled(78, 78));
  rock23->setPos(480, 261);

  QGraphicsPixmapItem *rock43 = new QGraphicsPixmapItem();
  rock43->setPixmap(QPixmap(":/image/rock.png").scaled(78, 78));
  rock43->setPos(640, 261);

  QGraphicsPixmapItem *rock63 = new QGraphicsPixmapItem();
  rock63->setPixmap(QPixmap(":/image/rock.png").scaled(78, 78));
  rock63->setPos(801, 261);

  QGraphicsPixmapItem *rock44 = new QGraphicsPixmapItem();
  rock44->setPixmap(QPixmap(":/image/rock.png").scaled(78, 78));
  rock44->setPos(640, 341);

  QGraphicsPixmapItem *rock25 = new QGraphicsPixmapItem();
  rock25->setPixmap(QPixmap(":/image/rock.png").scaled(78, 78));
  rock25->setPos(480, 421);

  QGraphicsPixmapItem *rock45 = new QGraphicsPixmapItem();
  rock45->setPixmap(QPixmap(":/image/rock.png").scaled(78, 78));
  rock45->setPos(640, 421);

  QGraphicsPixmapItem *rock55 = new QGraphicsPixmapItem();
  rock55->setPixmap(QPixmap(":/image/rock.png").scaled(78, 78));
  rock55->setPos(721, 421);

  //Set questions:
  question[0][2] = new QGraphicsPixmapItem();
  question[0][2]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[0][2]->setPos(400, 260);

  question[2][0] = new QGraphicsPixmapItem();
  question[2][0]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[2][0]->setPos(560, 100);

  question[2][2] = new QGraphicsPixmapItem();
  question[2][2]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[2][2]->setPos(560, 260);

  question[4][2] = new QGraphicsPixmapItem();
  question[4][2]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[4][2]->setPos(720, 260);

  question[1][3] = new QGraphicsPixmapItem();
  question[1][3]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[1][3]->setPos(480, 340);

  question[1][5] = new QGraphicsPixmapItem();
  question[1][5]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[1][5]->setPos(480, 500);

  question[3][5] = new QGraphicsPixmapItem();
  question[3][5]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[3][5]->setPos(640, 500);

  question[1][1] = new QGraphicsPixmapItem();
  question[1][1]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[1][1]->setPos(480, 180);

  question[0][4] = new QGraphicsPixmapItem();
  question[0][4]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[0][4]->setPos(400, 420);

  question[2][4] = new QGraphicsPixmapItem();
  question[2][4]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[2][4]->setPos(560, 420);

  question[5][4] = new QGraphicsPixmapItem();
  question[5][4]->setPixmap(QPixmap(":/image/question.png").scaled(80, 80));
  question[5][4]->setPos(800, 420);


  // Set the prize:
  QGraphicsPixmapItem *prize = new QGraphicsPixmapItem();
  prize->setPixmap(QPixmap(":/image/prize.png").scaled(80, 80));
  prize->setPos(800, 500);
  scene->addItem(bg);
  scene->addItem(matrix);
  scene->addItem(rock61);
  scene->addItem(rock42);
  scene->addItem(rock23);
  scene->addItem(rock43);
  scene->addItem(rock63);
  scene->addItem(rock44);
  scene->addItem(rock25);
  scene->addItem(rock45);
  scene->addItem(rock55);
  scene->addItem(question[0][2]);
  scene->addItem(question[2][0]);
  scene->addItem(question[2][2]);
  scene->addItem(question[4][2]);
  scene->addItem(question[1][3]);
  scene->addItem(question[1][5]);
  scene->addItem(question[3][5]);
  scene->addItem(question[1][1]);
  scene->addItem(question[0][4]);
  scene->addItem(question[2][4]);
  scene->addItem(question[5][4]);

  scene->addItem(prize);
  setScene(scene);

  q = nullptr;
  variant = 0;
  numberQuestion = 0;
  totalQuestion = 0;
  totalCorrect = 0;
  answerQuestion = false;
  gameOver = false;
  mainMenu = new menu();
  scene->addItem(mainMenu);
  mainMenu->setVisible(true);
  gameScore = new score();
  scene->addItem(gameScore);

}

//Function to take the random question
int HaGame::Random(int a, int b) {
  int n = b - a + 1;
  return (rand() % n + 1);
}

//DFS for checking game over
void HaGame::DFS(int **temp, int n, int m, bool &flag) {
  if (n < 0 || n >= fixed_size || m < 0 || m >= 6)
    return;
  if (temp[n][m] == 1)
    return;
  if (n == 5 && m == 5) {
    flag = true;
    return;
  }
  temp[n][m] = 1;
  DFS(temp, n + 1, m, flag);
  DFS(temp, n - 1, m, flag);
  DFS(temp, n, m - 1, flag);
  DFS(temp, n, m + 1, flag);
}

//Convert position into coordinate in matrix
int HaGame::xCoor(int posX) {
    return (posX - 400) / 80;
}

int HaGame::yCoor(int posY) {
    return (posY - 100) / 80;
}

void HaGame::GetQuestion() {
  if (matrix[xCoor(posX)][yCoor(posY)] == 2) {
    q = new questionlist();
    scene->addItem(q);
    numberQuestion = Random(1, 30);
    QString quiz = q->content(numberQuestion);
    text = new QGraphicsTextItem(quiz);
    QFontDatabase::addApplicationFont(":/font/AmongYou-BWdWw.ttf");
    QFont font("a Among You", 15);
    text->setFont(font);
    text->setPos(50, 270);
    text->setDefaultTextColor(QColor(125, 211, 217, 255));
    scene->addItem(text);

    QString info = "Press the key 1, 2, 3 to answer the question";
    note = new QGraphicsTextItem(info);
    QFont font2("a Among You", 8);
    note->setFont(font2);
    note->setPos(40, 400);
    note->setDefaultTextColor(QColor("white"));
    scene->addItem(note);
    answerQuestion = true;
  }
}

void HaGame::AnswerQuestion() {
  if (variant != 0 && numberQuestion != 0) {
    if (q->answer(numberQuestion, variant)) {
      scene->removeItem(q);
      scene->removeItem(text);
      scene->removeItem(note);
      question[xCoor(posX)][yCoor(posY)]->setPixmap(QPixmap(":/image/pass.png").scaled(80, 80));
      matrix[xCoor(posX)][yCoor(posY)] = 0; // if answer is true
      if (totalCorrect == totalQuestion) {
        gameScore->setScore(gameScore->getScore() + 50);
      } else {
        gameScore->setScore(gameScore->getScore() + 50 - (totalQuestion - totalCorrect) * 5);
      }
      variant = 0;
      numberQuestion = 0;
      answerQuestion = false;
      totalQuestion++;
      totalCorrect++;
    } else {
      scene->removeItem(q);
      scene->removeItem(text);
      scene->removeItem(note);
      question[xCoor(posX)][yCoor(posY)]->setPixmap(QPixmap(":/image/notpass.png").scaled(80, 80));
      matrix[xCoor(posX)][yCoor(posY)] = 1; // if answer is false
      variant = 0;
      numberQuestion = 0;
      if (mainObject->getDirection() == "Up") {
        posY += 80;
        mainObject->setPos(posX, posY);
        mainObject->setDirection("STOP");
      }
      if (mainObject->getDirection() == "Down") {
        posY -= 80;
        mainObject->setPos(posX, posY);
        mainObject->setDirection("STOP");
      }
      if (mainObject->getDirection() == "Left") {
        posX += 80;
        mainObject->setPos(posX, posY);
        mainObject->setDirection("STOP");
      }
      if (mainObject->getDirection() == "Right") {
        posX -= 80;
        mainObject->setPos(posX, posY);
        mainObject->setDirection("STOP");
      }
      answerQuestion = false;
      totalQuestion++;
      CheckGameOver();
      if (gameOver) {
        LoseMenu();
      }
    }
  }
}

//Lose menu
void HaGame::LoseMenu() {
  QGraphicsPixmapItem *lose = new QGraphicsPixmapItem();
  lose->setPixmap(QPixmap(":/image/lose.png").scaled(550, 370));
  lose->setPos(180, 115);
  scene->addItem(lose);
  gameScore->setScore(0);
}

//Win menu
void HaGame::WinMenu() {
  QGraphicsPixmapItem *win = new QGraphicsPixmapItem();
  win->setPixmap(QPixmap(":/image/win.png").scaled(550, 370));
  win->setPos(180, 115);
  scene->addItem(win);
  if (totalQuestion == 3) {
    gameScore->setScore(gameScore->getScore() + 1000);
  } else {
    gameScore->setScore(gameScore->getScore() + 1000 - (totalQuestion - 3) * 100);
  }
  QString total = QString::number(gameScore->getScore());
  text = new QGraphicsTextItem(total);
  QFontDatabase::addApplicationFont(":/font/AmongYou-BWdWw.ttf");
  QFont font("a Among You", 20);
  text->setFont(font);
  text->setPos(430, 370);
  text->setDefaultTextColor(QColor("white"));
  scene->addItem(text);
}


void HaGame::CheckGameOver() {
  bool flag = false;
  int **temp;
  temp = new int *[fixed_size];
  for (int i = 0; i < fixed_size; i++) {
    temp[i] = new int[fixed_size];
  }
  for (int i = 0; i < fixed_size; i++) {
    for (int j = 0; j < fixed_size; j++) {
      temp[i][j] = matrix[i][j];
    }
  }
  DFS(temp, xCoor(posX), yCoor(posY), flag);
  if (flag)
    gameOver = false;
  else
    gameOver = true;
}



void HaGame::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Down && !answerQuestion) {
    if (matrix[xCoor(posX)][yCoor(posY) + 1] != 1 && posY < 500) {
      posY += 80;
      mainObject->keyPressEvent(event);
      GetQuestion();
      if (xCoor(posX) == 5 && yCoor(posY) == 5)
        WinMenu();
      mainObject->setDirection("Down");
    }
  }

  if (event->key() == Qt::Key_Up && !answerQuestion) {
    if (matrix[xCoor(posX)][yCoor(posY) - 1] != 1 && posY > 100) {
      posY -= 80;
      mainObject->keyPressEvent(event);
      GetQuestion();
      if (xCoor(posX) == 5 && yCoor(posY) == 5)
        WinMenu();
      mainObject->setDirection("Up");
    }
  }

  if (event->key() == Qt::Key_Left && !answerQuestion) {
    if (matrix[xCoor(posX) - 1][yCoor(posY)] != 1 && posX > 400) {
      posX -= 80;
      mainObject->keyPressEvent(event);
      GetQuestion();
      if (xCoor(posX) == 5 && yCoor(posY) == 5)
        WinMenu();
      mainObject->setDirection("Left");
    }
  }
  if (event->key() == Qt::Key_Right && !answerQuestion) {
    if (matrix[xCoor(posX) + 1][yCoor(posY)] != 1 && posX < 800) {
      posX += 80;
      mainObject->keyPressEvent(event);
      GetQuestion();
      if (xCoor(posX) == 5 && yCoor(posY) == 5)
        WinMenu();
      mainObject->setDirection("Right");
    }
  }

  if (event->key() == Qt::Key_1) {
    variant = 1;
    mainObject->keyPressEvent(event);
    AnswerQuestion();
  }

  if (event->key() == Qt::Key_2) {
    variant = 2;
    mainObject->keyPressEvent(event);
    AnswerQuestion();
  }

  if (event->key() == Qt::Key_3) {
    variant = 3;
    mainObject->keyPressEvent(event);
    AnswerQuestion();
  }
  if (event->key() == Qt::Key_Space) {
    mainObject->keyPressEvent(event);
    mainMenu->setVisible(false);
    mainObject->setVisible(true);
    gameScore->setVisible(true);

  }
}


void HaGame::start() {
  mainObject = new object();
  mainObject->setVisible(false);
  mainObject->setFlag(QGraphicsItem::ItemIsFocusable);
  mainObject->setFocus();
  scene->addItem(mainObject);
  gameScore->setScore(0);
  gameScore->setVisible(false);

}
