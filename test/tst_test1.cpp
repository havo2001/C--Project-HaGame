#include <QtTest>
#include <include/hagame.h>
#include <include/object>

// add necessary includes here

class test1 : public QObject
{
    Q_OBJECT

public:
    test1();
    ~test1();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
};

test1::test1()
{

}

test1::~test1()
{
    //default
}

void test1::test_case1()
{
   QCOMPARE(GetCoordX(560), 2);
}

void test1::test_case2() {
     QCOMPARE(GetCoordY(180), 1);
}

void test1::test_case3() {
    QString str = "Down";
    QCOMPARE(str.getDirection(), QString("Down"));
}

QTEST_APPLESS_MAIN(test1)

#include "tst_test1.moc"
