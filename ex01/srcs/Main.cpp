/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:50:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/10 04:54:42 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PhoneBook.hpp"

void menu();

int main()
{
	std::cout << "Kirua rising his hand and \"Book!\"" << std::endl;
	menu();
	std::cout << "\"Book!\"" << std::endl;
	return 0;
}

void menu()
{
	PhoneBook phoneBook;
	std::string option;

	while (1)
	{
		std::cout << "Command: ";
		std::cin >> option;

		if (option == "ADD")
			phoneBook.addContact();
		else if (option == "SEARCH")
			phoneBook.searchContact();
		else if (option == "EXIT" || std::cin.eof())
			return;
		else
			std::cerr << "Invalid command" << std::endl;
	}
}