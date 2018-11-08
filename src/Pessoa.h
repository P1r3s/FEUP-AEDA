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
private:
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
private:
	//string horario[2];           //horario[0] = horas a que o professor entra || horario[1] = horas a que o professor sai
	vector<Aula> aulas;        //vector com as aulas que o professor tem de dar (TO DO: class aula)
	//int nrAulas;
};

class Utente : public Pessoa
{
public:
	Utente(string nome, int idade, bool goldCard);
	~Utente() {}
	bool getGoldCard();
	double getPrice() const;
private:
	bool goldCard;               //verifica se o utente tem cartao gold
	vector<Aula> aulasDoUtente;
	vector<Livre> livresDoUtente;
};