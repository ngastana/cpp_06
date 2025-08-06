/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:18:10 by ngastana          #+#    #+#             */
/*   Updated: 2025/08/06 12:06:54 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
    return;
}

ScalarConverter::~ScalarConverter(){
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
	return;
}           

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void) other;
    return (*this);
}

bool pseudo(std::string str)
{
    if (str == "nanf" || str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf" || str == "nan" || str == "inf" || str == "NaN")
    {
        std::cout << "char: " << "impossible" << "\n";
		std::cout << "int: " << "impossible" << "\n";
		std::cout << "float: " << ((str[str.size() - 1] == 'f') ? str : (str + 'f')) << std::endl;
		std::cout << "input: " << str << "\n";
        return (true);
    }
    return (false);
}

void str_is_char(std::string str)
{
    char c = str[0];
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    int str_int = static_cast<int>(c);
    std::cout << "int: " << str_int << std::endl;
    float str_float = static_cast<float>(c);
    std::cout << "float: " << str_float << ".0f" << std::endl;

    double str_double = static_cast<double>(c);
    std::cout << "double: " << str_double << ".0" << std::endl;
}

void str_is_int(std::string str)
{
    long value;
    std::istringstream iss(str);
    iss >> value;
    if (iss.fail() || !iss.eof())
    {
        throw std::runtime_error("Invalid integer value");
    }
    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(value)))
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    float fvalue = static_cast<float>(value);
    if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << fvalue << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void str_is_float(std::string str)
{
    float str_float;
    std::istringstream iss(str);
    iss >> str_float;
    // if (iss.fail() || !iss.eof())
    //     throw std::runtime_error("Invalid float value");
    if (iss.fail())
        throw std::runtime_error("Invalid float value");
    if (str_float < 0 || str_float > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(str_float)))
        std::cout << "char: '" << static_cast<char>(str_float) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (str_float < std::numeric_limits<int>::min() || str_float > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(str_float) << std::endl;
    if (str_float <= -std::numeric_limits<float>::max() || str_float >= std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else if (str_float == static_cast<int>(str_float))
        std::cout << "float: " << str_float << ".0f" << std::endl;
    else 
        std::cout << "float: " << str_float << "f" << std::endl;
    double str_double = static_cast<double>(str_float);
    if (str_double == static_cast<int>(str_double))
        std::cout << "double: " << str_double << ".0" << std::endl;
    else
        std::cout << "double: " << str_double << std::endl;
}

void str_is_double(std::string str)
{
    double str_double;
    std::istringstream iss(str);
    iss >> str_double;
    if (iss.fail() || !iss.eof())
        throw std::runtime_error("Invalid double value");
    if (str_double < 0 || str_double > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(str_double)))
        std::cout << "char: '" << static_cast<char>(str_double) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (str_double < std::numeric_limits<int>::min() || str_double > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(str_double) << std::endl;
    float str_float = static_cast<float>(str_double);
    if (str_float <= -std::numeric_limits<float>::max() || str_float >= std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else if (str_float == static_cast<int>(str_float))
        std::cout << "float: " << str_float << ".0f" << std::endl;
    else
        std::cout << "float: " << str_float << "f" << std::endl;
    std::cout << "double: " << str_double << std::endl;  
}

bool isValidLiteral(const std::string& str) {
    bool hasDot = false;
    bool hasF = false;

    for (std::size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        if ((c == '+' || c == '-') && i == 0)
            continue;
        if (c == '.') {
            if (hasDot || i == str.length() - 1)
                return false;
            hasDot = true;
            continue;
        }
        if (c == 'f') {
            if (i != str.length() - 1 || !hasDot)
                return false;
            hasF = true;
            continue;
        }
        if (!std::isdigit(c))
            return false;
    }
    if (str[str.length() -1] == '.')
        return false;
    else if (str[str.length() -1] == 'f' && str[str.length() -2] == '.')
        return false;
    return true;
}


void ScalarConverter::convert(std::string str)
{
    if (str.empty())
        std::cout << "Empty input" << std::endl;
    else if (pseudo(str))
        return;
    else if (str.length() == 1 && !std::isdigit(str[0]))
        str_is_char(str);
    else if (!isValidLiteral(str))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else if (str.find('.') != std::string::npos)
    {
        if (str[str.size() - 1] == 'f')
            str_is_float(str);
        else
            str_is_double(str);
    }
    else
        str_is_int(str);
    return;
} 