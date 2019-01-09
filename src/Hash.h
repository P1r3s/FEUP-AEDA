#ifndef HASH_h_
#define HASH_h_

#pragma once

#include <list>
#include <iostream> 
#include "CampoTenis.h"

using namespace std;

/**
* Tabela de dispersao com os professores
*/
class Hash
{
	int BUCKET;    // Nr de buckets 
	list<Professor> *lp;		// pointer to an array containing buckets

public:
	/**
	*  @brief Construtor da tabela de dispersao
	*
	*@param Nr de buckets 
	*/
	Hash(int V);  

	/**
	*  @brief Insere professor atual na tabela de dispersao
	*
	*@param professor
	*/
	void insertProf(Professor prof);

	/**
	*  @brief Insere antigo professor na tabela de dispersao
	*
	*@param professor
	*/
	void insertExProf(Professor prof);

	/**
	*  @brief Apaga professor na tabela de dispersao
	*
	*@param professor
	*/
	void deleteProf(Professor prof);

	/**
	*  @brief funcao hash para mapear os professores na tabela de dispersao
	*
	*@param professor
	*@param nome do professor
	*/
	int hashFunction(Professor p, string nomeP) {
		return (p.getNrAulas(nomeP)+1);
	}

	/**
	*  @brief retorna professor com menos aulas
	*/
	Professor profMenosA();

	/**
	*  @brief adiciona aula ao professor da tabela de dispersao
	*
	*@param aula
	*@param professor
	*/
	void adicionaAh(Aula a,Professor prof);

	/**
	*  @brief verifica se professor existe na tabela de dispersao
	*
	*@param nome professor
	*/
	bool existProf(string np);

	/**
	*  @brief retorna posicao do professor na tabela de dispersao
	*
	*@param nome professor
	*/
	int indexProf(string np);

	/**
	*  @brief retorna aulas do professor
	*
	*@param nome professor
	*/
	vector<Aula> aulasDoProf(string np);

};

#endif