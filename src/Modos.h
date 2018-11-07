#ifndef SRC_MODOS_H_
#define SRC_MODOS_H_

#include <string>

using namespace std;

class Modos {
	int campo;
	double preco;
	int nSlots;
public:
	Modos(int campo, double preco, int nSlots);
	virtual ~Modos() {};
	virtual double PrecoSessao() const;
};


class Aula : public Modos {
	int duracao;
	//string horaI, horaF;
	int indexAula;
public:
	Aula(int campo, int indexAula, double preco, int nSlots);
	virtual ~Aula() {};
	double PrecoSessao() const;

};

class Livre : public Modos {
	int duracao;
	//string horaI, horaF;
	int nSlots;
public:
	Livre(int campo, double preco, int nSlots);
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
