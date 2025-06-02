#include "Contact.hpp"

Contact::Contact() {
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

Contact::~Contact() {}

void Contact::setFirstName(const std::string& firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
	this->lastName = lastName;
}

void Contact::setNickname(const std::string& nickname) {
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
	this->darkestSecret = darkestSecret;
}

std::string Contact::getShortFirstName() const {
	if (this->firstName.length() > 10) {
		return this->firstName.substr(0, 9) + ".";
	}
	else
		return this->firstName;
}

std::string Contact::getShortLastName() const {
	if (this->lastName.length() > 10) {
		return this->lastName.substr(0, 9) + ".";
	}
	else
		return this->lastName;
}

std::string Contact::getShortNickname() const {
	if (this->nickname.length() > 10) {
		return this->nickname.substr(0, 9) + ".";
	}
	else
		return this->nickname;
}

std::string Contact::getFirstName() const {
	return this->firstName;
}

std::string Contact::getLastName() const {
	return this->lastName;
}

std::string Contact::getNickname() const {
	return this->nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return this->darkestSecret;
}