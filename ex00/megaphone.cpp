/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:36:49 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/09 21:44:27 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void toUpperCase(char *str);

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	argc--;
	argv++;
	while (argc--)
	{
		toUpperCase(*argv);
		std::cout << *argv;
		argv++;
	}
	std::cout << std::endl;
	return 0;
}

void toUpperCase(char *str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}