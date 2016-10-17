#ifndef VALUECELL_H
#define VALUECELL_H


class ValueCell
{
public:
    ValueCell();
    double getRadius();
    double getAngle();
    double getValue();
    bool isValid();
    bool isValidArg();
    ValueCell& setRadius(double r);
    ValueCell& setAngle(double a);
    ValueCell& setValue(double v);


private:
    double radius;
    double angle;
    double value;
    bool isRadiusValid;
    bool isAngleValid;
    bool isValueValid;
};

#endif // VALUECELL_H
