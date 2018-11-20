#include <iostream>
#include <string>
#include <vector>

#include "Pessoa.h"



using namespace std;

///Construtores

Pessoa::Pessoa(string nome, int idade)
{
	this->nome = nome;
	this->idade = idade;
}

Professor::Professor(string nome, int idade) : Pessoa(nome, idade)
{
}

Utente::Utente(string nome, int idade, bool goldCard) : Pessoa(nome, idade)
{
	this->goldCard = goldCard;
}


///Fun�oes Pessoa

string Pessoa::getName()
{
	return nome;
}

int Pessoa::getAge()
{
	return idade;
}

///Fun�oes Professor

int Professor::getNrAulas() {
	return aulasDoProfessor.size();
}

vector<Aula> Professor::getAulaVec()
{
	return aulasDoProfessor;
}

void Professor::aulasAdd(Aula a)
{
	aulasDoProfessor.push_back(a);
}

///Fun�oes Utentes

bool Utente::getGoldCard()
{
	return goldCard;
}

void Utente::aulasAdd(Aula a)
{
	aulasDoUtente.push_back(a);
}

void Utente::livresAdd(Livre l)
{
	livresDoUtente.push_back(l);
}

double Utente::getPrecoLivres() {
	double precoTotalLivres = 0;
	for (unsigned int i = 0; i < livresDoUtente.size(); i++) {
		precoTotalLivres += livresDoUtente[i].PrecoSessao();
	}
	return precoTotalLivres;
}

double Utente::getPrecoAulas() {
	double precoTotalAulas = 0;
	for (unsigned int i = 0; i < aulasDoUtente.size(); i++) {
		precoTotalAulas += aulasDoUtente[i].PrecoSessao();
	}
	if (goldCard == true)
	{
		precoTotalAulas = precoTotalAulas * 0.85;
	}
	return precoTotalAulas;
}

double Utente::getPrecoCartao() {
	if (goldCard == true)
	{
		return 10;
	}
	return 0;
}

double Utente::getPrecoTotal() {
	return getPrecoAulas() + getPrecoLivres() + getPrecoCartao();
}