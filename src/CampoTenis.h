#ifndef CampoTenis_h_
#define CampoTenis_h_

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
	bool insertHorario(int dia, string horaInicio, int slots);
	bool addAula(int dia, string horaInicio);
	bool addLivre(int dia, string horaInicio, int nrSlots);
	void addProf(string nome, string sigla, int idade);
	void addUtente(string nome, int idade, bool goldCard);
	void removeUtente(string ute);
	void removeProf(string prof);
	void displayHorario();
	void addAulaUtente(string nome, int dia, string horai);
	void addLivreUtente(string nome, int dia, string horai, int nrSlots);
	void Calendar();


private:
	int nCampos;							 // numero de campos disponiveis pela empressa
	int lotCampo;							 // numero maximo de pessoas por campo numa mesma hora
	int nSlots;								 // numero de slots de meia hora disponiveis para marcação de um modo
	string horaAbertura;					 // horas a que os campos abrem
	string horaEncerramento;				 // horas a que os campos fecham

	vector<Professor> professores;            // Vector com todos os professores
	vector<Utente> utentes;                   // Vector com todos os utentes
	vector<Aula> aulas;						  // Vector com todas as aulas marcadas
	vector<Livre> livres;					  // Vector com todos os livres marcados

	vector<Horario> campoHorario;			  // Vector com a matriz que representa o horario

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