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

#include "Modos.h"
#include "Pessoa.h"
#include "Horario.h"

using namespace std;

class CampoTenis
{
public:
	//CampoTenis(int nCampos, string horaA, string horaE, int lotacao);
	CampoTenis(int nCampos, int lotacao_por_campo);
	~CampoTenis() {}
	string getHoraAbertura();
	string getHoraEncerramento();
	vector<Professor> getProfessors();
	vector<Utente> getUtentes();
	vector<Aula> getAulas();
	vector<Livre> getLivres();
	int NumMaximoUtentesPorCampo() const;
	int getNumProfessores();
	int getNumUtentes();
	int getNumCampos();
	void addAula(Aula a);
	void addAulaVec(string nU, int indexAula, int data, int nSlots);
	void addProf(string nome, int idade);
	void addUtente(string nome, int idade, bool goldCard);
	void addLivre(string nU, int nSlots, int horaI, int data);
	void removeProf(string prof);
	
	

private:
	int nCampos=10;
	int lotacao_por_campo=2;
	int numeroSlots;
	string horaAbertura;
	string horaEncerramento;
	
	vector<Professor> professores;            // Vector com todos os professores
	vector<Utente> utentes;                   // vector com todos os utentes.
	vector<Aula> aulas;
	vector<Livre> livres;

	//vector<int> slot_vec;
	//vector<vector<int>> month_vec;
	vector<Horario> campoHorario;
	
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