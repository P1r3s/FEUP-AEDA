#include "CampoTenis.h"
#include "ServicoTecnico.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <sstream>
#include <list>
#include <algorithm>
#include <iomanip>

extern CampoTenis *c;
extern Hash *h;

void lerficheiroAulas(CampoTenis *c) {
	ifstream file;
	string line;
	file.open("Aulas.txt");

	while (getline(file, line)) {
		bool bol = true;
		stringstream aula(line);

		string nomeU, modo, horai, nSlot, data;

		getline(aula, nomeU, ',');			//guarda nome do utente
		getline(aula, modo, ',');

		if (modo == "Aula" || modo == "aula" || modo == "AULA") {		//verifica se � modo aula
			getline(aula, horai, ',');			//guarda hora em string
			getline(aula, data, '\n');			//guarda data em string

			int d = stoi(data);				//converte data para inteiro
			int hAux = c->hours(horai);			//converte hora para inteiro
			int minAux = c->minutes(horai);		//converte minutos para inteiro

			if (hAux < 9 || hAux>18) {				//erro caso hora seja invalida
				cout << endl;
				cout << "Erro: " << endl;
				cout << "A aula de " << nomeU << " de dia " << data << " as " << horai << "h tem uma hora invalida!" << endl;
				cout << "Certifique se que a hora de incio esta compreendida entre 9h e 18h." << endl;
				cout << "Esta aula nao foi adicionada!" << endl;
				bol = false;
			}

			if (d > 31 || d < 1) {			//erro se dia invalido
				cout << endl;
				cout << "Erro: " << endl;
				cout << "A aula de " << nomeU << " de dia " << data << " as " << horai << "h tem um dia invalido!" << endl;
				cout << "Verifique que o dia esta compreendido entre 1 e 31 (inclusive)." << endl;
				cout << "Esta aula nao foi adicionada!" << endl;
				bol = false;
			}

			//se nao ocorrer nenhum erro, adiciona a aula aos vetores 

			if (bol) {
				c->addAula(d, horai);
				c->addAulaUtente(nomeU, d, horai);
			}
		}
	}
}

void lerficheiroLivres(CampoTenis *c) {
	ifstream file;
	string line;
	file.open("Livres.txt");

	while (getline(file, line)) {
		bool bol = true;
		stringstream livre(line);

		string nomeU, modo, horai, nSlot, data;

		getline(livre, nomeU, ',');			//guarda nome
		getline(livre, modo, ',');

		if (modo == "Livre" || modo == "livre" || modo == "LIVRE") {
			getline(livre, horai, ',');			//guarda hora em string
			getline(livre, nSlot, ',');			//guarda nr de slots em string
			getline(livre, data, '\n');			//guarda a data em string

			int nrS = stoi(nSlot);		//converte nr de slots em inteiro
			int d = stoi(data);			//converte data em inteiro

			if (nrS > 4 || nrS < 1) {					//erro caso nr de slots invalido
				cout << endl;
				cout << "Erro: " << endl;
				cout << "O livre de " << nomeU << " de dia " << data << " as " << horai << "h tem um numero invalido de slots!" << endl;
				cout << "Certifique-se que o numero de slots esta compreendido entre 0 e 4 (inclusive)" << endl;
				cout << "Este livre nao foi adicionado!" << endl;
				bol = false;
			}

			vector<vector<int>> dispAux = c->getDispCampos();			//vetor de disponibilidade dos campos
			int nrSubtr = 0;							//nr a subtrair a hora para obter indice do slot
			int hAux = c->hours(horai);
			int minAux = c->minutes(horai);
			int nrSlot;


			if (hAux < 9 || hAux>18) {		//erro caso hora nao seja entre a hora de abertura e encerramento 
				cout << endl;
				cout << "Erro: " << endl;
				cout << "O livre de " << nomeU << " de dia " << data << " as " << horai << "h tem uma hora invalida!" << endl;
				cout << "Certifique se que a hora de incio esta compreendida entre 9h e 18h30." << endl;
				cout << "Este livre nao foi adicionado!" << endl;
				bol = false;
			}

			if (hAux + nrS > 19) {			//erro caso a hora mais o nr de slots exceda a hora de encerramento
				cout << endl;
				cout << "Erro: " << endl;
				cout << "O livre de " << nomeU << " de dia " << data << " as " << horai << "h tem um numero de slots que excede a hora de encerramento!" << endl;
				cout << "Verifique a disponibilidade dos campos! " << endl;
				cout << "Este livre nao foi adicionado!" << endl;
				bol = false;
			}

			if (d > 31 || d < 1) {			//erro caso dia invalido
				cout << endl;
				cout << "Erro: " << endl;
				cout << "O livre de " << nomeU << " de dia " << data << " as " << horai << "h tem um dia invalido!" << endl;
				cout << "Verifique que o dia esta compreendido entre 1 e 31 (inclusive)." << endl;
				cout << "Este livre nao foi adicionado!" << endl;
				bol = false;
			}


			//descobrir qual e o nr a subtrair a hora de inicio de modo a obter o nr do slot

			if (hAux == 9)
				nrSubtr = 9;

			if (hAux == 10)
				nrSubtr = 8;

			if (hAux == 11)
				nrSubtr = 7;

			if (hAux == 12)
				nrSubtr = 6;

			if (hAux == 13)
				nrSubtr = 5;

			if (hAux == 14)
				nrSubtr = 4;

			if (hAux == 15)
				nrSubtr = 3;

			if (hAux == 16)
				nrSubtr = 2;

			if (hAux == 17)
				nrSubtr = 1;

			if (hAux == 18)
				nrSubtr = 0;


			if (minAux == 30) {						//se min for 30 entao � o slot seguinte 
				nrSlot = hAux - nrSubtr + 1;
			}
			else
				nrSlot = hAux - nrSubtr;

			//se nao ocorrer nenhum erro entao adiciona o livre aos vetores 
			if (bol) {
				c->addLivre(d, horai, nrS);
				c->addLivreUtente(nomeU, d, horai, nrS);
			}
		}
	}
}

