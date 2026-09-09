#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
    private:
        // Canonical form
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

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