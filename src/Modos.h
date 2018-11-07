#ifndef SRC_MODOS_H_
#define SRC_MODOS_H_

#include <string>

using namespace std;

class Modos {
	int campo;
	double preco;
public:
	Modos(int campo, double preco);
	virtual ~Modos() {};
	virtual double PrecoSessao() const;
};


class Aula : public Modos {
	int duracao;
	string horaI, horaF;
public:
	Aula(int campo, double preco, int duracao, string horaI, string horaF);
	virtual ~Aula() {};
	double PrecoSessao() const;

};

class Livre : public Modos {
	int duracao;
	string horaI, horaF;
public:
	Livre(int campo, double preco, int duracao, string horaI, string horaF);
	virtual ~Livre() {};
	double PrecoSessao() const;

};

#endif /* SRC_MODOS_H_ */
