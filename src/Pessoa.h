#ifndef Pessoa_h_
#define Pessoa_h_

#include <iostream>
#include <vector>

#include "Modos.h"


using namespace std;

/**
 *  Representa uma pessoa
 */
class Pessoa
{
public:
	/**
	*  @brief Cria uma pessoa
	*
	*@param nome da pessoa 
	*@param idade da pessoa
	*/
	Pessoa(string nome, int idade);
	~Pessoa() {}

	/**
	*  @brief retorna nome da pessoa
	*/
	virtual string getName();

	/**
	*  @brief retorna idade da pessoa
	*/
	virtual int getAge();

protected:
	string nome;						 // Nome da pessoa
	int idade;							 // Idade da pessoa
};

/**
 *  Representa um professor
 */
class Professor : public Pessoa
{
public:
	/**
	*  @brief Cria um professor
	*
	*@param nome do professor
	*@param sigla do professor
	*@param idade do professor
	*/
	Professor(string nome,  string sigla,int idade);
	~Professor() {}

	/**
	*  @brief retorna numero de aulas do professor
	*
	*@param nome do professor
	*/
	int getNrAulas(string nome);

	/**
	*  @brief retorna o vetor de aulas do professor
	*/
	vector<Aula> getAulaVec();

	/**
	*  @brief retorna o nome do professor
	*/
	string getName() { return nome; }

	/**
	*  @brief retorna a idade do professor
	*/
	int getAge() { return idade; }

	/**
	*  @brief retorna a sigla do professor
	*/
	string getSigla() { return sigla; }

	/**
	*  @brief Adiciona aula ao vetor de aulas do professor
	*
	*@param aula
	*/
	void pushAula(Aula a);
	
	
protected:
	string sigla;						  // Iniciais do professor
	vector<Aula> aulasDoProfessor;        // Vector com as aulas que o professor tem de dar

};

/**
 *  Representa um utente
 */
class Utente : public Pessoa
{
protected:
	bool goldCard;						  // Verifica se o utente tem cartao gold
	vector<Aula> aulasDoUtente;			  // Vetor com as aulas do utente
	vector<Livre> livresDoUtente;		  // Vetor com os livres do utente
	
public:
	/**
	*  @brief Cria um utente
	*
	*@param nome do utente
	*@param idade do utente
	*@param se utente tem cartao gold
	*/
	Utente(string nome, int idade, bool goldCard);
	~Utente() {}

	/**
	*  @brief retorna true se tem cartao gold
	*/
	bool getGoldCard();

	/**
	*  @brief retorna o nome do utente
	*/
	string getName() { return nome; }

	/**
	*  @brief retorna a idade do utente
	*/
	int getAge() { return idade; }

	/**
	*  @brief retorna preco total dos livres
	*/
	double getPrecoLivres();

	/**
	*  @brief retorna preco total das aulas
	*/
	double getPrecoAulas();

	/**
	*  @brief retorna preco do cartao gold
	*/
	double getPrecoCartao();

	/**
	*  @brief retorna preco total de livres e aulas e com desconto do cartao gold caso o utente o tenha
	*/
	double getPrecoTotal();

	/**
	*  @brief retorna o vetor com as aulas do utente
	*/
	vector<Aula> getAulasUtente();

	/**
	*  @brief retorna o vetor com os livres do utente
	*/
	vector<Livre> getLivresUtente();

	/**
	*  @brief Adiciona aula ao vetor de aulas do utente
	*
	*@param aula
	*/
	void pushAula(Aula a);

	/**
	*  @brief Adiciona livres ao vetor de livres do utente
	*
	*@param aula
	*/
	void pushLivre(Livre l);
};

#endif