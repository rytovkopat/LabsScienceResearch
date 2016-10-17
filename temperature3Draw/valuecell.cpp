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
        throw 1; // поставь исключение
    return angle;
}

double ValueCell::getRadius()
{
    if (!isRadiusValid)
        throw 2; // поставь исключение
    return radius;
}

double ValueCell::getValue()
{
    if (!isValueValid)
        throw 3; // поставь исключение
    return value;
}

ValueCell& ValueCell::setAngle(double a)
{
    if (a<0.0 || a>M_2_PI || isnan(a))
        throw 4; // поставь исключение
    angle = a;
    isAngleValid = true;
    return *this;
}

ValueCell& ValueCell::setRadius(double r)
{
    if (r<0.0 || isnan(r))
        throw 5; // поставь исключение
    radius = r;
    isRadiusValid = true;
    return *this;
}

ValueCell& ValueCell::setValue(double v)
{
    if (isnan(v))
        throw 6; // поставь исключение
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
