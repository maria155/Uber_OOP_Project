#include <iostream>
#include "UserManagement.h"

void menu() {
	UserManagement uManagement;
	while (true) {
		std::cout << "Welcome to our online platform UBER!" << std::endl << "Are you a client or a driver?" << std::endl;
		int input, num;
		std::cout << "If you are a client, enter 1. If you are a driver, enter 2. If you want to exit, enter 3." << std::endl;
		std::cin >> input;
		switch (input)
		{
		case 1:
			std::cout << "1. Login \n2. Register \n3. Logout \n4. Make order \n5. Check order \n6. Cancel order \n7. Pay order \n8. Rate order \n9. Add money \n";
			std::cin >> num;
			switch (num)
			{
			case 1:
				uManagement.logClient();
				break;
			case 2:
				uManagement.registerClient();
				break;
			case 3: uManagement.logoutClient();
				break;
			case 4: uManagement.makeOrder();
				break;
			case 5: uManagement.checkOrder();
				break;
			case 6: uManagement.cancelOrder();
				break;
			case 7: uManagement.pay();
				break;
			case 8: uManagement.rate();
				break;
			case 9: uManagement.addMoney();
				break;
			default: std::cout << "No such command!\n";
				break;
			}
			break;
		case 2:
			std::cout << "1. Login \n2. Register \n3. Logout \n4. Change address \n5. Check messages \n6. Accept order \n7. Decline order \n8. Finish order \n9. Accept payment \n";
			std::cin >> num;
			switch (num)
			{
			case 1:
				uManagement.logDriver();
				break;
			case 2:
				uManagement.registerDriver();
				break;
			case 3: uManagement.logoutDriver();
				break;
			case 4: uManagement.changeAddress();
				break;
			case 5: uManagement.checkMessages();
				break;
			case 6: uManagement.acceptOrder();
				break;
			case 7: uManagement.declineOrder();
				break;
			case 8: uManagement.finishOrder();
				break;
			case 9: uManagement.acceptPayment();
				break;
			default: std::cout << "No such command!\n";
				break;
			}
			break;
		case 3: return;
			break;
		default:  std::cout << "No such command!\n";
			break;
		}
	}
}