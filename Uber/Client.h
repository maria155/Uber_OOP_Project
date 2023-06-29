#pragma once
#include "User.h"
#include "Order.h"
#include "Vector.hpp"

class Client : public User
{
private:
	Order* currentOrder = nullptr;
public:
	Client() = default;
	Client(UserType userType, const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName);
	virtual void registerUser() override; 
	Order* getCurrentOrder() const;
	void pay();
	Order* rate(const MyString& firstName, const MyString& lastName, double rating) const;
	void checkOrder() const;
};

