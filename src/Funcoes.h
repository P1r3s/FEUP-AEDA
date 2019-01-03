#pragma once

/**
*  @brief Le o ficheiro Aulas.txt e adiciona as aulas aos respetivos vetores
*
*@param campo de tenis
*/
void lerficheiroAulas(CampoTenis *c);

/**
*  @brief Le o ficheiro Livres.txt e adiciona os livres aos respetivos vetores
*
*@param campo de tenis
*/
void lerficheiroLivres(CampoTenis *c);

/**
*  @brief Le o ficheiro Professores.txt e adiciona os professores aos respetivos vetores
*
*@param campo de tenis
*/
void lerficheiroProfessores(CampoTenis *c);

/**
*  @brief Le o ficheiro Utentes.txt e adiciona os utentes aos respetivos vetores
*
*@param campo de tenis
*/
void lerficheiroUtentes(CampoTenis *c);

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
vector<int> contasUtentes(string no);

/**
*  @brief Adiciona novo utente
*
*@param nome do utente
*@param idade do utente 
*@param utente ter cartao gold
*/
void adicionarUtente(string no,int idade,int gold);

/**
*  @brief Adiciona novo professor
*
*@param nome do professor
*@param sigla do professor
*@param idade do professor
*/
void adicionarProfessor(string nome, string sigla, int idade);

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
