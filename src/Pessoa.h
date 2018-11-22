#ifndef Pessoa_h_
#define Pessoa_h_

// !Pessoa_h_

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
//#include "CampoTenis.h"

using namespace std;

class Pessoa
{
public:
	Pessoa(string nome, int idade);
	~Pessoa() {}
	string getName();
	int getAge();
protected:
	string nome;
	int idade;
};

class Professor : public Pessoa
{
public:
	Professor(string nome, int idade);
	~Professor() {}
	int getNrAulas();
	vector<Aula> getAulaVec();
	void aulasAdd(Aula a);

protected:
	vector<Aula> aulasDoProfessor;        //vector com as aulas que o professor tem de dar (TO DO: class aula)

};

class Utente : public Pessoa
{
protected:
	bool goldCard;               //verifica se o utente tem cartao gold
	vector<Aula> aulasDoUtente;   // Vetor com as aulas do utente
	vector<Livre> livresDoUtente; // Vetor com os livres do utente
public:
	Utente(string nome, int idade, bool goldCard);
	~Utente() {}
	bool getGoldCard();
	double getPrecoLivres();
	double getPrecoAulas();
	double getPrecoCartao();
	double getPrecoTotal();
	void aulasAdd(Aula a);
	void livresAdd(Livre l);
	vector<Aula> getAulasUtente();
	vector<Livre> getLivresUtente();
};

#endif