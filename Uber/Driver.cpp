#include "Driver.h"

Driver::Driver(UserType userType, const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName, const MyString& carNumber, const MyString& phoneNumber)
{
	setUserType(userType);
	setUsername(username);
	setPassword(password);
	setFirstName(firstName);
	setLastName(lastName);
}

void Driver::setCarNumber(const MyString& firstName)
{
	this->carNumber = carNumber;
}

MyString Driver::getCarNumber() const
{
	return carNumber;
}

void Driver::setPhoneNumber(const MyString& lastName)
{
	this->phoneNumber = phoneNumber;
}

MyString Driver::getPhoneNumber() const
{
	return phoneNumber;
}

void Driver::changeAddress(const MyString& nameOfAddress, int x, int y)
{
	this->nameOfAddress = nameOfAddress;
	point = {x, y}; 
}

void Driver::registerUser() 
{
	std::cout << "Please enter your username: " << std::endl;
	std::cin >> username;
	std::cout << "Please enter your password: " << std::endl;
	std::cin >> password;
	std::cout << "Please enter your first name: " << std::endl;
	std::cin >> firstName;
	std::cout << "Please enter your last name: " << std::endl;
	std::cin >> lastName;
	std::cout << "Please enter your car number: " << std::endl;
	std::cin >> carNumber;
	std::cout << "Please enter your phone number: " << std::endl;
	std::cin >> phoneNumber;

}

//void Driver::login() 
//{
//}
//
//void Driver::logout() const
//{
//}

size_t Driver::getDistance(int c1, int c2) const
{
	int dx = c1 - point.x;
	int dy = c2 - point.y;

	return sqrt(dx * dx + dy * dy);
}

void Driver::receiveOrder(Order* order)
{
	orders.push_back(order);
}

void Driver::acceptOrder(int id, int minutes)
{
	currentOrder = orders[findOrderPerId(id)];
	currentOrder->changeStatus(orderStatus::ACCEPTED);
}

Order* Driver::declineOrder(int id)
{
	int position = findOrderPerId(id);
	
	if (position >= 0) {
		orders[position]->changeStatus(orderStatus::DECLINED);
		Order* order = orders[position];
		orders.deleteAt(position);
		return order;
	}
	else {
		//error message
	}
}

int Driver::findOrderPerId(int id) const
{
	for (int i = 0; i < orders.Size(); i++)
	{
		if (orders[i]->getId() == id) {
			return i;
		}
	}
	return -1;
}
