/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:16:35 by ngastana          #+#    #+#             */
/*   Updated: 2025/08/06 09:18:41 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
        return (std::cout << "Empty input" << std::endl, 0);
    std::string str = argv[1];
    ScalarConverter::convert(str);
    return (0);
}