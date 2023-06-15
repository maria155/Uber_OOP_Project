
#pragma once
#include "Vector.hpp"
#include "Client.h"
#include "Driver.h"

class UserManagement
{
private:
	Vector<Client> clients;
	Vector<Driver> drivers;
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
};



