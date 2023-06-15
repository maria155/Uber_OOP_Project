#pragma once
#include "MyString.h"

enum UserType {
	CLIENT,
	DRIVER
};

class User
{
protected:
	UserType userType;
	MyString username;
	MyString password;
	MyString firstName;
	MyString lastName;
public:
	//User() = default;
	//User(UserType userType, const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName);

	void setUserType(UserType userType);
	UserType getUserType() const;

	void setUsername(const MyString& username);
	MyString getUsername() const;

	void setPassword(const MyString& password);
	MyString getPassword() const;

	void setFirstName(const MyString& firstName);
	MyString getFirstName() const;

	void setLastName(const MyString& lastName);
	MyString getLastName() const;

	//virtual void login(const MyString& username, const MyString& password) = 0; 
	virtual void registerUser() = 0;
	virtual void login() = 0;
	virtual void logout() const = 0; 
	virtual ~User() = default;
};

