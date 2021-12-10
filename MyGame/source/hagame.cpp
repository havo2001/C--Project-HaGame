#include "../header/hagame.h"

const int fixedSize = 6;
const int blank = 0;
const int rockValue = 1;
const int questionValue = 2;
const int prizeValue = 3;
const int itemSize = 80;
const int xStart = 400;
const int yStart = 100;
const int widthSize = 900;
const int heightSize = 600;
const int xOrigin = 0;
const int yOrigin = 0;
const int gridSize = 480;
const int questionAmount = 30;
const std::pair<int, int> questionPos(50, 270);
const std::pair<int, int> infoPos(40, 400);
const int cost = 50;
const int bestScore = 1000;
const int minStep = 3;
const std::pair<int, int> menuSize(550, 370);
const std::pair<int, int> menuPos(180, 115);
const std::pair<int, int> scoreDisplay(430, 370);
const QString information = "Press the key 1, 2, 3 to answer the question";

HaGame::HaGame(QWidget *parent) : QGraphicsView(parent) {
  // Set value x,y:
  posX = xStart;
  posY = yStart;

  // Set up the matrix
  matrix = new int *[fixedSize];
  for (int col = 0; col < fixedSize; ++col) {
    matrix[col] = new int[fixedSize];
  }
  for (int col = 0; col < fixedSize; ++col) {
    for (int row = 0; row < fixedSize; ++row) {
      matrix[col][row] = blank;
    }
  }

  // set value for matrix:
  matrix[5][0] = rockValue;
  matrix[3][1] = rockValue;
  matrix[1][2] = rockValue;
  matrix[3][2] = rockValue;
  matrix[5][2] = rockValue;
  matrix[3][3] = rockValue;
  matrix[1][4] = rockValue;
  matrix[3][4] = rockValue;
  matrix[4][4] = rockValue;
  matrix[2][0] = questionValue;
  matrix[0][2] = questionValue;
  matrix[2][2] = questionValue;
  matrix[4][2] = questionValue;
  matrix[1][3] = questionValue;
  matrix[1][5] = questionValue;
  matrix[3][5] = questionValue;
  matrix[1][1] = questionValue;
  matrix[0][4] = questionValue;
  matrix[2][4] = questionValue;
  matrix[5][4] = questionValue;
  matrix[5][5] = prizeValue;

  // Make an array of questions
  question = new QGraphicsPixmapItem **[fixedSize];
  for (int col = 0; col < fixedSize; ++col) {
    question[col] = new QGraphicsPixmapItem *[fixedSize];
  }

  // Make an array of rocks
  rock = new QGraphicsPixmapItem **[fixedSize];
  for (int col = 0; col < fixedSize; ++col) {
    rock[col] = new QGraphicsPixmapItem *[fixedSize];
  }
  // Set the size of back ground
  setFixedSize(widthSize, heightSize);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  // Set background
  scene = new QGraphicsScene(this);
  scene->setSceneRect(xOrigin, yOrigin, widthSize, heightSize);
  QGraphicsPixmapItem *bg = new QGraphicsPixmapItem();
  bg->setPixmap(QPixmap(":/image/background.jpg").scaled(widthSize, heightSize));
  scene->addItem(bg);

  //Set the grid image
  QGraphicsPixmapItem *grid = new QGraphicsPixmapItem();
  grid->setPixmap(QPixmap(":/image/matrix.png").scaled(gridSize, gridSize));
  grid->setPos(xStart, yStart);
  scene->addItem(grid);

  //Insert rocks, questions, prize item
  for (int xIter = 0; xIter < fixedSize; ++xIter) {
      for (int yIter = 0; yIter < fixedSize; ++yIter) {
          if (matrix[xIter][yIter] == rockValue) {
              //Rocks
              rock[xIter][yIter]= new QGraphicsPixmapItem();
              rock[xIter][yIter]->setPixmap(QPixmap(":/image/rock.png").scaled(itemSize, itemSize));
              rock[xIter][yIter]->setPos(xStart + xIter*itemSize, yStart + yIter*itemSize);
              scene->addItem(rock[xIter][yIter]);

          } else if (matrix[xIter][yIter] == questionValue) {
              //Questions
              question[xIter][yIter] = new QGraphicsPixmapItem();
              question[xIter][yIter]->setPixmap(QPixmap(":/image/question.png").scaled(itemSize, itemSize));
              question[xIter][yIter]->setPos(xStart + xIter*itemSize, yStart + yIter*itemSize);
              scene->addItem(question[xIter][yIter]);

          } else if (matrix[xIter][yIter] == prizeValue) {
              //Prizes
              QGraphicsPixmapItem *prize = new QGraphicsPixmapItem();
              prize->setPixmap(QPixmap(":/image/prize.png").scaled(itemSize, itemSize));
              prize->setPos(xStart + xIter*itemSize, yStart + yIter*itemSize);
              scene->addItem(prize);
          }
      }
  }

  setScene(scene);
  questionObject = nullptr;
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
int HaGame::Random(int first, int second) {
  int temp = second - first + 1;
  return (rand() % temp + 1);
}

//DFS for checking game over
void HaGame::DFS(int **temp, int w, int h, bool &flag) {
  if (w < 0 || w >= fixedSize || h < 0 || h >= fixedSize)
    return;
  if (temp[w][h] == rockValue)
    return;
  if (w == (fixedSize - 1) && h == (fixedSize - 1)) {
    flag = true;
    return;
  }
  temp[w][h] = rockValue;
  DFS(temp, w + 1, h, flag);
  DFS(temp, w - 1, h, flag);
  DFS(temp, w, h - 1, flag);
  DFS(temp, w, h + 1, flag);
}

//Convert position into coordinate in matrix
int HaGame::xCoor(int posX) {
    return (posX - xStart) / itemSize;
}

int HaGame::yCoor(int posY) {
    return (posY - yStart) / itemSize;
}

void HaGame::GetQuestion() {
  if (matrix[xCoor(posX)][yCoor(posY)] == questionValue) {
    questionObject = new questionlist();
    scene->addItem(questionObject);
    numberQuestion = Random(1, questionAmount);
    QString quiz = questionObject->content(numberQuestion);
    text = new QGraphicsTextItem(quiz);
    QFontDatabase::addApplicationFont(":/font/AmongYou-BWdWw.ttf");
    QFont font("a Among You", 15);
    text->setFont(font);
    text->setPos(questionPos.first, questionPos.second);
    text->setDefaultTextColor(QColor(125, 211, 217, 255));
    scene->addItem(text);

    QString info = information;
    note = new QGraphicsTextItem(info);
    QFont font2("a Among You", 8);
    note->setFont(font2);
    note->setPos(infoPos.first, infoPos.second);
    note->setDefaultTextColor(QColor("white"));
    scene->addItem(note);
    answerQuestion = true;
  }
}

void HaGame::AnswerQuestion() {
  if (variant != 0 && numberQuestion != 0) {
    if (questionObject->answer(numberQuestion, variant)) {
      scene->removeItem(questionObject);
      scene->removeItem(text);
      scene->removeItem(note);
      question[xCoor(posX)][yCoor(posY)]->setPixmap(QPixmap(":/image/pass.png").scaled(itemSize, itemSize));
      matrix[xCoor(posX)][yCoor(posY)] = blank; // if answer is true
      if (totalCorrect == totalQuestion) {
        gameScore->setScore(gameScore->getScore() + cost);
      } else {
        gameScore->setScore(gameScore->getScore() + cost - (totalQuestion - totalCorrect) * 5);
      }
      variant = 0;
      numberQuestion = 0;
      answerQuestion = false;
      totalQuestion++;
      totalCorrect++;
    } else {
      scene->removeItem(questionObject);
      scene->removeItem(text);
      scene->removeItem(note);
      question[xCoor(posX)][yCoor(posY)]->setPixmap(QPixmap(":/image/notpass.png").scaled(itemSize, itemSize));
      matrix[xCoor(posX)][yCoor(posY)] = rockValue; // if answer is false
      variant = 0;
      numberQuestion = 0;
      if (mainObject->getDirection() == "Up") {
        posY += itemSize;
        mainObject->setPos(posX, posY);
        mainObject->setDirection("STOP");
      }
      if (mainObject->getDirection() == "Down") {
        posY -= itemSize;
        mainObject->setPos(posX, posY);
        mainObject->setDirection("STOP");
      }
      if (mainObject->getDirection() == "Left") {
        posX += itemSize;
        mainObject->setPos(posX, posY);
        mainObject->setDirection("STOP");
      }
      if (mainObject->getDirection() == "Right") {
        posX -= itemSize;
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
  lose->setPixmap(QPixmap(":/image/lose.png").scaled(menuSize.first, menuSize.second));
  lose->setPos(menuPos.first, menuPos.second);
  scene->addItem(lose);
  gameScore->setScore(0);
}

//Win menu
void HaGame::WinMenu() {
  QGraphicsPixmapItem *win = new QGraphicsPixmapItem();
  win->setPixmap(QPixmap(":/image/win.png").scaled(menuSize.first, menuSize.second));
  win->setPos(menuPos.first, menuPos.second);
  scene->addItem(win);
  if (totalQuestion == minStep) {
    gameScore->setScore(gameScore->getScore() + bestScore);
  } else {
    int scoreReduce = (totalQuestion - minStep) * cost;
    gameScore->setScore(gameScore->getScore() + bestScore - 2*scoreReduce);
  }
  QString total = QString::number(gameScore->getScore());
  text = new QGraphicsTextItem(total);
  QFontDatabase::addApplicationFont(":/font/AmongYou-BWdWw.ttf");
  QFont font("a Among You", 20);
  text->setFont(font);
  text->setPos(scoreDisplay.first, scoreDisplay.second);
  text->setDefaultTextColor(QColor("white"));
  scene->addItem(text);
}

// Check game over
void HaGame::CheckGameOver() {
  bool flag = false;
  int **temp;
  temp = new int *[fixedSize];
  for (int i = 0; i < fixedSize; i++) {
    temp[i] = new int[fixedSize];
  }
  for (int i = 0; i < fixedSize; i++) {
    for (int j = 0; j < fixedSize; j++) {
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
    if (matrix[xCoor(posX)][yCoor(posY) + 1] != rockValue && posY < heightSize - 100) {
      posY += itemSize;
      mainObject->keyPressEvent(event);
      GetQuestion();
      if (xCoor(posX) == fixedSize - 1 && yCoor(posY) == fixedSize - 1)
        WinMenu();
      mainObject->setDirection("Down");
    }
  }
  if (event->key() == Qt::Key_Up && !answerQuestion) {
    if (matrix[xCoor(posX)][yCoor(posY) - 1] != rockValue && posY > yStart) {
      posY -= itemSize;
      mainObject->keyPressEvent(event);
      GetQuestion();
      if (xCoor(posX) == fixedSize - 1 && yCoor(posY) == fixedSize - 1)
        WinMenu();
      mainObject->setDirection("Up");
    }
  }
  if (event->key() == Qt::Key_Left && !answerQuestion) {
    if (matrix[xCoor(posX) - 1][yCoor(posY)] != rockValue && posX > xStart) {
      posX -= itemSize;
      mainObject->keyPressEvent(event);
      GetQuestion();
      if (xCoor(posX) == fixedSize - 1 && yCoor(posY) == fixedSize - 1)
        WinMenu();
      mainObject->setDirection("Left");
    }
  }
  if (event->key() == Qt::Key_Right && !answerQuestion) {
    if (matrix[xCoor(posX) + 1][yCoor(posY)] != rockValue && posX < widthSize - 100) {
      posX += itemSize;
      mainObject->keyPressEvent(event);
      GetQuestion();
      if (xCoor(posX) == fixedSize - 1 && yCoor(posY) == fixedSize - 1)
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
