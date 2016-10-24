#include "appexception.h"

AppException::AppException()
{
    message = "Every in-application exception";
}

std::string AppException::getMessage()
{
    return std::string(message);
}
