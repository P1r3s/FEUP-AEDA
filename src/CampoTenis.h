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
	CampoTenis();
	~CampoTenis() {}
	string getHoraAbertura();
	string getHoraEncerramento();
	string returnSigla();
	vector<Professor> getProfessors();
	vector<Utente> getUtentes();
	vector<Aula> getAulas();
	vector<Livre> getLivres();
	vector<Horario> getHorario();
	int getNumSlots() const;
	int NumMaximoUtentesPorCampo() const;
	int getNumProfessores();
	int getNumUtentes();
	int getNumCampos();
	void addAula(int dia, string horaInicio);
	void addProf(string nome, string sigla, int idade);
	void addUtente(string nome, int idade, bool goldCard);
	void addLivre(int dia, string horaInicio, int nrSlots);
	void removeUtente(string ute);
	void removeProf(string prof);
	void displayHorario();
	void addAulaUtente(string nome, int dia, string horai);
	void addLivreUtente(string nome, int dia, string horai, int nrSlots);
	//void addCampo();


private:
	int nCampos;
	int lotCampo;
	int nSlots;
	string horaAbertura;
	string horaEncerramento;

	vector<Professor> professores;            // Vector com todos os professores
	vector<Utente> utentes;                   // vector com todos os utentes.
	vector<Aula> aulas;
	vector<Livre> livres;

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