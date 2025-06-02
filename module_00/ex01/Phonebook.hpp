
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
	private:
		int index;
		int contactCount;
		Contact contacts[8];
	public:
		Phonebook();
		~Phonebook();
		int getContactCount();
		void addContact();
		void startSearch();
};

#endif