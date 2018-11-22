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

void lerficheiroModos() {
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

			CampoTenis c;
			c.addAulaVec(d,horai);
		}
		else {
			getline(modos, horai, ',');
			getline(modos, nSlot, ',');
			getline(modos, data);

			int nrS = stoi(nSlot);
			int d = stoi(data);

			CampoTenis c;
			c.addLivre(d, horai, nrS);
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
		getline(uten, idadeUten, ',');
		getline(uten, card);

		int idade = stoi(idadeUten);
		bool goldC = false;
		if (card == "Sim" || card == "sim" || card == "SIM") {
			goldC = true;
		}

		CampoTenis c;
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

/*
int ocupacaoC(int i) {
	return campos[i];
}*/

/*int getNumC() {
	return getNumC();
}*/

void criarRelatorioProgresso(string no, vector<Aula> v) {
	//cria ficheiro .txt com o progresso do utente

	ofstream Progresso;
	Progresso.open(no + "_Progresso.txt");

	if (v.size() < 3) {
		string p = "Ainda tem de praticar mais\n";
		Progresso << p;
	}else if (v.size() < 6) {
		string p = "Tem melhorado bastante\n";
		Progresso << p;
	}else {
		string p = "Já esta mais que apto\n";
		Progresso << p;
	}

	Progresso.close();

}

void criarDoc(string no) {
	//cria ficheiro .txt com as aulas/livres que frequentou (incluindo a data e horas e valor total)

	ofstream DocFimMes;
	DocFimMes.open(no + "_DocFimMes.txt");
	//string my_string = "Oi qual o seu nome?\n";
	//file << my_string;

	CampoTenis c;
	vector<Utente> auxU = c.getUtentes();
	//int indexU;
	vector<Aula> auxA;
	vector<Livre> auxL;
	unsigned int i = 0;

	while (i < auxU.size()) {
		if (auxU[i].getName() == no) {
			auxA = auxU[i].getAulasUtente();
			auxL = auxU[i].getLivresUtente();
			break;
		}
		i++;
	}

	for (unsigned int i = 0; i < auxA.size(); i++) {
		DocFimMes << auxA.at(i).getDia();
		DocFimMes << auxA.at(i).getHoraI();
	}

	DocFimMes.close();
	criarRelatorioProgresso(no, auxA);
}

