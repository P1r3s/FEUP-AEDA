#ifndef SRC_MODOS_H_
#define SRC_MODOS_H_

#include <string>


using namespace std;

class Modos {
public:
	Modos(int dia, string horaInicio);
	virtual ~Modos() {};
	virtual int getDia();
	virtual string getHoraI();
protected:
	int dia;							// Dia da marcacao
	string horaInicio;					// Hora da marcacao
};


class Aula : public Modos {
public:
	Aula(int dia, string sigla, string horaInicio);
	virtual ~Aula() {};
	double PrecoSessao() const;
	int getDia();
	string getHoraI();
private:
	string sigla;						// Iniciais do professor responsavel por dar a aula
	double preco;						// Preco por aula
};

class Livre : public Modos {
public:
	Livre(int dia, string horaInicio, int nrSlots);
	virtual ~Livre() {};
	double PrecoSessao() const;
	int getDia();
	string getHoraI();
private:
	int nrSlots;						// Numero de slots que o modo vai ocupar
	double preco;						// Preco por cada meia hora de modo livre
};

class InvalidSlot	//Exceção
{
public:
	InvalidSlot(int nSlots) { this->nSlots = nSlots; }
	int getNslots() { return nSlots; }

private:
	int nSlots;
};


#endif /* SRC_MODOS_H_ */
