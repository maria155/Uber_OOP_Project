#pragma once
#include "Driver.h"
#include "Client.h"
#include "MyString.h"

enum orderStatus {
	NOTACCEPTED,
	ACCEPTED,
	INPROCCESS,
	CANCELLED,
	FINISHED,
	DECLINED
};

class Order
{
private:
	orderStatus statusOfOrder = NOTACCEPTED;
	Driver* currentDriver;
	Client* client;
	MyString firstAddress, secondAddress, additionalInfo;
	int x1, y1, x2, y2;
	int time;
	int id;
	
public:
	int numberOfDeclinedOrders = 0;
	Order() = default;
	Order(User* currentDriver, User* client, const MyString& firstAddress, const MyString& secondAddress, const MyString& additionalInfo,
		int x1, int y1, int x2, int y2);
	//int calculateTime(int x1, int y1, int x2, int y2);
	void changeStatus(orderStatus statusOfOrder);
	void viewOrder() const;
	int getId() const;
};