void lerficheiroProfessores(CampoTenis *c) {
	ifstream file;
	string line;
	file.open("Professores.txt");

	while (getline(file, line)) {
		stringstream prof(line);

		string nomeProf, siglaProf, idadeProf, moradaProf, nifProf;

		getline(prof, nomeProf, ',');		//guarda nome
		getline(prof, siglaProf, ',');		//guarda sigla
		getline(prof, idadeProf, ',');			//guarda idade em string
		getline(prof, moradaProf, ',');			//guarda morada
		getline(prof, nifProf);				//guarda nif em string

		int idade = stoi(idadeProf);		//converte idade para inteiro
		int nif = stoi(nifProf);			//converte nif para inteiro

		c->addProf(nomeProf, siglaProf, idade, moradaProf, nif);		//adiciona professor
		c->insertHash(nomeProf, siglaProf, idade, moradaProf, nif);
	}
}

void lerficheiroExProfessores(CampoTenis *c) {
	ifstream file;
	string line;
	file.open("ExProfessores.txt");

	while (getline(file, line)) {
		stringstream prof(line);

		string nomeProf, siglaProf, idadeProf, moradaProf, nifProf;

		getline(prof, nomeProf, ',');		//guarda nome
		getline(prof, siglaProf, ',');		//guarda sigla
		getline(prof, idadeProf, ',');			//guarda idade em string
		getline(prof, moradaProf, ',');			//guarda morada
		getline(prof, nifProf);				//guarda nif em string

		int idade = stoi(idadeProf);		//converte idade para inteiro
		int nif = stoi(nifProf);			//converte nif para inteiro

		c->addExProf(nomeProf, siglaProf, idade, moradaProf, nif);		//adiciona professor
		c->insertExHash(nomeProf, siglaProf, idade, moradaProf, nif);
	}
}

