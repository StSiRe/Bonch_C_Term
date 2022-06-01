#include "Service.h"
void Service::AddNewOrder()
{
	Order newOrder;
	newOrder.SetOrderID(Orders.capacity());
	Orders.push_back(newOrder);
}
void Service::AddNewClient()
{
	Client newClient;
	newClient.SetClientID(Clients.capacity());
	Clients.push_back(newClient);
}
int Service::CheckClientName(std::string name)
{
	for (size_t i = 0; i < Clients.capacity(); i++)
	{
		if (name == Clients[i].GetClientName())
		{
			return i;
		}
	}
	return -1;
}