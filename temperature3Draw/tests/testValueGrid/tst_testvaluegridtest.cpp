#include <QString>
#include <QtTest>
#include <QObject>

#include <math.h>

#include "../../valuegrid.h"
#include "../../valuecell.h"

class TestValueGridTest : public QObject
{
    Q_OBJECT

public:
    TestValueGridTest();

private Q_SLOTS:
    void testValueCellConstruct();
    void testValueCellSetGet();
    void testValueGrid_Node();
    void testValueGrid_HalfNodeR();
    void testValueGrid_HalfNodeA();
};

TestValueGridTest::TestValueGridTest()
{

}

void TestValueGridTest::testValueCellConstruct()
{
    ValueCell testCell;
    QVERIFY2(testCell.isValid()==false, "Not initialized");
    QVERIFY2(testCell.isValidArg()==false, "Args not initialized");
}

void TestValueGridTest::testValueCellSetGet()
{
    ValueCell testCell;
    try
    {
        testCell.setRadius(8.0);
//        QVERIFY2(isnan(testCell.getRadius()), "0");
        testCell.setAngle(0.456789);
        QCOMPARE(testCell.getRadius(), 8.0);
        QCOMPARE(testCell.getAngle(), 0.456789);
        QVERIFY2(testCell.isValidArg(), "Well initialization of args");
        QVERIFY2(!testCell.isValid(), "Value still not valid");
        testCell.setValue(-9.6);
        QCOMPARE(testCell.getValue(), -9.6);
        QVERIFY2(testCell.isValid(), "Value now already valid");
    }
    catch (char const* str)
    {
        QVERIFY2(false, "Arg init not done");
    }


    //QCOMPARE(testCell.getAngle(), 0.8654321);
    //QCOMPARE(testCell.getRadius(), 9.0);
    //QVERIFY2(testCell.isValid()==false, "Not initialized");
    //QVERIFY2(testCell.isValidArg()==true, "Args initialized, value not");
}

void TestValueGridTest::testValueGrid_Node()
{
    ValueGrid testGrid;
    try
    {
        testGrid = ValueGrid(4, 8, 2.0);

        QCOMPARE(testGrid.getAngle_Node(1,3), 3*M_PI/4);
        QCOMPARE(testGrid.getRadius_Node(1,3), 1.0);
    }
    catch (char const* str)
    {
        printf("Error: %s\n",str);

        QVERIFY2(false, "Read/write error");
    }
    catch (...)
    {
        printf("Caught unexpectable exception!");
        QVERIFY2(false, "Unexpected error");
    }
}

void TestValueGridTest::testValueGrid_HalfNodeR()
{
    ValueGrid testGrid;
    try
    {
        testGrid = ValueGrid(4, 8, 2.0);

        QCOMPARE(testGrid.getAngle_HalfNodeRadius(1,3), 3*M_PI/4);
        QCOMPARE(testGrid.getRadius_HalfNodeRadius(1,3), sqrt(1.5));
    }
    catch (char const* str)
    {
        printf("Error: %s\n",str);

        QVERIFY2(false, "Read/write error");
    }
    catch (...)
    {
        printf("Caught unexpectable exception!");
        QVERIFY2(false, "Unexpected error");
    }
}

void TestValueGridTest::testValueGrid_HalfNodeA()
{
    ValueGrid testGrid;
    try
    {
        testGrid = ValueGrid(4, 8, 2.0);

        QCOMPARE(testGrid.getAngle_HalfNodeAngle(1,3), 7*M_PI/8);
        QCOMPARE(testGrid.getRadius_HalfNodeAngle(1,3), 1.0);
    }
    catch (char const* str)
    {
        printf("Error: %s\n",str);

        QVERIFY2(false, "Read/write error");
    }
    catch (...)
    {
        printf("Caught unexpectable exception!");
        QVERIFY2(false, "Unexpected error");
    }
}

QTEST_APPLESS_MAIN(TestValueGridTest)

#include "tst_testvaluegridtest.moc"
