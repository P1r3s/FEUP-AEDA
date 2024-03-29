#pragma once

/**
*  @brief Le o ficheiro Aulas.txt e adiciona as aulas na base de dados
*
*@param campo de tenis
*/
void lerficheiroAulas(CampoTenis *c);

/**
*  @brief Le o ficheiro Livres.txt e adiciona os livres na base de dados
*
*@param campo de tenis
*/
void lerficheiroLivres(CampoTenis *c);

/**
*  @brief Le o ficheiro Professores.txt e adiciona os professores a base de dados 
*
*@param campo de tenis
*/
void lerficheiroProfessores(CampoTenis *c);

/**
*  @brief Le o ficheiro ExProfessores.txt e adiciona os antigos professores a base de dados
*
*@param campo de tenis
*/
void lerficheiroExProfessores(CampoTenis *c);

/**
*  @brief Le o ficheiro Utentes.txt e adiciona os utentes na base de dados
*
*@param campo de tenis
*/
void lerficheiroUtentes(CampoTenis *c);

/**
*  @brief Le o ficheiro ServicoTecnico.txt e adiciona os tecnicos a fila de prioridade
*
*@param campo de tenis
*/
void lerficheiroServicoT(CampoTenis *c);

/**
*  @brief Imprime as aulas do professor
*
*@param nome do professor
*/
void professorDasAulas(string nomeProf);

/**
*  @brief Retorna a frequencia de um dado utente passado como parametro
*
*@param nome do utente
*/
int freqUtentes(string no);

/**
*  @brief Retorna o vetor com a conta do utente de nome passado como parametro
*
*@param nome do utente
*/
Utente contasUtentes(string no);

/**
*  @brief Adiciona novo utente
*
*@param nome do utente
*@param idade do utente 
*@param utente ter cartao gold
*@param morada do utente
*@param nif do utente
*/
void adicionarUtente(string no,int idade,int gold, string morada, int nif);

/**
*  @brief Adiciona novo professor
*
*@param nome do professor
*@param sigla do professor
*@param idade do professor
*@param morada do professor
*@param nif do professor
*/
void adicionarProfessor(string nome, string sigla, int idade, string morada, int nif);

/**
*  @brief Cria ficheiro .txt com as aulas/livres que frequentou (incluindo data/horas e valor a pagar)
*
*@param nome do utente
*/
void criarDoc(string no);

/**
*  @brief Cria ficheiro .txt com o progresso do utente
*
*@param nome do utente 
*@param vetor das aulas do utente
*/
void criarRelatorioProgresso(string no, vector<Aula> v);

/**
*  @brief Adiciona novo tecnico
*
*@param nome do novo tecnico
*@param disponibilidade do novo tecnico
*@param numero de reparacoes do novo tecnico
*/
void adicionarTecnico(string nome, int disp, int nrRep);

/**
* @brief Faz update a BST de utentes
*
*@param campo de tenis
*/
void updateBST(CampoTenis *c);