#pragma once
class Horario
{
public:
	Horario();
	virtual ~Horario() {}
	void makeCalendar();
private:
	vector<int> slot_vec;
	vector<vector<int>> month_vec;
};

