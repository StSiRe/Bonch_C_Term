#pragma once
#include <iostream>
#include "Trouble.h"
class Device
{
public:
	int GetDeviceID()
	{
		return devID;
	}
	void SetDeviceID(int deviceID)
	{
		devID = deviceID;
	}
	std::string Diagnostic()
	{
		Trouble tr;
		return tr.GetTrouble();
	}
	int GetRepairPrice()
	{
		return rand();
	}
	void Repair()
	{
		std::cout << "Repairing...." << std::endl;
	}
private:
	int devID = 0;
};

