#pragma once
#include "User.h"
#include "Order.h"
#include "Vector.hpp"

class Client : public User
{
private:
	
public:
	Client() = default;
	Client(UserType userType, const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName);
	virtual void registerUser() override; 
	/*virtual void login() override;
	virtual void logout() const override;*/
	
};

