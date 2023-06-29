#include "Client.h"
#include "stdexcept"

Client::Client(UserType userType, const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName)
{
	setUserType(userType);
	setUsername(username);
	setPassword(password);
	setFirstName(firstName);
	setLastName(lastName);
}

void Client::registerUser() 
{
	std::cout << "Please enter your username: " << std::endl;
	std::cin >> username;
	std::cout << "Please enter your password: " << std::endl;
	std::cin >> password;
	std::cout << "Please enter your first name: " << std::endl;
	std::cin >> firstName;
	std::cout << "Please enter your last name: " << std::endl;
	std::cin >> lastName;
}

Order* Client::getCurrentOrder() const
{
	return currentOrder;
}

void Client::pay()
{
	if (currentOrder->getStatus() == orderStatus::FINISHED) {
		double amount = currentOrder->calculatePayment();
		if (currentMoney >= amount) {
			currentMoney -= amount;
			currentOrder->pay();
		}
		else {
			std::cout << "WE ARE CALLING THE POLICE!" << std::endl;
		}
	}
	else {
		std::cout << "You cannot pay for an order that is not finished!" << std::endl;
	}
}

Order* Client::rate(const MyString& firstName, const MyString& lastName, double rating) const
{
	return nullptr;
}

void Client::checkOrder() const
{
	currentOrder->viewOrder();
}

