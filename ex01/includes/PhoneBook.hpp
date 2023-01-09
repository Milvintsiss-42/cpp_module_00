/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:23:55 by ple-stra          #+#    #+#             */
/*   Updated: 2023/01/09 18:27:25 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[8];
	int _nbContacts;

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact();
};
