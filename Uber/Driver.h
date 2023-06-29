#pragma once
#include "User.h"
#include "Order.h"

class Driver : public User
{
private:
	MyString carNumber;
	MyString phoneNumber;
	MyString nameOfAddress;
	double rating = 0;
	int countOfRating = 0;
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
	size_t getDistance(int c1, int c2) const;
	void receiveOrder(Order* order);
	void acceptOrder(int id, int minutes);
	Order* declineOrder(int id);
	Order* finishOrder(int id);
	void checkMessages() const;
	double getRating() const;
	void setRating(double rating);
	void acceptPayment(int id);
};

