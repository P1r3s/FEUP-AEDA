#ifndef EXCECOES_H_
#define EXCECOES_H_

#include <iostream>
#include <exception>
#include <string>

using namespace std;

/**
* Excecao
*/
class UtenteNaoExiste : public exception {
	string nome;				//nome do utente
public:
	/**
	*  @brief Cria excecao utente nao existe
	*
	*@param nome do utente
	*/
	UtenteNaoExiste(string Str) : nome(Str) {}
	virtual ~UtenteNaoExiste() throw() {}

	/**
	*  @brief output da excecao
	*/
	virtual const char *what() const throw() {
		cout << endl;
		cout << "O utente " << nome << " nao existe." << endl << endl;

		return "";
	}
};

/**
* Excecao
*/
class ProfNaoExiste : public exception {
	string nome;				//nome do professor
public:
	/**
	*  @brief Cria excecao professor nao existe
	*
	*@param nome do professor
	*/
	ProfNaoExiste(string Str) : nome(Str) {}
	virtual ~ProfNaoExiste() throw() {}

	/**
	*  @brief output da excecao
	*/
	virtual const char *what() const throw() {
		cout << endl;
		cout << "O professor " << nome << " nao existe." << endl << endl;

		return "";
	}
};

/**
* Excecao
*/
class TecnicoNaoExiste : public exception {
	string nome;			//nome do tecnico
public:
	/**
	*  @brief Cria excecao tecnico nao existe
	*
	*@param nome do tecnico
	*/
	TecnicoNaoExiste(string Str) : nome(Str) {}
	virtual ~TecnicoNaoExiste() throw() {}

	/**
	*  @brief output da excecao
	*/
	virtual const char *what() const throw() {
		cout << endl;
		cout << "O tecnico " << nome << " nao existe." << endl << endl;

		return "";
	}
};

#endif
