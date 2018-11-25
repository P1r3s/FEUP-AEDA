#ifndef SRC_MODOS_H_
#define SRC_MODOS_H_

#include <string>

using namespace std;

/**
 *  Representa os Modos possiveis
 */
class Modos {
public:
	/**
	*  @brief Cria modo
	*
	*@param dia do modo
	*@param hora de inicio do modo
	*/
	Modos(int dia, string horaInicio);
	virtual ~Modos() {};

	/**
	*  @brief retorna o dia do modo
	*/
	virtual int getDia();

	/**
	*  @brief retorna a hora do modo
	*/
	virtual string getHoraI();
protected:
	int dia;							// Dia da marcacao
	string horaInicio;					// Hora da marcacao
};

/**
 *  Representa uma aula
 */
class Aula : public Modos {
public:
	/**
	*  @brief Cria aula
	*
	*
	*@param dia da aula
	*@param sigla do professor
	*@param hora de inicio da aula 
	*/
	Aula(int dia, string sigla, string horaInicio);
	virtual ~Aula() {};

	/**
	*  @brief Retorna o preco da aula
	*/
	double PrecoSessao() const;

	/**
	*  @brief retorna o dia da aula
	*/
	int getDia();

	/**
	*  @brief retorna a hora de inicio da aula
	*/
	string getHoraI();

	/**
	*  @brief retorna a sigla do professor dessa aula
	*/
	string getSigla();
private:
	string sigla;						// Iniciais do professor responsavel por dar a aula
	double preco;						// Preco por aula
};

/**
 *  Representa um livre
 */
class Livre : public Modos {
public:
	/**
	*  @brief Cria livre
	*
	*
	*@param dia do livre
	*@param hora de inicio do livre 
	*@param numero de slots do livre
	*/
	Livre(int dia, string horaInicio, int nrSlots);
	virtual ~Livre() {};

	/**
	*  @brief retorna o preco do livre
	*/
	double PrecoSessao() const;

	/**
	*  @brief retorna o dia do livre
	*/
	int getDia();

	/**
	*  @brief retorna a hora de inicio do livre
	*/
	string getHoraI();

	/**
	*  @brief retorna o numero de slots do livre
	*/
	int getNrSlots();
private:
	int nrSlots;						// Numero de slots que o modo vai ocupar(slots sao de 30 min)
	double preco;						// Preco por cada meia hora de modo livre
};

/**
 *  Excecao para invalid slots
 */
class InvalidSlot	//Exceção
{
public:
	InvalidSlot(int nSlots) { this->nSlots = nSlots; }
	int getNslots() { return nSlots; }

private:
	int nSlots;
};


#endif /* SRC_MODOS_H_ */
