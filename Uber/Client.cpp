#include "Client.h"
#include "stdexcept"

Client::Client(UserType userType, const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName)
{
	setUserType(userType);
	setUsername(username);
	setPassword(password);
	setFirstName(firstName);
	setLastName(lastName);
}

void Client::registerUser() 
{
	/*std::cout << "Please enter what type of user you are (1 for client, 2 for driver): " << std::endl;
	std::cin >> userType;
	if (userType != 1) {
		throw std::logic_error("If you are a client, your user type should be 1!");
	}*/
	std::cout << "Please enter your username: " << std::endl;
	std::cin >> username;
	std::cout << "Please enter your password: " << std::endl;
	std::cin >> password;
	std::cout << "Please enter your first name: " << std::endl;
	std::cin >> firstName;
	std::cout << "Please enter your last name: " << std::endl;
	std::cin >> lastName;
}

//void Client::login() 
//{
//	/*std::cout << "Please enter your username: " << std::endl;
//	std::cin >> username;
//	std::cout << "Please enter your password: " << std::endl;
//	std::cin >> password;*/
//}
//
//void Client::logout() const
//{
//}