void lerficheiroUtentes(CampoTenis *c) {
	ifstream file;
	string line;
	file.open("Utentes.txt");

	while (getline(file, line)) {
		stringstream uten(line);

		string nomeUten, idadeUten, card, moradaUten, nifUten;


		getline(uten, nomeUten, ',');		//guarda nome
		getline(uten, idadeUten, ',');		//guarda idade em string
		getline(uten, card, ',');			//guarda se tem ou nao cartao dourado
		getline(uten, moradaUten, ',');		//guarda morada
		getline(uten, nifUten);				//guarda nif em string

		int idade = stoi(idadeUten);	//converte idade para inteiro
		int nif = stoi(nifUten);		//converte nif para inteiro

										//verifica se tem cartao dourado
		bool goldC = false;
		if (card == "Sim" || card == "sim" || card == "SIM") {
			goldC = true;
		}

		//adiciona utente
		c->addUtente(nomeUten, idade, goldC, moradaUten, nif);

	}
}

void lerficheiroServicoT(CampoTenis *c) {
	ifstream file;
	string line;
	file.open("ServicoTecnico.txt");

	while (getline(file, line)) {
		stringstream serv(line);

		string nomeTec, disp, nrRep;

		getline(serv, nomeTec, ',');		//guarda nome
		getline(serv, disp, ',');			//guarda disponibilidade
		getline(serv, nrRep);				//guarda nr de reparacoes

		int disponibilidade = stoi(disp);		//converte disponibilidade para inteiro
		int nrR = stoi(nrRep);			//converte nr de reparacoes para inteiro

		c->addTecnico(nomeTec, disponibilidade, nrR);		//adiciona tecnico
	}
	//c->ordenaTecnicos();
}

void adicionarUtente(string no, int idade, int gold, string morada, int nf) {
	//adicionar novo utente
	bool g = false;
	if (gold == 1)
		g = true;

	c->addUtente(no, idade, g, morada, nf);

	Utente u(no, idade, g, morada, nf);
	c->insertBST(u);

	ofstream ute;
	ute.open("Utentes.txt", std::fstream::out | std::fstream::app);
	string card = "nao";
	if (g) {
		card = "sim";
	}

	//escreve utente para o ficheiro Utentes.txt ja existente
	ute << endl << no << ',' << idade << ',' << card << ',' << morada << ',' << nf;

	ute.close();
}

void adicionarProfessor(string nome, string sigla, int idade, string morada, int nif) {
	//adicionar novo professor

	c->addProf(nome, sigla, idade, morada, nif);
	Professor p(nome, sigla, idade, morada, nif);
	h->insertProf(p);

	ofstream prof;
	prof.open("Professores.txt", std::fstream::out | std::fstream::app);

	//escreve professor para o ficheiro Professores.txt ja existente
	prof << endl << nome << ',' << sigla << ',' << idade << ',' << morada << ',' << nif;

	prof.close();

}

void professorDasAulas(string nomeProf) {
	//aulas de um determinado professor da tabela de dispersao
	vector<Aula> vAulasProf = h->aulasDoProf(nomeProf);
	
	//ordena o vetor das aulas do professor por ordem crescente de dia da aula

	for (unsigned int i = 0; i < vAulasProf.size(); i++)
	{
		for (unsigned int j = 0; j < vAulasProf.size(); j++)
		{
			if (vAulasProf[i].getDia() < vAulasProf[j].getDia())
			{
				Aula aux(vAulasProf[i].getDia(), vAulasProf[i].getSigla(), vAulasProf[i].getHoraI());

				vAulasProf[i] = vAulasProf[j];
				vAulasProf[j] = aux;
			}
		}
	}

	if (h->indexProf(nomeProf) == 0) {		//se o indice do professor na tabela de dispersao for 0 entao e um professor antigo
		cout << "O professor ja nao trabalha no Campo de Tenis" << endl << endl;
	}
	else {
		cout << "Aulas do professor: " << endl << endl;
		for (unsigned int j = 0; j < vAulasProf.size(); j++) {
			cout << "Tem aula dia " << vAulasProf[j].getDia() << " as " << vAulasProf[j].getHoraI() << "h." << endl;
		}
		cout << endl;
		cout << "Numero de aulas no mes: " << vAulasProf.size() << endl << endl;
	}
}

int freqUtentes(string no) {
	//retorna a frequencia de um dado utente passado como parametro
	BST<Utente> auxU = c->getUtentes();
	vector<Aula> auxA;
	vector<Livre> auxL;

	BSTItrIn<Utente> it(auxU);
	Utente u = it.retrieve();
	 
	while (!it.isAtEnd()) {
		u = it.retrieve();
		if (u.getName() == no) {		//ate encontrar o utente no vetor utentes
			auxL = u.getLivresUtente();
			auxA = u.getAulasUtente();
			break;
		}
		it.advance();
	}

	int f = auxA.size() + auxL.size();		//soma das aulas e livres do utente

	return  f;
}

