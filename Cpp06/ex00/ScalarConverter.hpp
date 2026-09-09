#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
    private:
        // Canonical form
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static int charVerificator(std::string literal);
        static int intVerificator(std::string literal);
        static int floatVerificator(std::string literal);
        static int doubleVerificator(std::string literal);
        static int nanOrInfVerificator(std::string literal);

        static int typeChecker(std::string literal);
        static void charConverter(std::string literal);
        static void intConverter(std::string literal);
        static void floatConverter(std::string literal);
        static void doubleConverter(std::string literal);
        static void nanOrInfConverter(std::string literal);

    public:
        static void convert(std::string literal);
};


#endif