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
	vector<vector<int>> getMonthVec();
	vector<int> getSlotVec();
private:
	vector<int> slot_vec;
	vector<vector<int>> month_vec;
};


#endif