#include "Driver.h"

Driver::Driver(UserType userType, const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName, const MyString& carNumber, const MyString& phoneNumber)
{
	setUserType(userType);
	setUsername(username);
	setPassword(password);
	setFirstName(firstName);
	setLastName(lastName);
}

void Driver::setCarNumber(const MyString& firstName)
{
	this->carNumber = carNumber;
}

MyString Driver::getCarNumber() const
{
	return carNumber;
}

void Driver::setPhoneNumber(const MyString& lastName)
{
	this->phoneNumber = phoneNumber;
}

MyString Driver::getPhoneNumber() const
{
	return phoneNumber;
}

void Driver::registerUser() 
{
	std::cout << "Please enter your username: " << std::endl;
	std::cin >> username;
	std::cout << "Please enter your password: " << std::endl;
	std::cin >> password;
	std::cout << "Please enter your first name: " << std::endl;
	std::cin >> firstName;
	std::cout << "Please enter your last name: " << std::endl;
	std::cin >> lastName;
	std::cout << "Please enter your car number: " << std::endl;
	std::cin >> carNumber;
	std::cout << "Please enter your phone number: " << std::endl;
	std::cin >> phoneNumber;

}

void Driver::login() 
{
}

void Driver::logout() const
{
}
