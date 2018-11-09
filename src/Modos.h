#ifndef SRC_MODOS_H_
#define SRC_MODOS_H_

#include <string>


using namespace std;

class Modos {
protected:
	//int campo;
	double preco=10;
	int nSlots;
	string nU;
	int data;
public:
	Modos(string nU, int nSlots,int data);
	virtual ~Modos() {};
	virtual double PrecoSessao() const;
};


class Aula : public Modos {
	int duracao;
	//string horaI, horaF;
	int indexAula;
	//string nU;
	//int data;
public:
	//Aula(int campo, int indexAula, double preco, int nSlots);
	Aula(string nU, int indexAula, int data, int nSlots);
	virtual ~Aula() {};
	double PrecoSessao() const;

};

class Livre : public Modos {
	int duracao;
	int horaI;
	//string nU;
	//int data;
	//string horaI, horaF;
	//int nSlots;
public:
	Livre(string nU, int nSlots,int horaI,int data);
	virtual ~Livre() {};
	double PrecoSessao() const;

};

class InvalidSlot
{
public:
	InvalidSlot(int nSlots) { this->nSlots = nSlots; }
	int getNslots() { return nSlots; }

private:
	int nSlots;
};


#endif /* SRC_MODOS_H_ */
