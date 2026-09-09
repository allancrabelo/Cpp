#include "ScalarConverter.hpp"

// Canonical form
ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    std::cout << "ScalarConverter assignment operator called" << std::endl;
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

// Public member functions
int ScalarConverter::charVerificator(std::string literal)
{
    if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
        return (1);
    return (0);
}

int ScalarConverter::intVerificator(std::string literal)
{
    if (literal.length() == 0)
        return (0);
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i = 1;
    for (; i < literal.length(); i++)
    {
        if (!isdigit(literal[i]))
            return (0);
    }
    return (1);
}

int ScalarConverter::floatVerificator(std::string literal)
{
    if (literal.length() == 0)
        return (0);
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i = 1;
    bool dotFound = false;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (dotFound)
                return (0);
            dotFound = true;
        }
        else if (!isdigit(literal[i]))
            return (0);
    }
    if (!dotFound || literal[literal.length() - 1] != 'f')
        return (0);
    return (1);
}

int ScalarConverter::doubleVerificator(std::string literal)
{
    if (literal.length() == 0)
        return (0);
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i = 1;
    bool dotFound = false;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (dotFound)
                return (0);
            dotFound = true;
        }
        else if (!isdigit(literal[i]))
            return (0);
    }
    if (!dotFound)
        return (0);
    return (1);
}

int ScalarConverter::nanOrInfVerificator(std::string literal)
{
    if (literal == "nan" || literal == "inf" || literal == "+inf" || literal == "-inf")
        return (1);
    return (0);
}

void    ScalarConverter::charConverter(std::string literal)
{
    char c = static_cast<char>(literal[0]);
    std::cout << "char: " << c << std::endl;

    int i = static_cast<int>(literal[0]);
    std::cout << "int: " << i << std::endl;

    float f = static_cast<float>(literal[0]);
    std::cout << "float: " << static_cast<float>(f) << ".0f" << std::endl;

    double d = static_cast<double>(literal[0]);
    std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;

}

void    ScalarConverter::floatConverter(std::string literal)
{
    float f = std::stof(literal);
    std::cout << "float: " << f << "f" << std::endl;

    int i = static_cast<int>(f);
    std::cout << "int: " << i << std::endl;

    char c = static_cast<char>(f);
    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    double d = static_cast<double>(f);
    std::cout << "double: " << d << std::endl;
}

void    ScalarConverter::doubleConverter(std::string literal)
{
    double d = std::stod(literal);
    std::cout << "double: " << d << std::endl;

    int i = static_cast<int>(d);
    std::cout << "int: " << i << std::endl;

    char c = static_cast<char>(d);
    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    float f = static_cast<float>(d);
    std::cout << "float: " << f << "f" << std::endl;
}

void   ScalarConverter::intConverter(std::string literal)
{
    int i = std::stoi(literal);
    std::cout << "int: " << i << std::endl;

    char c = static_cast<char>(i);
    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    float f = static_cast<float>(i);
    std::cout << "float: " << f << ".0f" << std::endl;

    double d = static_cast<double>(i);
    std::cout << "double: " << d << ".0" << std::endl;
}

void   ScalarConverter::nanOrInfConverter(std::string literal)
{
    if (literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "inf" || literal == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else if (literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(std::string literal)
{
    ScalarConverter converter;

    int type = converter.typeChecker(literal);

    switch (type)
    {
        case 0:
            converter.charConverter(literal);
            break;
        case 1:
            converter.intConverter(literal);
            break;
        case 2:
            converter.floatConverter(literal);
            break;
        case 3:
            converter.doubleConverter(literal);
            break;
        case 4:
            converter.nanOrInfConverter(literal);
            break;
        default:
            std::cerr << "Error: Invalid literal" << std::endl;
            break;
    }
}

int ScalarConverter::typeChecker(std::string literal)
{
    if (charVerificator(literal))
        return (0);
    else if (intVerificator(literal))
        return (1);
    else if (floatVerificator(literal))
        return (2);
    else if (doubleVerificator(literal))
        return (3);
    else if (nanOrInfVerificator(literal))
        return (4);
    else
        return (-1);
}