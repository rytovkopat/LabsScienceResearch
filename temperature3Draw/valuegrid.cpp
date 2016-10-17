#include <stdlib.h>
#include <math.h>

#include "valuegrid.h"

ValueGrid::ValueGrid() :
    nAngles(0), nRadiuses(0), maxRadius(0.0),
    gridMatrix(std::vector<std::vector<ValueCell> >())
{
}

ValueGrid::ValueGrid(unsigned int NSectors, unsigned int NCircles, double Radius) :
{
    if (isnan(Radius) || Radius<=0.0)
        throw 7; // поставь исключение
    if (NSectors==0 || NSectors >= 1<<30)
        throw 8; //
    if (NCircles==0 || NCircles >= 1<<30)
        throw 9; //
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
    for (angleId = 0; angleId <= 2*nAngles; angleId++)
    {
        double an = M_2_PI * angleId / (2*nAngles);
        for (radiusId = 0; radiusId <= 2*nRadiuses; radiusId++)
        {
            double rad = (radiusId % 2 == 0)
                         ? rad1 * sqrt(radiusId * 0.5)
                         : rad1 * sqrt(radiusId * 0.5);  // половинные узлы в парадигме основных узлов
                      // : rad1 * (sqrt((radiusId-1)*0.5) + sqrt((radiusId+1)*0.5)) * 0.5;  // половинные узлы в парадигме центра масс ячейки
                      // : rad1 * 2/3 * (radiusId + 0.5*sqrt(radiusId*radiusId-1)) / (sqrt((radiusId-1)*0.5) + sqrt((radiusId+1)*0.5)) // половинные узлы в парадигме средних арифметических
            gridMatrix[angleId][radiusId].setRadius(rad).setAngle(an);
        }
    }

    return *this;
}

