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

vector<int> Horario::getSlotVec()
{
	return slot_vec;
}

void Horario::makeCalendar() {
	int nOfSlots = 20;
	for (int i = 0; i < nOfSlots; i++)
	{
		slot_vec.push_back(0);
	}

	for (int i = 0; i < 31; i++)
	{
		month_vec.push_back(slot_vec);
	}
}
