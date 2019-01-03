#ifndef CampoTenis_h_
#define CampoTenis_h_

#pragma once

#include <fstream>
#include <iomanip>

#include "Modos.h"
#include "Pessoa.h"

using namespace std;

/**
 *  Representa o Campo de Tenis
 */
class CampoTenis
{
public:
	/**
	*  @brief Cria um Campo de Tenis com uma dada hora de abertura/encerramento e lotacao por campo
	*/
	CampoTenis();
	~CampoTenis() {}

	/**
	*  @brief Retorna a hora de abertura do campo de tenis
	*/
	string getHoraAbertura();

	/**
	*  @brief Retorna a hora de encerramento do campo de tenis
	*/
	string getHoraEncerramento();

	/**
	*  @brief Retorna a sigla do professor com menos aulas
	*/
	string returnSigla();

	/**
	*  @brief Retorna o vetor de professores
	*/
	vector<Professor> getProfessors();

	/**
	*  @brief Retorna o vetor de utentes
	*/
	vector<Utente> getUtentes();

	/**
	*  @brief Retorna o vetor de aulas
	*/
	vector<Aula> getAulas();

	/**
	*  @brief Retorna o vetor de livres
	*/
	vector<Livre> getLivres();

	/**
	*  @brief Retorna o numero de slots
	*/
	int getNumSlots() const;

	/**
	*  @brief Retorna o numero maximo de utentes por campo
	*/
	int NumMaximoUtentesPorCampo() const;

	/**
	*  @brief Retorna a lotacao total dos campos de tenis
	*/
	int getLotacao();

	/**
	*  @brief Retorna o numero de professores
	*/
	int getNumProfessores();

	/**
	*  @brief Retorna o numero de utentes
	*/
	int getNumUtentes();

	/**
	*  @brief Retorna o numero de campos de tenis
	*/
	int getNumCampos();

	/**
	*  @brief Adiciona aula ao professor com menos aulas
	*
	*@param dia da aula
	*@param hora de inicio da aula
	*/
	void addAula(int dia, string horaInicio);

	/**
	*  @brief Adiciona livre ao vetor de livres
	*
	*@param dia do livre
	*@param hora de inicio do livre
	*@param nr de slots do livre
	*/
	void addLivre(int dia, string horaInicio, int nrSlots);

	/**
	*  @brief Cria e adiciona o professor ao vetor de professores
	*
	*@param nome do professor
	*@param sigla do professor
	*@param idade do professor
	*/
	void addProf(string nome, string sigla, int idade);

	/**
	*  @brief Cria e adiciona o utente ao vetor de utentes
	*
	*@param nome do utente
	*@param idade do utente
	*@param goldCard true se utente tem cartao gold
	*/
	void addUtente(string nome, int idade, bool goldCard);

	/**
	*  @brief Remove utente do vetor de utentes e do ficheiro Utentes.txt
	*
	*@param nome do utente
	*/
	bool removeUtente(string ute);

	/**
	*  @brief Remove professor do vetor de professores e do ficheiro Professores.txt
	*
	*@param nome do professor
	*/
	bool removeProf(string prof);

	/**
	*  @brief Adiciona a aula ao utente
	*
	*@param nome do utente
	*@param dia da aula
	*@param hora de inicio da aula
	*/
	void addAulaUtente(string nome, int dia, string horai);

	/**
	*  @brief Adiciona o livre ao utente
	*
	*@param nome do utente
	*@param dia do livre
	*@param hora de inicio do livre 
	*@param numero de slots do livre
	*/
	void addLivreUtente(string nome, int dia, string horai, int nrSlots);

	/**
	*  @brief Atualiza o vetor de disponibilidade dos campos de tenis
	*/
	void atualizaVetorDisp();

	/**
	*  @brief Imprime o vetor de vetores com a disponibilidade dos campos
	*/
	void displayDispCampos();

	/**
	*  @brief Retorna o vetor de vetores com a disponibilidade dos campos
	*/
	vector<vector<int>> getDispCampos();

	/**
	*  @brief Converte as horas de string para inteiro
	*
	*@param horas 
	*/
	int hours(string horas);

	/**
	*  @brief Converte os minutos de string para inteiro
	*
	* @param minutos das horas
	*/
	int minutes(string horas);

	/**
	*@brief Verifica se o professor existe no vetor professores
	*
	*@param nome do professor
	*/
	bool verificaExProf(string nome);

	/**
	*@brief Verifica se o utente existe no vetor utentes
	*
	*@param nome do utente
	*/
	bool verificaExUten(string nome);


private:
	int nCampos;							 // numero de campos disponiveis pela empressa
	int lotCampo;							 // numero maximo de pessoas por campo numa mesma hora
	int nSlots;								 // numero de slots de meia hora disponiveis para marcação de um modo
	string horaAbertura;					 // horas a que os campos abrem
	string horaEncerramento;				 // horas a que os campos fecham

	vector<Professor> professores;            // Vector com todos os professores
	vector<Utente> utentes;                   // Vector com todos os utentes
	vector<Aula> aulas;						  // Vector com todas as aulas marcadas
	vector<Livre> livres;					  // Vector com todos os livres marcados

	vector<vector<int>>  dispCamposPorSlot;   //disponibilidade de campos por dia em cada slot

};

/**
 *  Excecao 
 */
class Exception
{
public:
	Exception(string nome) { this->nome = nome; }
	string getNome() { return nome; }

private:
	string nome;
};


#endif