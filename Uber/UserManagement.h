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
	void giveRating();
	void acceptOrder() const;
	void declineOrder() const;
	//void bubbleSort(Vector<Driver> drivers, int size);
};



