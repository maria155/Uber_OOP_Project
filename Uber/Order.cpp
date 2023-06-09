#include "Order.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

Order::Order(Driver* currentDriver, Client* currentClient, const MyString& firstAddress, const MyString& secondAddress, const MyString& additionalInfo, int x1, int y1, int x2, int y2)
{
	this->statusOfOrder = orderStatus::NOTACCEPTED;
	this->currentDriver = currentDriver;
	this->currentClient = currentClient;
	this->firstAddress = firstAddress;
	this->secondAddress = secondAddress;
	this->additionalInfo = additionalInfo;
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;

	srand((unsigned)time(NULL));
	id = rand() % 100; //generates a random number between 0 and 99 for the id
}

void Order::changeStatus(orderStatus statusOfOrder)
{

	
	if (this->statusOfOrder == orderStatus::ACCEPTED) {
		this->statusOfOrder = orderStatus::INPROCCESS;
	}
	else if (this->statusOfOrder == orderStatus::DECLINED) {
		numberOfDeclinedOrders++;
		this->statusOfOrder = statusOfOrder;
	}
	else if (this->statusOfOrder == orderStatus::NOTACCEPTED) {
		this->statusOfOrder = statusOfOrder;
	}
	else if (this->statusOfOrder == orderStatus::CANCELLED) {
		this->statusOfOrder = statusOfOrder;
	}
}

void Order::viewOrder() const
{
	std::cout << "Name of driver: " << currentDriver->getFirstName() << " "  << currentDriver->getLastName() << std::endl;
	std::cout << "Name of client: " << currentClient->getFirstName() << " " << currentClient->getLastName() << std::endl;
	std::cout << "First address: " << firstAddress<< std::endl;
	std::cout << "Second address: " << secondAddress << std::endl;
	std::cout << "Additional information: " << additionalInfo << std::endl;
	std::cout << "Coordinates of current address: " << x1 << " " << y1 << std::endl;
	std::cout << "Coordinates of the address the client wants to go to: " << x2 << " " << y2 << std::endl;
	std::cout << "Order ID: " << id << std::endl;
}

int Order::getId() const
{
	return id;
}

bool Order::changeDriver(Driver* driver)
{
	if (statusOfOrder == orderStatus::DECLINED) {
		delete currentDriver;
		currentDriver = driver;
		changeStatus(orderStatus::NOTACCEPTED);
		return true;
	}
	else {
		std::cout << "Error!" << std::endl;
		return false;
	}
}

int Order::getX1() const
{
	return x1;
}

int Order::getY1() const
{
	return y1;
}

int Order::getX2() const
{
	return x2;
}

int Order::getY2() const
{
	return y2;
}

const MyString& Order::getNameOfSecondAddress() const
{
	return secondAddress;
}

orderStatus Order::getStatus() const
{
	return statusOfOrder;
}

int Order::getNumberOfDeclinedOrders() const
{
	return numberOfDeclinedOrders;
}

bool Order::isItPaid() const
{
	return isPaid;
}


double Order::calculatePayment() const
{
	int dx = x1 - x2;
	int dy = y1 - y2;
	
	return sqrt(dx * dx + dy * dy) * 1.5; //we multiply the distance between the two locations by 1.5 to get the money the client has to pay the driver
}

void Order::rate(double rating) const
{
	currentDriver->setRating(rating);
}

void Order::pay()
{
	isPaid = true;
}
