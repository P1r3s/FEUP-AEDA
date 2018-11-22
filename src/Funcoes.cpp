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

extern CampoTenis *c;

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

			c->addAula(d, horai);
			c->addAulaUtente(nomeU, d, horai);
			
		}
		else {
			getline(modos, horai, ',');
			getline(modos, nSlot, ',');
			getline(modos, data);

			int nrS = stoi(nSlot);
			int d = stoi(data);

			c->addLivre(d, horai, nrS);
			c->addLivreUtente(nomeU, d, horai,nrS);
		}
	}
}

void lerficheiroProfessores(CampoTenis *c) {
	ifstream file;
	string line;
	file.open("Professores.txt");

	while (getline(file, line)) {
		stringstream prof(line);

		string nomeProf, siglaProf, idadeProf;

		getline(prof, nomeProf, ',');
		getline(prof, siglaProf, ',');
		getline(prof, idadeProf);

		int idade = stoi(idadeProf);

		c->addProf(nomeProf, siglaProf, idade);

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

void adicionarUtente(string no, int idade, int gold) {
	bool g = false;
	if (gold == 1)
		g = true;

	c->addUtente(no, idade, g);

}

void adicionarProfessor(string nome, string sigla, int idade) {

	c->addProf(nome, sigla, idade);
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

int freqUtentes(string no) {
	vector<Utente> auxU = c->getUtentes();
	vector<Aula> auxA;
	vector<Livre> auxL;
	unsigned int i = 0;
	int f;

	while (i < auxU.size()) {
		if (auxU[i].getName() == no) {
			auxA = auxU[i].getAulasUtente();
			auxL = auxU[i].getLivresUtente();
			break;
		}
		i++;
	}

	f = auxA.size() + auxA.size();

	return  f;

}

vector<int> contasUtentes(string no) {
	vector <Utente> auxV = c->getUtentes();
	bool goldC;
	int age;
	int gC = 0;
	unsigned int i = 0;
	vector<int> v;

	while (i < auxV.size()) {
		if (auxV[i].getName() == no) {
			goldC = auxV[i].getGoldCard();
			age = auxV[i].getAge();
			break;
		}
		i++;
	}

	if (goldC)
		gC = 1;

	v.push_back(age);
	v.push_back(gC);
	return v;
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

void criarRelatorioprogresso(string no, vector<Aula> v) {
	//cria ficheiro .txt com o progresso do utente

	ofstream progresso;
	progresso.open(no + "_progresso.txt");

	if (v.size() < 3) {
		string p = "Ainda tem de praticar mais\n";
		progresso << p;
	}
	else if (v.size() < 6) {
		string p = "Tem melhorado bastante\n";
		progresso << p;
	}
	else {
		string p = "J� esta mais que apto\n";
		progresso << p;
	}

	progresso.close();

}

void criarDoc(string no) {
	//cria ficheiro .txt com as aulas/livres que frequentou (incluindo a data e horas e valor total)

	ofstream docFimMes;
	docFimMes.open(no + "_docFimMes.txt");

	vector<Utente> auxU = c->getUtentes();
	vector<Aula> auxA;
	vector<Livre> auxL;
	unsigned int i = 0;

	while (i < auxU.size()) {
		if (auxU[i].getName() == no) {
			auxL = auxU[i].getLivresUtente();
			auxA = auxU[i].getAulasUtente();
			break;
		}
		i++;
	}
	
	docFimMes << "AULAS\n";

	for (unsigned int i = 0; i < auxA.size(); i++) {
		docFimMes << "Dia: " << auxA.at(i).getDia() << ", Hora: " << auxA.at(i).getHoraI() << '\n';
	}
	
	docFimMes << "\nLIVRES\n";

	for (unsigned int i = 0; i < auxL.size(); i++) {
		docFimMes << "Dia: " << auxL.at(i).getDia() << ", Hora: " << auxL.at(i).getHoraI() << '\n';
	}

	cout << auxL.size();
	docFimMes.close();
	criarRelatorioprogresso(no, auxA);
}

