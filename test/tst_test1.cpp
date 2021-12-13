#include <QtTest>
#include <include/hagame.h>

// add necessary includes here

class test1 : public QObject
{
    Q_OBJECT

public:
    test1();
    ~test1();

private slots:
    void test_case1();

};

test1::test1()
{
   QCOMPARE(2, GetCoordX(560));
   QCOMPARE(1, GetCoordY(180));
}

test1::~test1()
{
    //default
}

void test1::test_case1()
{

}

QTEST_APPLESS_MAIN(test1)

#include "tst_test1.moc"
