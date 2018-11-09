#include "Horario.h"



Horario::Horario()
{
}

void Horario::makeCalendar() {
	int nOfSlots = 18;
	for (int i = 0; i < nOfSlots; i++)
	{
		slot_vec.push_back(0);
	}

	for (int i = 0; i < 20; i++)
	{
		month_vec.push_back(slot_vec);
	}
}
