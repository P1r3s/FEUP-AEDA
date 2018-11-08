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
	string horaAbertura;
	string horaEncerramento;
	vector<Professor> professores;            // Vector com todos os professores
	vector<Utente> utentes;                   // vector com todos os utentes.
};

class Exception
{
public:
	Exception(string nome) { this->nome = nome; }
	string getNome() { return nome; }

private:
	string nome;
};

