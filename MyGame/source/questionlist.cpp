#include "../header/questionlist.h"
const std::pair<int, int> questionSize(350, 270);
const std::pair<int, int> questionPos(30, 250);
questionlist::questionlist(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
  setPixmap(QPixmap(":/image/frame.png").scaled(questionSize.first, questionSize.second));
  setPos(questionPos.first, questionPos.second);
}

QString questionlist::content(int i) {
  if (i == 1) {
    QString quiz = "What number does\ngiga stand for?\nA.a thousand     \nB.a million     \nC.a billion";
    return quiz;
  }

  if (i == 2) {
    QString quiz = "if: 1=3 , 2=3 , 3=5 ,  \n    4=4 , 5=4 \n \n   Then, 6= ? \n    A.3    B.4   C.5 ";
    return quiz;
  }

  if (i == 3) {
    QString quiz = "How many prime \nnumbers less than 23? \n\n   A.7    B.8   C.9 ";
    return quiz;
  }

  if (i == 4) {
    QString quiz = "The max sum of two \n integers have the \n product 25? \n\n    A.10   B.25  C.not A&B ";
    return quiz;
  }
  if (i == 5) {
    QString quiz = "What is the smallest \n planet in our solar \n system? \nA.Mercury   B.Venus \n            C.Mars ";
    return quiz;
  }
  if (i == 6) {
    QString quiz = "Do you want to win the\n             game? \n\nA.Yes   B.Of course yes \n            C.Why not ";
    return quiz;
  }
  if (i == 7) {
    QString quiz = "What is the smallest \n country in the\n world? \n\nA.Monaco   B.Vatican \n            C.Nauru ";
    return quiz;
  }
  if (i == 8) {
    QString quiz = "HTML is HyperText? \n\nA.Markup Language \nB.Marking Language \nC.Makeup Language";
    return quiz;
  }
  if (i == 9) {
    QString quiz = "What geometric shape \n is generally used for \n stop signs?\nA.Round \nB.Hexagon \nC.Octagon";
    return quiz;
  }
  if (i == 10) {
    QString quiz = "Which animal can be\n seen on the Porsche\n logo?\nA.Horse \nB.Lion \nC.Tiger";
    return quiz;
  }
  if (i == 11) {
    QString quiz =
        "What was the first \n soft drink in \n space?\nA.Coca Cola   B.Pepsi \nC.I was not there \n so i don't know";
    return quiz;
  }
  if (i == 12) {
    QString quiz = "Which country invented\n   ice cream?\nA.France    B.Britain \n         C.China";
    return quiz;
  }
  if (i == 13) {
    QString quiz =
        "Which country won \n the first-ever soccer \n World Cup in 1930?\nA.Brazil    B.Uruguay \n         C.Germany";
    return quiz;
  }
  if (i == 14) {
    QString quiz = "Havana is the capital \n of what country?\nA.Cuba    B.Jamaica \n         C.Haiti";
    return quiz;
  }
  if (i == 15) {
    QString
        quiz = "The unicorn is the \n national animal of\n which country?\n A.Finland \n B.Switzerland \n C.Scotland";
    return quiz;
  }
  if (i == 16) {
    QString quiz = "if: 6=48  5=35  4=24  2=8\n Then 1=?\n A.2        B.4       C.1";
    return quiz;
  }
  if (i == 17) {
    QString quiz = "How many face\ndiagonals in a cube?\n A.4     B.2     C.not A&B";
    return quiz;
  }
  if (i == 18) {
    QString quiz = "Fill the table?\n11  2  18\n5  2  ??\n12  5  14\n\nA.6     B.7    C.9";
    return quiz;
  }
  if (i == 19) {
    QString quiz = "How many legs \ndoes a spider have?\nA.6     B.8    C.10";
    return quiz;
  }
  if (i == 20) {
    QString quiz = "How many colors\n are there in\n 3 rainbows?\nA.21     B.14    C.7";
    return quiz;
  }
  if (i == 21) {
    QString quiz = "Which is the largest\n ocean in the world?\nA.Pacific   B.Indian\n      C.Atlantic";
    return quiz;
  }
  if (i == 22) {
    QString
        quiz = "Which country \nconsumes the most\n chocolate per capita?\nA.USA       B.Belgium\n     C.Switzerland";
    return quiz;
  }
  if (i == 23) {
    QString quiz = "What country has the\n most natural lakes?\nA.Russia       B.Canada\n     C.Australia";
    return quiz;
  }
  if (i == 24) {
    QString quiz = "How long do elephant\n pregnancies last?\nA.22 months\nB.20 months\nC.2 years";
    return quiz;
  }
  if (i == 25) {
    QString quiz = "How many teeth does\nan adult human have?\n\nA.32   B.34   C.30";
    return quiz;
  }
  if (i == 26) {
    QString quiz = "Where is Billie \nEilish from?\n\nA.New York   \nB.Los Angeles\nC.Chicago";
    return quiz;
  }
  if (i == 27) {
    QString quiz = "What is the national\n flower of Japan?\nA.Rose  \nB.Lotus\nC.Cherry blossom";
    return quiz;
  }
  if (i == 28) {
    QString quiz = "What is the smallest\n perfect number?\nA.4    B.5    C.6";
    return quiz;
  }
  if (i == 29) {
    QString quiz =
        "How many colors are\nneeded on a map to\nmake sure that no\nborder will share\na color?\nA.4    B.5    C.6";
    return quiz;
  }
  if (i == 30) {
    QString quiz = "How many sides does\na nonagon have?\nA.9     B.10     C.11";
    return quiz;
  }

  return "";

}

bool questionlist::answer(int i, int variant) {
  if (i == 1) {
    if (variant == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 2) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 3) {
    if (variant == 2) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 4) {
    if (variant == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 5) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 6) {
    return false;
  }
  if (i == 7) {
    if (variant == 2) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 8) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 9) {
    if (variant == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 10) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 11) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 12) {
    if (variant == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 13) {
    if (variant == 2) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 14) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 15) {
    if (variant == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 16) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 17) {
    if (variant == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 18) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 19) {
    if (variant == 2) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 20) {
    if (variant == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 21) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 22) {
    if (variant == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 23) {
    if (variant == 2) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 24) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 25) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 26) {
    if (variant == 2) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 27) {
    if (variant == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 28) {
    if (variant == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 29) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (i == 30) {
    if (variant == 1) {
      return true;
    } else {
      return false;
    }
  }
  return true;

}


