#ifndef SERVICOSTECNICOS_H_
#define SERVICOSTECNICOS_H_

#include <iostream>
#include <sstream>

using namespace std;

/**
*  Representa um tecnico
*/
class ServicoTecnico {
private:
	int disponibilidade, nrReparacoes;			//disponibilidade, numero de reparacoes do tecnico
	string nomeTecnico;							//nome do tecnico
public:
	/**
	*  @brief construtor do servico tecnico
	*
	*@param nome do tecnico
	*@param disponibilidade do tecnico
	*@param numero de reparacoes que o tecnico ja realizou
	*/
	ServicoTecnico(string noTec, int disp, int nrRep){
		nomeTecnico = noTec;
		disponibilidade = disp;
		nrReparacoes = nrRep;
	}
	virtual ~ServicoTecnico() {
	}

	/**
	*  @brief retorna nome do tecnico
	*/
	string getNomeTec();

	/**
	*  @brief retorna disponibilidade do tecnico
	*/
	int getDisponibilidade();

	/**
	*  @brief retorna numero de reparacoes do tecnico
	*/
	int getNrReparacoes();

	/**
	*  @brief operador < que ordena tecnicos por ordem de disponibilidade destes
	*/
	bool operator <(const ServicoTecnico& o1) const;

};

#endif