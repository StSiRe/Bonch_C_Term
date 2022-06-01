#pragma once
#include <vector>
#include "Order.h"
#include "Client.h"
class Service
{
public:
	friend void Repair();
	friend void GetOrders();
private:
	std::vector <Order> Orders;

	std::vector <Client> Clients;

	void AddNewOrder();
	void AddNewClient();
	int CheckClientName(std::string name);
};

