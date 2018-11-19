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


///Funçoes Pessoa

string Pessoa::getName()
{
	return nome;
}

int Pessoa::getAge()
{
	return idade;
}

///Funçoes Professor

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

///Funçoes Utentes

bool Utente::getGoldCard()
{
	return goldCard;
}

double Utente::getPrice() const {

	double precoTotalLivres = 0;
	for (unsigned int i = 0; i < livresDoUtente.size(); i++) {
		precoTotalLivres += livresDoUtente[i].PrecoSessao();
	}

	double precoTotalAulas = 0;
	if (goldCard) {
		precoTotalAulas = aulasDoUtente.size()*aulasDoUtente[0].PrecoSessao()*0.85;
	}
	else {
		precoTotalAulas = aulasDoUtente.size()*aulasDoUtente[0].PrecoSessao();
	}

	return precoTotalLivres + precoTotalAulas;
}

void Utente::aulasAdd(Aula a)
{
	aulasDoUtente.push_back(a);
}

void Utente::livresAdd(Livre l)
{
	livresDoUtente.push_back(l);
}