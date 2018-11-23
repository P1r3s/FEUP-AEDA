#ifndef Pessoa_h_
#define Pessoa_h_

// !Pessoa_h_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include <algorithm>
#include <iomanip>

#include "Modos.h"


using namespace std;

class Pessoa
{
public:
	Pessoa(string nome, int idade);
	~Pessoa() {}
	virtual string getName();
	virtual int getAge();

protected:
	string nome;						 // Nome da pessoa
	int idade;							 // Idade da pessoa
};

class Professor : public Pessoa
{
public:
	Professor(string nome,  string sigla,int idade);
	~Professor() {}
	int getNrAulas(string nome);
	vector<Aula> getAulaVec();
	void aulasAdd(Aula a);
	string getName() { return nome; }
	int getAge() { return idade; }
	string getSigla() { return sigla; }
	void pushAula(Aula a);
	
protected:
	string sigla;						  // Iniciais do professor
	vector<Aula> aulasDoProfessor;        // Vector com as aulas que o professor tem de dar

};

class Utente : public Pessoa
{
protected:
	bool goldCard;						  // Verifica se o utente tem cartao gold
	vector<Aula> aulasDoUtente;			  // Vetor com as aulas do utente
	vector<Livre> livresDoUtente;		  // Vetor com os livres do utente
	
public:
	Utente(string nome, int idade, bool goldCard);
	~Utente() {}
	bool getGoldCard();
	string getName() { return nome; }
	int getAge() { return idade; }
	double getPrecoLivres();
	double getPrecoAulas();
	double getPrecoCartao();
	double getPrecoTotal();
	vector<Aula> getAulasUtente();
	vector<Livre> getLivresUtente();
	void pushAula(Aula a);
	void pushLivre(Livre l);
};

#endif