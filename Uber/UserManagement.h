#pragma once
#include "Vector.hpp"
#include "Client.h"
#include "Driver.h"

class UserManagement
{
private:
	Vector<Client> clients;
	Vector<Driver> drivers;
	Vector<Order> orders;
	User* loggedUser = nullptr;
public:
	UserManagement();
	//UserManagement(Vector<Client> clients, Vector<Driver> drivers) {};
	void registerClient();
	void registerDriver();
	void logClient();
	void logDriver();
	void logoutClient();
	void logoutDriver();
	void makeOrder();
	Driver* closestDriver(int x, int y, int declinedOrders) const;
	void acceptOrder() const;
	void declineOrder() const;
	void finishOrder() const;
	void checkMessages() const;
	//void clientPays() const;
	void rate() const;
	void cancelOrder() const;
	void pay() const;
	void acceptPayment() const;
	void changeAddress();
	void checkOrder() const;
	void addMoney();

	//void bubbleSort(Vector<Driver> drivers, int size);
};



