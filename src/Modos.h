#ifndef SRC_MODOS_H_
#define SRC_MODOS_H_

#include <string>


using namespace std;

class Modos {
public:
	Modos(int dia, string horaInicio);
	virtual ~Modos() {};
	//virtual double PrecoSessao() const;
	int getDia();
	string getHoraI();
protected:
	int dia;
	string horaInicio;
};


class Aula : public Modos {
public:
	Aula(int dia, string sigla, string horaInicio);
	virtual ~Aula() {};
	double PrecoSessao() const;
private:
	string sigla;
	double preco;
};

class Livre : public Modos {
public:
	Livre(int dia, string horaInicio, int nrSlots);
	virtual ~Livre() {};
	double PrecoSessao() const;
private:
	int nrSlots;
	double preco;
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
