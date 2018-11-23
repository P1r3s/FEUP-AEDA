#include <vector>

#include "Horario.h"

using namespace std;

Horario::Horario()
{
}

vector<vector<int>> Horario::getMonthVec()
{
	return month_vec;
}

vector<int> Horario::getDayVec()
{
	return day_vec;
}

void Horario::makeCalendar() {
	
	for (int i = 0; i < 31; i++)
	{
		day_vec.push_back(0);
	}

	for (int i = 0; i < 20; i++)
	{
		month_vec.push_back(day_vec);
	}
}

int Horario::getOcupation(int dia, int indexSlot)
{
	return month_vec[indexSlot][dia];
}

void Horario::addOcupation(int dia, int indexSlot)
{
	month_vec[indexSlot][dia] += 1;
}
