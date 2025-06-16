#include "Phonebook.hpp"

Phonebook::Phonebook(){
	index = 0;
	contactCount = 0;
}
Phonebook::~Phonebook() {}

int Phonebook::getContactCount() {
	return contactCount;
}

void Phonebook::addContact() {

	Contact newContact;
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	while (input.empty()) {
 		std::cout << "First name cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "Last name cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "Nickname cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "Phone number cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "Darkest secret cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	newContact.setDarkestSecret(input);

	contacts[index] = newContact;
	if (contactCount < 8)
		contactCount++;
	index = (index + 1) % 8;
	std::cout << "Contact added successfully! Returning to the main menu." << std::endl;
}

void Phonebook::startSearch() {
	int selectedIndex;
	std::cout << "============================================" << std::endl;
	std::cout << "              📞 MY C++ PHONEBOOK           " << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < this->contactCount; i++) {
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contacts[i].getShortFirstName() << "|";
		std::cout << std::setw(10) << contacts[i].getShortLastName() << "|";
		std::cout << std::setw(10) << contacts[i].getShortNickname() << "|" << std::endl;
	}
	std::cout << "============================================" << std::endl;
	std::cout << "Enter index of the contact to view details: ";

	if (!(std::cin >> selectedIndex)) {
		std::cout << "Invalid input (not an integer). Returning to main menu." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush the input buffer
		return;
	}
	std::cin.ignore(); // discard leftover newline
	if (selectedIndex < 0 || selectedIndex >= this->contactCount) {
		std::cout << "Invalid index. Returning to main menu." << std::endl;
		return;
	}
	else {
		std::cout << "Contact details:" << std::endl;
		std::cout << "First Name: " << contacts[selectedIndex].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[selectedIndex].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[selectedIndex].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[selectedIndex].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[selectedIndex].getDarkestSecret() << std::endl;
	}
}
