#include <iostream>
#include <string>
#include <vector>

#include "Pessoa.h"

using namespace std;

//Construtores

Pessoa::Pessoa(string nome, int idade, string morada, int nif)
{
	this->nome = nome;
	this->idade = idade;
	this->morada = morada;
	this->nif = nif;
}

Professor::Professor(string nome, string sigla, int idade, string morada, int nif) : Pessoa(nome, idade, morada, nif)
{
	this->sigla = sigla;
}

Utente::Utente(string nome, int idade, bool goldCard, string morada, int nif) : Pessoa(nome, idade, morada, nif)
{
	this->goldCard = goldCard;
}


//Funçoes Pessoa

string Pessoa::getName()
{
	return nome;
}

int Pessoa::getAge()
{
	return idade;
}

string Pessoa::getMorada()
{
	return morada;
}

int Pessoa::getNif()
{
	return nif;
}

//Funçoes Professor

int Professor::getNrAulas(string nomeProf) {
	return aulasDoProfessor.size();
}

vector<Aula> Professor::getAulaVec() const
{
	return aulasDoProfessor;
}

void Professor::pushAula(Aula a) {
	aulasDoProfessor.push_back(a);
}

//Funçoes Utentes
vector<Aula> Utente::getAulasUtente() const{
	return aulasDoUtente;
}

vector<Livre> Utente::getLivresUtente() const{
	return livresDoUtente;
}

bool Utente::getGoldCard() const
{
	return goldCard;
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
	if (goldCard)
	{
		return 10;
	}
	return 0;
}

double Utente::getPrecoTotal() {
	if (goldCard) {
		return getPrecoAulas() + getPrecoLivres() + getPrecoCartao();
	}
	return getPrecoAulas() + getPrecoLivres();
}

void Utente::pushAula(Aula a) {
	aulasDoUtente.push_back(a);
}

void Utente::pushLivre(Livre l) {
	livresDoUtente.push_back(l);
}

bool Utente::operator < (const Utente &u1) const
{
	int freq = aulasDoUtente.size() + livresDoUtente.size();
	int freq1 = u1.aulasDoUtente.size() + u1.livresDoUtente.size();

	if (freq < freq1)
		return true;
	else if (freq > freq1)
		return false;
	else
	{
		if (nome < u1.nome)
			return true;
		else
			return false;
	}
}
