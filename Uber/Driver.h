#pragma once
#include "User.h"

class Driver : public User
{
private:
	MyString carNumber;
	MyString phoneNumber;
public:
	Driver() = default;
	Driver(UserType userType, const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName, 
			const MyString& carNumber, const MyString& phoneNumber);

	void setCarNumber(const MyString& firstName);
	MyString getCarNumber() const;

	void setPhoneNumber(const MyString& lastName);
	MyString getPhoneNumber() const;

	virtual void registerUser() override;
	virtual void login() override;
	virtual void logout() const override;
};

