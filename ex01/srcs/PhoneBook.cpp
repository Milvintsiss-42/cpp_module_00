/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:49:38 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/10 20:39:08 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_nbContacts = 0;
}

PhoneBook::~PhoneBook()
{
}

static void promptField(std::string prompt, std::string &field)
{
	while (field.length() == 0)
	{
		std::cout << prompt;
		getline(std::cin, field);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cerr << "\nForce exit" << std::endl;
			exit(1);
		}
	}
} 

void PhoneBook::addContact()
{
	Contact *contact;
	this->_contacts[this->_nbContacts % 8] = Contact();

	contact = &this->_contacts[this->_nbContacts % 8];
	promptField("First name: ", contact->firstName);
	promptField("Last name: ", contact->lastName);
	promptField("Nickname: ", contact->nickname);
	promptField("Phone number: ", contact->phoneNumber);
	promptField("Darkest secret: ", contact->darkestSecret);
	this->_nbContacts++;
}

static void displayLineElement(std::string element)
{
	if (element.length() > 10)
		std::cout << element.substr(0, 9) << ".";
	else if (element.length() < 10)
		std::cout << std::string(10 - element.length(), ' ') << element;
	else
		std::cout << element;
}

static void displayBookIndex(Contact contacts[8], int nbContacts)
{
	int i;
	Contact *contact;

	i = 0;
	while (i < 8 && i < nbContacts)
	{
		contact = &contacts[i];
		displayLineElement(std::to_string(i));
		std::cout << "|";
		displayLineElement(contact->firstName);
		std::cout << "|";
		displayLineElement(contact->lastName);
		std::cout << "|";
		displayLineElement(contact->nickname);
		std::cout << std::endl;
		i++;
	}
}

void PhoneBook::searchContact()
{
	int index;
	Contact *contact;

	if (this->_nbContacts == 0)
	{
		std::cerr << "The book is empty" << std::endl;
		return;
	}
	displayBookIndex(this->_contacts, this->_nbContacts);
	std::cout << "Index: ";
	std::cin >> index;
	if (std::cin.eof())
	{
		std::cout << "Force exit" << std::endl;
		exit(1);
	}
	if (std::cin.fail() || !std::cin.good() ||
		index < 0 || index >= this->_nbContacts)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	contact = &this->_contacts[index];
	std::cout << "First name: " << contact->firstName << std::endl;
	std::cout << "Last name: " << contact->lastName << std::endl;
	std::cout << "Nickname: " << contact->nickname << std::endl;
	std::cout << "Phone number: " << contact->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << contact->darkestSecret << std::endl;
}