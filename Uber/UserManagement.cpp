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
	if (loggedUser == nullptr) {
		throw std::logic_error("There is no such user in the system!");
		
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
	if (loggedUser == nullptr) {
		throw std::logic_error("There is no such user in the system!");
		
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

void UserManagement::makeOrder()
{
	MyString addressName1, addressName2, additionalInfo;
	size_t numberOfPeople;
	int x1, x2, y1, y2;

	std::cout << "Please enter the name of your location: " << std::endl;
	std::cin >> addressName1;
	std::cout << "Please enter the coordinates of you location: " << std::endl;
	std::cin >> x1 >> y1;
	std::cout << "Please enter the name of the destination you would like to go to: " << std::endl;
	std::cin >> addressName2;
	std::cout << "Please enter the coordinates of the location you would like to go to: " << std::endl;
	std::cin >> x2 >> y2;
	
	std::cout << "Would you like to add any other information?" << std::endl << "If yes, please enter 1, if not - enter 2." << std::endl;
	int input;
	std::cin >> input;
	if (input == 1) {
		std::cin >> additionalInfo;
		std::cout << "The additional information has been added successfully!" << std::endl;
	}
	else if (input == 2) {
		std::cout << "No additional information will be added!" << std::endl;
	}
	else {
		throw std::logic_error("Invalid input!");
	}
	
	//logoutClient();
	//return closestDriver(x1, y1);
	Driver* currentDriver = closestDriver(x1, y1, 0);
	Order order(currentDriver, loggedUser, addressName1, addressName2, additionalInfo, x1, y1, x2, y2);
	orders.push_back(order);
	currentDriver->receiveOrder(&order);
}

Driver* UserManagement::closestDriver(int x, int y, int declinedOrders) const
{
	/*int minDistance = drivers[0].getDistance(x, y);
	Driver* wantedDriver = &drivers[0];

	for (size_t i = 0; i < drivers.Size(); i++)
	{
		size_t distance = drivers[i].getDistance(x, y);
		if (i != 0 && distance < minDistance) {
			minDistance = distance;
			wantedDriver = &drivers[i];
		}
	}
	return wantedDriver;*/
	//Order order;
	Driver* closestDriver = &drivers[0];
	int closestDistance = closestDriver->getDistance(x, y);

	for (size_t i = 1; i < drivers.Size(); i++)
	{
		int distance = drivers[i].getDistance(x, y);
		if (distance < closestDistance)
		{
			closestDriver = &drivers[i];
			closestDistance = distance;

			for (size_t j = i; j > 0; j--)
			{
				drivers[j] = drivers[j - 1];
			}
			drivers[0] = *closestDriver;
		}
	}

	return &drivers[declinedOrders];
	
}

void UserManagement::acceptOrder() const
{
	int minutes, id;
	std::cout << "How many minutes is the order going to take?" << std::endl;
	std::cin >> minutes;
	std::cout << "Choose an id: " << std::endl;
	std::cin >> id;
	
	Driver* driver = dynamic_cast<Driver*>(loggedUser);
	if (driver != nullptr) {
		driver->acceptOrder(id, minutes);
	}
	else {
		std::cout << "Only drivers can accept an order.";
	}
		
	
}

void UserManagement::declineOrder() const
{
	int id;
	std::cout << "Choose an id: " << std::endl;
	std::cin >> id;

	Driver* driver = dynamic_cast<Driver*>(loggedUser);
	if (driver != nullptr) {
		Order* currentOrder = driver->declineOrder(id);
		Driver* currentDriver = closestDriver(currentOrder->getX1(), currentOrder->getY1(), currentOrder->getNumberOfDeclinedOrders());
		if (currentOrder->changeDriver(currentDriver)) {
			currentDriver->receiveOrder(currentOrder);
		}
		
	}
	else {
		std::cout << "Only drivers can decline an order.";
	}
}




