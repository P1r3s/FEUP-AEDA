#include "CampoTenis.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <unistd.h>
#include <sstream>
#include <list>
#include <algorithm>
#include <iomanip>

/*
int nrCamp;
int lotCamp;

void criaCampo(int nrC, int lotC) {
	nrCamp = nrC;
	lotCamp = lotC;
	CampoTenis c(nrC, lotC);
}
*/

//vector<int> campos(nrCamp, 0);

void lerficheiroModos(CampoTenis *c) {
	ifstream file;
	string line;
	file.open("Modos.txt");

	while (getline(file, line)) {
		stringstream modos(line);

		string nomeU, modo, horai, nSlot, data;

		getline(modos, nomeU, ',');
		getline(modos, modo, ',');

		if (modo == "Aula" || modo == "aula" || modo == "AULA") {
			getline(modos, horai, ',');
			getline(modos, data);

			int d = stoi(data);

			c->addAulaVec(d,horai);
		}
		else {
			getline(modos, horai, ',');
			getline(modos, nSlot, ',');
			getline(modos, data);

			int nrS = stoi(nSlot);
			int d = stoi(data);

			c->addLivre(d, horai, nrS);
		}
	}
}

void lerficheiroProfessores(CampoTenis *c) {
	ifstream file;
	string line;
	file.open("Professores.txt");

	while (getline(file, line)) {
		stringstream prof(line);

		string nomeProf, idadeProf;

		getline(prof, nomeProf, ',');
		getline(prof, idadeProf);

		int idade = stoi(idadeProf);

		c->addProf(nomeProf, idade);

	}
}

void lerficheiroUtentes(CampoTenis *c) {
	ifstream file;
	string line;
	file.open("Utentes.txt");

	while (getline(file, line)) {
		stringstream uten(line);

		string nomeUten, idadeUten, card;


		getline(uten, nomeUten, ',');
		getline(uten, idadeUten, ',');
		getline(uten, card);

		int idade = stoi(idadeUten);
		bool goldC = false;
		if (card == "Sim" || card == "sim" || card == "SIM") {
			goldC = true;
		}

		c->addUtente(nomeUten, idade, goldC);
	}
}

void criarFicheiros() {

}

int ocupacaoCampos() {
	return 0;
}

void consultarHorario() {

}

void professorDasAulas() {

}

void freqUtentes() {

}

void contasUtentes() {

}

void horarioProfessores() {
	//mostra os dias e horas de aulas de cada professor
}

/*
int ocupacaoC(int i) {
	return campos[i];
}*/

/*int getNumC() {
	return getNumC();
}*/

void criarDoc(string no) {
	//cria ficheiro .txt com as aulas/livres que frequentou (incluindo a data e horas e valor total)
}

void criarRelatorioProgresso(string no) {
	//cria ficheiro .txt com o progresso do utente
}