Utente contasUtentes(string no) {
	//retorna o vetor com a conta do utente de nome passado como parametro
	BST<Utente> auxV = c->getUtentes();
	bool goldC;
	int age;
	int gC = 0;
	unsigned int i = 0;
	vector<int> v;
	string morada;
	int nif;

	BSTItrIn<Utente> it(auxV);
	Utente u = it.retrieve();

	//procura no vetor utentes o utente de nome "nome"
	while (!it.isAtEnd()) {
		u = it.retrieve();
		if (u.getName() == no) {
			goldC = u.getGoldCard();
			age = u.getAge();
			morada = u.getMorada();
			nif = u.getNif();
			break;
		}
		it.advance();
	}

	if (goldC)
		gC = 1;
	
	Utente utent(no, age, goldC, morada, nif);

	return utent;
}


void criarRelatorioProgresso(string no, vector<Aula> v) {
	//cria ficheiro .txt com o progresso do utente

	ofstream progresso;
	progresso.open(no + "_progresso.txt");

	if (v.size() < 3) {
		string p = "Como ainda esta no inicio, visto ter frequentado poucas aulas, o seu progresso ainda nao e notorio. \nNo entanto, certamente que havendo uma maior frequencia nos campos de tenis, evoluira rapidamente.";
		progresso << p;
	}
	else if (v.size() < 6) {
		string p = "O seu progresso tem sido bastante notorio, pelo que agora � continuar a praticar.";
		progresso << p;
	}
	else {
		string p = "A evolucao foi rapida e esta mais que apto a jogar tenis.";
		progresso << p;
	}

	progresso.close();

}

void criarDoc(string no) {
	//cria ficheiro .txt com as aulas/livres que frequentou (incluindo data/horas e valor a pagar)

	ofstream docFimMes;
	docFimMes.open(no + "_docFimMes.txt");

	BST<Utente> auxU = c->getUtentes();
	vector<Aula> auxA;
	vector<Livre> auxL;


	BSTItrIn<Utente> it(auxU);
	Utente u = it.retrieve();

	while (!it.isAtEnd()) {
		u = it.retrieve();
		if (u.getName() == no) {
			auxL = u.getLivresUtente();
			auxA = u.getAulasUtente();
			break;
		}
		it.advance();
	}

	docFimMes << "AULAS\n";

	for (unsigned int i = 0; i < auxA.size(); i++) {
		docFimMes << "Dia: " << auxA.at(i).getDia() << ", Hora: " << auxA.at(i).getHoraI() << "h" << '\n';
	}

	docFimMes << "\nLIVRES\n";

	for (unsigned int i = 0; i < auxL.size(); i++) {
		docFimMes << "Dia: " << auxL.at(i).getDia() << ", Hora: " << auxL.at(i).getHoraI() << "h" << endl << endl;
	}

	docFimMes << endl << endl;
	docFimMes << "CONTAS DO MES" << endl;
	if (u.getGoldCard()) {
		docFimMes << "\nMensalidade do Cartao Dourado: " << u.getPrecoCartao() << " euros" << endl;
	}

	docFimMes << "\nTotal a pagar pelas aulas: " << u.getPrecoAulas() << " euros" << endl;
	docFimMes << "\nTotal a pagar pelos livres: " << u.getPrecoLivres() << " euros" << endl << endl;
	docFimMes << "\nTotal a pagar: " << u.getPrecoTotal() << " euros" << endl;

	docFimMes.close();
	criarRelatorioProgresso(no, auxA);
}


void adicionarTecnico(string nome, int disp, int nrRep) {
	//adicionar novo tecnico

	c->addTec(nome, disp, nrRep);
}

void updateBST(CampoTenis *c)
{
	vector<Utente> uT = c->getUtenTemp();

	for (unsigned int i = 0; i < uT.size(); i++)
	{
		Utente u = uT[i];
		c->insertBST(u);
	}
}