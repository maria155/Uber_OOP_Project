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
	orderStatus statusOfOrder;
	Driver* currentDriver;
	Client* currentClient;
	MyString firstAddress, secondAddress, additionalInfo;
	int x1, y1, x2, y2;
	int timeNeeded;
	int id;
	int numberOfDeclinedOrders = 0;
	bool isPaid = false;
public:
	Order() = default;
	Order(Driver* currentDriver, Client* currentClient, const MyString& firstAddress, const MyString& secondAddress, const MyString& additionalInfo,
		int x1, int y1, int x2, int y2);
	void changeStatus(orderStatus statusOfOrder);
	void viewOrder() const;
	int getId() const;
	bool changeDriver(Driver* driver);
	int getX1() const;
	int getY1() const;
	int getX2() const;
	int getY2() const;
	bool isItPaid() const;
	orderStatus getStatus() const;
	const MyString& getNameOfSecondAddress() const;
	int getNumberOfDeclinedOrders() const;
	size_t getMoneyPaid() const;
	double calculatePayment() const;
	void pay();
	void rate(double rating) const;
};

