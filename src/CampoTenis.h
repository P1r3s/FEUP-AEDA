#pragma once

#include <string>
#include<vector>

using namespace std;

class CampoTenis
{
public:
	CampoTenis(int nCampos, string horaA, string horaE, int lotacao);
	~CampoTenis() {}
	string getHoraAbertura();
	string getHoraEncerramento();
	//vector<Pessoa> getProfessors();
	int NumMaximoUtentes() const;
	void addAula(Aula a);

private:
	int nCampos;
	int lotacao;
	string horaAbertura;
	string horaEncerramento;
	vector<Professor> professores;            //vector com todos os professores
};