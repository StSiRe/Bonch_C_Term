#pragma once
#include <iostream>
class Trouble
{
public:
	std::string GetTrouble()
	{
		std::string problems[4] = { "������� �����","������ � ������ ��","���������� ����������� ��������� ����������","������ ����������" };
		return problems[rand() % 4];
	}
};

