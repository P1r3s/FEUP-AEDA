#ifndef Pessoa_h_
#define Pessoa_h_

 // !Pessoa_h_


#include <string>
#include "Modos.h"



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
	//string getEntryHour();
	//string getOffHour();
	int getNrAulas();
	vector<Aula> getAulaVec();
	void aulasAdd(Aula a);
private:          
	vector<Aula> aulas;        //vector com as aulas que o professor tem de dar (TO DO: class aula)
	
};

class Utente : public Pessoa
{
public:
	Utente(string nome, int idade, bool goldCard);
	~Utente() {}
	bool getGoldCard();
	double getPrice() const;
	void aulasAdd(Aula a);
	void livresAdd(Livre l);
protected:
	bool goldCard;               //verifica se o utente tem cartao gold
	vector<Aula> aulasDoUtente;   // Vetor com as aulas do utente
	vector<Livre> livresDoUtente; // Vetor com os livres do utente
};

#endif