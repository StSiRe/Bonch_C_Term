#pragma once
#include "Trouble.h"
#include <string>
class Order
{
public:
	Order();

	void SetOrderID(int orderId);
	int GetOrderID();

	void SetClientID(int clientId);
	int GetClientID();

	void SetDeviceID(int devID);
	int GetDeviceID();

	std::string GetDiagnosticsResult();
	int GetCost();
	std::string Repair();



private:
	int orderID;
	int clientID;

	int deviceID;
	int RepairPrice;
	Trouble tr;
	std::string problem;
};

