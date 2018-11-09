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

void lerficheiroAulas() {
	ifstream file;
	string line;
	file.open("Aulas.txt");

	while (getline(file, line)) {
		stringstream aula(line);

		string nomeU, modo, hora, nrAula,nSlot, data;

		getline(aula, nomeU, ',');
		getline(aula, modo,',');

		if (modo == "Aula"||modo=="aula"||modo=="AULA") {
			getline(aula, nrAula, ',');
			getline(aula, nSlot, ',');
			getline(aula, data);

			int nrA = stoi(nrAula);
			int nrS = stoi(nSlot);
			int d = stoi(data);

			Aula a(nomeU, nrA, d, nrS);
		/*ADICIONAR AULA CRIADA AO VETOR AULAS*/
		//getAula.push_back(p);
		}
		else {
			getline(aula, hora, ',');
			getline(aula, nSlot, ',');
			getline(aula, data);

			int nrS = stoi(nSlot);
			int d = stoi(data);
			int h = stoi(hora);

			Livre l(nomeU, nrS, h, d);

		/*ADICIONAR LIVRE CRIADO AO VETOR LIVRES*/
		//getAula.push_back(p);
		}
	}
}

void lerficheiroProfessores() {
	ifstream file;
	string line;
	file.open("Professores.txt");
	
	while (getline(file, line)) {
		stringstream prof(line);

		string nomeProf, idadeProf;

		getline(prof, nomeProf, ',');
		getline(prof, idadeProf);

		int idade = stoi(idadeProf);
		//Professor p(nomeProf,idade);
		/*ADICIONAR O PROF CRIADO AO VETOR PROFESSORES*/
		CampoTenis c;
		c.addProf(nomeProf, idade);

	}
}

void lerficheiroUtentes() {
	ifstream file;
	string line;
	file.open("Utentes.txt");

	while (getline(file, line)) {
		stringstream uten(line);

		string nomeUten, idadeUten, card;
		

		getline(uten, nomeUten, ',');
		getline(uten, idadeUten,',');
		getline(uten, card);

		int idade = stoi(idadeUten);
		bool goldC = false;
		if (card == "Sim" || card == "sim" || card == "SIM") {
			goldC = true;
		}
		Utente u(nomeUten, idade, goldC);

		/*ADICIONAR O UTENTE CRIADO AO VETOR UTENTES*/
		//getUtentes.push_back(u);
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

}