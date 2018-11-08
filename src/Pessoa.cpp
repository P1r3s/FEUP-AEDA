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

///

string Pessoa::getName()
{
	return nome;
}

int Pessoa::getAge()
{
	return idade;
}

/*
string Professor::getEntryHour()
{
	return horario[0];
}

string Professor::getOffHour()
{
	return horario[1];
}
*/

int Professor::getNrAulas() {
	return aulas.size();
}

vector<Aula> Professor::getAulaVec()
{
	return aulas;
}

bool Utente::getGoldCard()
{
	return goldCard;
}

double Utente::getPrice() const {

	//falta implementar
//	if (goldCard == true)
//		return Aula->preco*0.85;
//	else
//		return Aula.preco;
//	}


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
