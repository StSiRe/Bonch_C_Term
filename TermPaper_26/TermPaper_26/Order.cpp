#include "Order.h"
Order::Order()
{
	RepairPrice = std::rand();
	problem = tr.GetTrouble();
}
void Order::SetOrderID(int orderId)
{
	orderID = orderId;
}
int Order::GetOrderID()
{
	return orderID;
}
void Order::SetClientID(int clientId)
{
	clientID = clientId;
}
int Order::GetClientID()
{
	return clientID;
}
std::string Order::GetDiagnosticsResult()
{
	return problem;
}
int Order::GetCost()
{
	return RepairPrice;
}
std::string Order::Repair()
{
	int r = std::rand();
	if (r % 2 == 0)
	{
		return "Успешный ремонт";
	}
	else
	{
		return "Ремонт не удался(";
	}
}
void Order::SetDeviceID(int devID)
{
	deviceID = devID;
}
int Order::GetDeviceID()
{
	return deviceID;
}