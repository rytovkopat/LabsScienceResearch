#include <math.h>

#include "valuecell.h"

ValueCell::ValueCell()
{
    radius = 0.0;
    angle = 0.0;
    value = 0.0;
    isRadiusValid = false;
    isAngleValid = false;
    isValueValid = false;
}

double ValueCell::getAngle()
{
    if (!isAngleValid)
        throw "AccessException"; // поставь исключение
    return angle;
}

double ValueCell::getRadius()
{
    if (!isRadiusValid)
        throw "AccessException"; // поставь исключение
    return radius;
}

double ValueCell::getValue()
{
    if (!isValueValid)
        throw "AccessException"; // поставь исключение
    return value;
}

ValueCell& ValueCell::setAngle(double a)
{
    if (bool(isnan(a)) || a<0.0 || a>M_2_PI)
        throw "DataException"; // поставь исключение
    angle = a;
    isAngleValid = true;
    return *this;
}

ValueCell& ValueCell::setRadius(double r)
{
    if (/*bool(isnan(r))*/false || r<0.0)
        throw "DataException"; // поставь исключение
    radius = r;
    isRadiusValid = true;
    return *this;
}

ValueCell& ValueCell::setValue(double v)
{
    if (/*bool(isnan(v))*/ false)
        throw "DataException"; // поставь исключение
    value = v;
    isValueValid = true;
    return *this;
}

bool ValueCell::isValid()
{
    return isRadiusValid && isAngleValid && isValueValid;
}

bool ValueCell::isValidArg()
{
    return isRadiusValid && isAngleValid;
}
