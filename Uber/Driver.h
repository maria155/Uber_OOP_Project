#pragma once
#include "User.h"
#include "Order.h"

class Driver : public User
{
private:
	MyString carNumber;
	MyString phoneNumber;
	MyString nameOfAddress;
	int rating;
	Vector<Order*> orders;
	Order* currentOrder = nullptr;

	struct Point {
		int x;
		int y;

	} point;

public:
	Driver() = default;
	Driver(UserType userType, const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName, 
			const MyString& carNumber, const MyString& phoneNumber);

	void setCarNumber(const MyString& firstName);
	MyString getCarNumber() const;

	void setPhoneNumber(const MyString& lastName);
	MyString getPhoneNumber() const;

	void changeAddress(const MyString& nameOfAddress, int x, int y);
	

	virtual void registerUser() override;
	/*virtual void login() override;
	virtual void logout() const override;*/

	size_t getDistance(int c1, int c2) const;
	void receiveOrder(Order* order);
	void viewOrder() const;
	void acceptOrder(int id, int minutes);
	Order* declineOrder(int id);
	int findOrderPerId(int id) const;
};

