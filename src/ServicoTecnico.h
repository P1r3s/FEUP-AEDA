#ifndef SERVICOSTECNICOS_H_
#define SERVICOSTECNICOS_H_

#include <iostream>
#include <sstream>

using namespace std;

class ServicoTecnico {
private:
	int disponibilidade, nrReparacoes;
	string nomeTecnico;
public:
	ServicoTecnico(string noTec, int disp, int nrRep){
		nomeTecnico = noTec;
		disponibilidade = disp;
		nrReparacoes = nrRep;
	}
	virtual ~ServicoTecnico() {
	}

	string getNomeTec();

	int getDisponibilidade();

	int getNrReparacoes();

	bool operator <(const ServicoTecnico& o1) const;

};

#endif