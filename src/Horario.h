#ifndef Horario_h_
#define Horario_h_

#pragma once

#include <vector>

using namespace std;

class Horario
{
public:
	Horario();
	virtual ~Horario() {}
	void makeCalendar();
	void addOcupation(int dia, int indexSlot);
	vector<vector<int>> getMonthVec();
	vector<int> getDayVec();
	int getOcupation(int dia, int indexSlot);
private:
	vector<int> day_vec;						// Vector com os dias do mes
	vector<vector<int>> month_vec;				// Matriz que representa o horário mensal
};


#endif