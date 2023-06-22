#include "Order.h"

Order::Order(User* currentDriver, User* client, const MyString& firstAddress, const MyString& secondAddress, const MyString& additionalInfo, int x1, int y1, int x2, int y2)
{
	this->statusOfOrder = orderStatus::NOTACCEPTED;
	this->currentDriver = (Driver*)currentDriver;
	this->client = (Client*)client;
	this->firstAddress = firstAddress;
	this->secondAddress = secondAddress;
	this->additionalInfo = additionalInfo;
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	//random id must be generated here 
}

//int Order::calculateTime(int x1, int y1, int x2, int y2)
//{
//	int dx = x1 - x2;
//	int dy = y1 - y2;
//
//	return sqrt(dx * dx + dy * dy) * 10;
//}

void Order::changeStatus(orderStatus statusOfOrder)
{

	//this->statusOfOrder = statusOfOrder;
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
	//not finished
}

void Order::viewOrder() const
{
	std::cout << "firstAddress" << std::endl;
	//to be continued with info about the order
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
		//message
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

int Order::getNumberOfDeclinedOrders() const
{
	return numberOfDeclinedOrders;
}
