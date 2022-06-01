#include <iostream>
#include <locale.h>
#include "Service.h"


using namespace std;

Service service;

void Repair()
{
	service.AddNewOrder();

	cout << "Как вас зовут:";
	std::string name;
	cin >> name;
	if (service.CheckClientName(name) == -1)
	{
		cout << "Рады Вас приветствовать " << name << endl;
		service.AddNewClient();
		service.Clients[service.Clients.capacity() - 1].SetClientName(name);
	}
	else
	{
		cout << "Рады Вас снова приветствовать " << name << endl;
	}
	service.Orders[service.Orders.capacity() - 1].SetClientID(service.Clients[service.CheckClientName(name)].GetClientID());

	cout << "Что у вас за устройство?" << endl
		<< "1. Стиральная машина" << endl
		<< "2. Посудомоечная машина" << endl
		<< "3. Компьютер" << endl
		<< "4. Телефон" << endl
		<< "5. Ноутбук" << endl
		<< "Так что у вас за устройство:";
	int deviceID;
	cin >> deviceID;
	service.Orders[service.Orders.capacity() - 1].SetDeviceID(deviceID);

	cout << "У вас уже прошла гарантия на устройство?" << endl
		<< "1. Да" << endl
		<< "2. Нет" << endl << "Ответ: ";
	int typeOfRepair = 0;
	cin >> typeOfRepair;

	cout << "НАЧИНАЕМ ДИАГНОСТИКУ..." << endl;
	cout << endl;
	cout << endl;

	cout << "В ходе диагностики была найдена неисправность:" << service.Orders[service.Orders.capacity() - 1].GetDiagnosticsResult() << endl;
	if (typeOfRepair == 2)
	{
		cout << "Ремонт для вас будет бесплантым, поскольку гарантия еще есть" << endl;
	}
	else
	{
		cout << "Стоимость ремонта составит:" << service.Orders[service.Orders.capacity() - 1].GetCost() << endl;
	}
	cout << endl;
	cout << endl;
	cout << "Вы согласны на ремонт?" << endl << "1. Да" << endl << "2. Нет" << endl << "Ваше решение:";
	int repairG = 0;
	cin >> repairG;
	if (repairG == 2)
	{
		cout << "Поняли Вас. Возврат в основное меню..." << endl;
		return;
	}
	else
	{
		cout << "Ремонтируем...." << endl;
		cout << "Результат ремонта:" << service.Orders[service.Orders.capacity() - 1].Repair() << endl;
	}
	cout << "Благодарим Вас " << name << " за посещение нашего сервиса! Поставьте нам 5 по курсовой работе!" << endl;
	cout << endl;
	cout << endl;
}

void GetOrders()
{
	cout << "Введите Ваше имя: ";
	std::string name;
	cin >> name;
	if (service.CheckClientName(name) == -1)
	{
		cout << "Извините, но вы у нас ничего не чинили..." << endl;
		return;
	}
	cout << "Снова здравствуйте, " << name << "!" << endl;
	cout << "Вот ваши прошлые заказы:" << endl;
	int enumirator = 0;
	for (size_t i = 0; i < service.Orders.capacity(); i++)
	{
		if (service.Orders[i].GetClientID() == service.Clients[service.CheckClientName(name)].GetClientID())
		{
			Order tmp = service.Orders[i];
			cout << "[" << enumirator << "]: " << endl
				<< "Тип устройства:" << tmp.GetDeviceID() << endl
				<< "Найденная неисправность:" << tmp.GetDiagnosticsResult() << endl
				<< "Итоговая стоимость ремонта: " << tmp.GetCost() << endl
				<< "Результат ремонта: " << tmp.Repair() << endl << endl;
			enumirator++;
			
		}
	}
	cout << endl;
}

int main()
{

	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "Приветствуем Вас в нашем сервисе-программе!" << endl << "У нас Вы можете починить свою технику!"
			<< "Вы можете:" << endl << "1. Сдать устройство на ремонт" << endl << "2. Узнать историю своих заказов" << endl << "3. Выйти из программы" << endl;
		cout << "Что бы вы хотели сделать:";
		int action = 0;
		cin >> action;
		switch (action)
		{
		case 1:
			Repair();
			break;
		case 2:
			GetOrders();
			break;
		default:
			cout << "Goodbye!" << endl;
			return 0;
			break;
		}
	}
}