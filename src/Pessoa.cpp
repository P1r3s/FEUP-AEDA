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

Professor::Professor(string nome, string sigla, int idade) : Pessoa(nome, idade)
{
	this->sigla = sigla;
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

int Professor::getNrAulas(string nomeProf) {
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
vector<Aula> Utente::getAulasUtente() {
	return aulasDoUtente;
}

vector<Livre> Utente::getLivresUtente() {
	return livresDoUtente;
}

bool Utente::getGoldCard()
{
	return goldCard;
}
/*
void Utente::aulasAdd(Aula a)
{
	aulasDoUtente.push_back(a);
}

void Utente::livresAdd(Livre l)
{
	livresDoUtente.push_back(l);
}
*/


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

void Utente::pushAula(Aula a) {
	aulasDoUtente.push_back(a);
}

/*
void Utente::switchVec(vector<Aula> &auxA) {
	for (unsigned int i = 0; i < aulasDoUtente.size(); i++)
	{
		auxA.push_back(aulasDoUtente[i]);
	}
}

Aula Utente::getAulaUnica(int i) {
	return aulasDoUtente[i];
}
*/

void Utente::pushLivre(Livre l) {
	livresDoUtente.push_back(l);
}

void Professor::pushAula(Aula a) {
	aulasDoProfessor.push_back(a);
}

