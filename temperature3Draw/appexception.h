#ifndef APPEXCEPTION_H
#define APPEXCEPTION_H

#include <string>

class AppException
{

public:
    AppException();
    std::string getMessage();

protected:
    std::string message;
};

#endif // APPEXCEPTION_H
