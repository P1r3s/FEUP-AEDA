#ifndef CampoTenis_h_
#define CampoTenis_h_

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <unistd.h>
#include <sstream>
#include <list>
#include <algorithm>
#include <iomanip>

//#include "Modos.h"
#include "Pessoa.h"

using namespace std;

class CampoTenis
{
public:
	//CampoTenis(int nCampos, string horaA, string horaE, int lotacao);
	CampoTenis();
	~CampoTenis() {}
	string getHoraAbertura();
	string getHoraEncerramento();
	vector<Professor> getProfessors();
	vector<Utente> getUtentes();
	int NumMaximoUtentesPorCampo() const;
	int getNumProfessores();
	int getNumUtentes();
	void addAula(Aula a);
	void addProf(string nome, int idade);
	void removeProf(string prof);

private:
	int nCampos;
	int lotacao_por_campo;
	int numeroSlots;
	string horaAbertura;
	string horaEncerramento;
	
	vector<Professor> professores;            // Vector com todos os professores
	vector<Utente> utentes;                   // vector com todos os utentes.
	vector<Aula> aulas;
	vector<Livre> livres;
	
};

class Exception
{
public:
	Exception(string nome) { this->nome = nome; }
	string getNome() { return nome; }

private:
	string nome;
};

#endif