#include "User.h"

//User::User(UserType userType, MyString username, MyString password, MyString firstName, MyString lastName)
//{
//	setUserType(userType);
//	setUsername(username);
//	setPassword(password);
//	setFirstName(firstName);
//	setLastName(lastName);
//}

void User::setUserType(UserType userType)
{
	this->userType = userType;
}

UserType User::getUserType() const
{
	return userType;
}

void User::setUsername(const MyString& username)
{
	this->username = username;
}

MyString User::getUsername() const
{
	return username;
}

void User::setPassword(const MyString& password)
{
	this->password = password;
}

MyString User::getPassword() const
{
	return password;
}

void User::setFirstName(const MyString& firstName)
{
	this->firstName = firstName; 
}

MyString User::getFirstName() const
{
	return firstName;
}

void User::setLastName(const MyString& lastName)
{
	this->lastName = lastName;
}

MyString User::getLastName() const
{
	return lastName;
}

void User::addMoney(size_t money)
{
	currentMoney += money;
}

size_t User::getMoney() const
{
	return currentMoney;
}

