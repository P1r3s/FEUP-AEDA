#pragma once
#ifndef MENU_H_
#define MENU_H_

#include "Pessoa.h"
#include "Modos.h"
#include "CampoTenis.h"
#include "Funcoes.h"

#include <iostream>
#include <fstream>

/**
*  @brief Menu inicial
*/
void menuPrincipal();

/**
*  @brief Menu que permite ver as informacoes relativas aos campos, utentes e professores
*/
void menuInformacoes();

/**
*  @brief Menu que permite manipular(adicionar/remover) utentes e professores
*/
void menuAlteracoes();

/**
*  @brief Permite sair do programa
*/
void sair();

/**
*  @brief Menu que permite ver as informacoes relativas aos campos de tenis
*/
void menuInfoCampos();

/**
	*  @brief Menu que permite ver as informacoes relativas as aulas
*/
void menuInfoAulas();

/**
	*  @brief Menu que permite ver as informacoes relativas aos utentes
*/
void menuInfoUtentes();

/**
	*  @brief Imprime o titulo inicial
*/
void titulo();

/**
	*  @brief Guarda as informacoes dos ficheiros Aulas.txt,Livres.txt,Utentes.txt e Professores.txt
*/
void carregarFicheiros();

#endif