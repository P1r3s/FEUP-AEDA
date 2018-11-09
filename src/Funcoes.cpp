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

int nrCamp;
int lotCamp;

void criaCampo(int nrC, int lotC) {
	nrCamp = nrC;
	lotCamp = lotC;
	CampoTenis c(nrC, lotC);
}

vector<int> campos(nrCamp, 0);

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

			CampoTenis c(nrCamp,lotCamp);
			c.addAulaVec(nomeU, nrA, d, nrS);
		}
		else {
			getline(aula, hora, ',');
			getline(aula, nSlot, ',');
			getline(aula, data);

			int nrS = stoi(nSlot);
			int d = stoi(data);
			int h = stoi(hora);

			CampoTenis c(nrCamp, lotCamp);
			c.addLivre(nomeU, nrS, h, d);
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
	
		CampoTenis c(nrCamp, lotCamp);
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
		
		CampoTenis c(nrCamp, lotCamp);
		c.addUtente(nomeUten, idade, goldC);
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


int ocupacaoC(int i) {
	return campos[i];
}

/*int getNumC() {
	return getNumC();
}*/

void criarDoc(string no) {
	//cria ficheiro .txt com as aulas/livres que frequentou (incluindo a data e horas e valor total)
}

void criarRelatorioProgresso(string no) {
	//cria ficheiro .txt com o progresso do utente
}