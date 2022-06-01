#pragma once
#include <iostream>
class Trouble
{
public:
	std::string GetTrouble()
	{
		std::string problems[4] = { "Сгорела плата","Ошибка в работе ПО","Физическое повреждение элементов устройства","Сгорел контроллер" };
		return problems[rand() % 4];
	}
};

