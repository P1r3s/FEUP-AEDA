#pragma once


void lerficheiroModos(CampoTenis *c);
void lerficheiroProfessores(CampoTenis *c);
void lerficheiroUtentes(CampoTenis *c);
void criarFicheiros();
void professorDasAulas(string nomeProf);
int freqUtentes(string no);
vector<int> contasUtentes(string no);
void adicionarUtente(string no,int idade,int gold);
void adicionarProfessor(string nome, string sigla, int idade);
void horarioProfessores();
void criarDoc(string no);
void criarRelatorioProgresso(string no, vector<Aula> v);
