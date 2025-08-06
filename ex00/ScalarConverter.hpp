/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:09:39 by ngastana          #+#    #+#             */
/*   Updated: 2025/07/29 16:27:06 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <cctype> 

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class ScalarConverter
{
    public:
        static void convert(std::string str);
    private:
        ScalarConverter(void);
        ScalarConverter& operator=(const ScalarConverter& other);
        ScalarConverter(const ScalarConverter& copy);
        ~ScalarConverter();
};

class NonDisplayableException: public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Exception. Non displayable");
        }
};

class ImpossibleException: public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Exception. Impossible");
        }
};

#endif