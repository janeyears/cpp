
#include "Contact.hpp"
#include "Phonebook.hpp"

// FIX UNRELEVANT INPUT TO INDEX SEARCH 
// ADD COLOURS

void printPhoneBookCover() {
	std::cout << "======================================" << std::endl;
	std::cout << "         📞 MY C++ PHONEBOOK       " << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "        Store up to 8 contacts!" << std::endl;
	std::cout << "     Commands: ADD, SEARCH, EXIT" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
}

int main() {

	Phonebook	phonebook;
	std::string	command;

	while(1) {
		printPhoneBookCover();
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH"){
			if (phonebook.getContactCount() == 0) {
				std::cout << "No contacts found. Please add a contact first." << std::endl;
				continue ;
			}
			else
				phonebook.startSearch();
		}
		else if (command == "EXIT") {
			std::cout << "Exiting phonebook. I will delete everything. Goodbye!" << std::endl;
			break;
		} else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
}
