#ifndef VALUEGRID_H
#define VALUEGRID_H

#include <vector>
#include "valuecell.h"

class ValueGrid
{
public:
    ValueGrid();
    ValueGrid(unsigned int NSectors, unsigned int NCircles, double Radius);
    //ValueGrid(const ValueGrid& Source, int MultAngle, int MultRadius);
    //ValueGrid(const ValueGrid& source);

    // методы для извлечения значений координат и функций в узлах
    double getRadius_Node(unsigned int radiusAxe, unsigned int angleAxe);
    double getAngle_Node(unsigned int radiusAxe, unsigned int angleAxe);
    double getValue_Node(unsigned int radiusAxe, unsigned int angleAxe);

    // методы для извлечения значений координат и функций в половинных узлах
    double getRadius_HalfNodeRadius(unsigned int radiusAxe, unsigned int angleAxe);
    double getAngle_HalfNodeRadius(unsigned int radiusAxe, unsigned int angleAxe);
    double getRadius_HalfNodeAngle(unsigned int radiusAxe, unsigned int angleAxe);
    double getAngle_HalfNodeAngle(unsigned int radiusAxe, unsigned int angleAxe);

    // методы заполнения значения функций в конкретном узле (целом или половинном)
    ValueGrid& setValue_Node(unsigned int radiusAxe, unsigned int angleAxe, double v);
    ValueGrid& setValue_HalfNodeRadius(unsigned int radiusAxe, unsigned int angleAxe, double v);
    ValueGrid& setValue_HalfNodeAngle(unsigned int radiusAxe, unsigned int angleAxe, double v);

protected:

private:
    std::vector<std::vector<ValueCell> > gridMatrix;
    unsigned int nAngles;
    unsigned int nRadiuses;
    double maxRadius;

    ValueGrid& setArgs();
};

#endif // VALUEGRID_H
