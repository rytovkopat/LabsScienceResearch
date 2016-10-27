#include <stdlib.h>
#include <math.h>

#include "valuegrid.h"

ValueGrid::ValueGrid() :
    nAngles(0), nRadiuses(0), maxRadius(0.0),
    gridMatrix(std::vector<std::vector<ValueCell> >())
{
}

ValueGrid::ValueGrid(unsigned int NCircles, unsigned int NSectors, double Radius)
{
    if (bool(isnan(Radius)) || Radius<=0.0)
        throw "DataException1()"; // поставь исключение
    if (NSectors==0 || NSectors >= 1<<30)
        throw "DataException2()"; //
    if (NCircles==0 || NCircles >= 1<<30)
        throw "DataException3()"; //
    nAngles = NSectors;
    nRadiuses = NCircles;
    maxRadius = Radius;
    gridMatrix.resize(2*nAngles+1);
    for (unsigned angleId=0; angleId <= 2*nAngles; angleId++)
    {
        gridMatrix[angleId].resize(2*nRadiuses+1);
    }

    setArgs();
}

ValueGrid& ValueGrid::setArgs()
{
    double rad1 = maxRadius / sqrt(nRadiuses);
    for (unsigned int angleId = 0; angleId <= 2*nAngles; angleId++)
    {
        double an = M_PI * angleId / (nAngles);
        for (unsigned int radiusId = 0; radiusId <= 2*nRadiuses; radiusId++)
        {
            double rad = (radiusId % 2 == 0)
                         ? rad1 * sqrt(radiusId * 0.5)
                         : rad1 * sqrt(radiusId * 0.5);  // половинные узлы в парадигме основных узлов
                      // : rad1 * (sqrt((radiusId-1)*0.5) + sqrt((radiusId+1)*0.5)) * 0.5;  // половинные узлы в парадигме центра масс ячейки
                      // : rad1 * 2/3 * (radiusId + 0.5*sqrt(radiusId*radiusId-1)) / (sqrt((radiusId-1)*0.5) + sqrt((radiusId+1)*0.5)) // половинные узлы в парадигме средних арифметических
            gridMatrix[angleId][radiusId].setRadius(rad);
            gridMatrix[angleId][radiusId].setAngle(an);
        }
    }

    return *this;
}

double ValueGrid::getRadius_Node(unsigned int radiusAxe, unsigned int angleAxe)
{
    if (radiusAxe > nRadiuses)
        throw "DataExceptionR()";
    if (angleAxe > nAngles)
        throw "DataExceptionA()";

    return gridMatrix[angleAxe*2][radiusAxe*2].getRadius();
}

double ValueGrid::getAngle_Node(unsigned int radiusAxe, unsigned int angleAxe)
{
    if (radiusAxe > nRadiuses)
        throw "DataExceptionR()";
    if (angleAxe > nAngles)
        throw "DataExceptionA()";

    return gridMatrix[angleAxe*2][radiusAxe*2].getAngle();
}

double ValueGrid::getValue_Node(unsigned int radiusAxe, unsigned int angleAxe)
{
    if (radiusAxe > nRadiuses)
        throw "DataExceptionR()";
    if (angleAxe > nAngles)
        throw "DataExceptionA()";

    try
    {
        return gridMatrix[angleAxe*2][radiusAxe*2].getValue();
    }
    catch(...)
    {
        throw;
    }
}

ValueGrid& ValueGrid::setValue_Node(unsigned int radiusAxe, unsigned int angleAxe, double v)
{
    if (radiusAxe > nRadiuses)
        throw "DataExceptionR()";
    if (angleAxe > nAngles)
        throw "DataExceptionA()";

    gridMatrix[angleAxe*2][radiusAxe*2].setValue(v);
    return *this;
}

ValueGrid& ValueGrid::setValue_HalfNodeAngle(unsigned int radiusAxe, unsigned int angleAxe, double v)
{
    if (radiusAxe > nRadiuses)
        throw "DataExceptionR()";
    if (angleAxe >= nAngles)
        throw "DataExceptionA()";

    gridMatrix[angleAxe*2+1][radiusAxe*2].setValue(v);
    return *this;
}

ValueGrid& ValueGrid::setValue_HalfNodeRadius(unsigned int radiusAxe, unsigned int angleAxe, double v)
{
    if (radiusAxe >= nRadiuses)
        throw "DataExceptionR()";
    if (angleAxe > nAngles)
        throw "DataExceptionA()";

    gridMatrix[angleAxe*2][radiusAxe*2+1].setValue(v);
    return *this;
}

double ValueGrid::getAngle_HalfNodeAngle(unsigned int radiusAxe, unsigned int angleAxe)
{
    if (radiusAxe > nRadiuses)
        throw "DataExceptionR()";
    if (angleAxe >= nAngles)
        throw "DataExceptionA()";

    return gridMatrix[angleAxe*2+1][radiusAxe*2].getAngle();
}

double ValueGrid::getRadius_HalfNodeAngle(unsigned int radiusAxe, unsigned int angleAxe)
{
    if (radiusAxe > nRadiuses)
        throw "DataExceptionR()";
    if (angleAxe >= nAngles)
        throw "DataExceptionA()";

    return gridMatrix[angleAxe*2+1][radiusAxe*2].getRadius();
}

double ValueGrid::getAngle_HalfNodeRadius(unsigned int radiusAxe, unsigned int angleAxe)
{
    if (radiusAxe >= nRadiuses)
        throw "DataExceptionR()";
    if (angleAxe > nAngles)
        throw "DataExceptionA()";

    return gridMatrix[angleAxe*2][radiusAxe*2+1].getAngle();
}

double ValueGrid::getRadius_HalfNodeRadius(unsigned int radiusAxe, unsigned int angleAxe)
{
    if (radiusAxe >= nRadiuses)
        throw "DataExceptionR()";
    if (angleAxe > nAngles)
        throw "DataExceptionA()";

    return gridMatrix[angleAxe*2][radiusAxe*2+1].getRadius();
}

