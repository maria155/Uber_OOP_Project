#include "UserManagement.h"

UserManagement::UserManagement()
{
	//clients = 
}

void UserManagement::registerClient()
{
	int userType;
	std::cout << "Please enter what type of user you are (1 for client, 2 for driver): " << std::endl;
	std::cin >> userType;
	if (userType != 1) {
		throw std::logic_error("If you are a client, your user type should be 1!");
	}

	Client client;
	client.registerUser();
	clients.push_back(client);
}

void UserManagement::registerDriver()
{
	int userType;
	std::cout << "Please enter what type of user you are (1 for client, 2 for driver): " << std::endl;
	std::cin >> userType;
	if (userType != 2) {
		throw std::logic_error("If you are a driver, your user type should be 2!");
	}

	Driver driver;
	driver.registerUser();
	drivers.push_back(driver);
}

void UserManagement::logClient()
{
	MyString username, password;
	std::cout << "Please enter your username: " << std::endl;
	std::cin >> username;
	std::cout << "Please enter your password: " << std::endl;
	std::cin >> password;

	for (size_t i = 0; i < clients.Size(); i++)
	{
		if (clients[i].getUsername() == username && clients[i].getPassword() == password) {
			loggedUser = &clients[i];
		}
	}
}

void UserManagement::logDriver()
{
	MyString username, password;
	std::cout << "Please enter your username: " << std::endl;
	std::cin >> username;
	std::cout << "Please enter your password: " << std::endl;
	std::cin >> password;

	for (size_t i = 0; i < drivers.Size(); i++)
	{
		if (drivers[i].getUsername() == username && drivers[i].getPassword() == password) {
			loggedUser = &drivers[i];
		}
	}
}

void UserManagement::logoutClient()
{
	loggedUser = nullptr;
}

void UserManagement::logoutDriver()
{
	loggedUser = nullptr;
}
