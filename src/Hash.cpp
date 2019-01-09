#include "Hash.h"

using namespace std;

Hash::Hash(int b)
{
	this->BUCKET = b;
	lp = new list<Professor>[BUCKET];
}

void Hash::insertProf(Professor prof)
{
	int index = hashFunction(prof,prof.getName());		//indice do professor na tabela de dispersao de acordo com funcao hash
	lp[index].push_back(prof);		//adiciona professor ao vetor que esta no indice index
}

void Hash::insertExProf(Professor prof)
{
	lp[0].push_back(prof);		//insere antigo professor na posicao 0 da tabela de dispersao
}

void Hash::deleteProf(Professor prof)
{
	//indice do professor de acordo com a funcao hash
	int index = hashFunction(prof,prof.getName());

	//encontrar professor na lista que esta no indice index 
	list <Professor> ::iterator it;
	for (it = lp[index].begin(); it != lp[index].end(); it++) {
		if ((*it).getName() == prof.getName())
			break;
	}

	//se professor for encontrado, remove-lo
	if (it != lp[index].end())
		lp[index].erase(it);
}

Professor Hash::profMenosA() {
	list <Professor> ::iterator it;

	//encontra o primeiro professor atual que se encontra na tabela no menor indice a partir do indice 1(inclusive)
	for (int i = 1; i < BUCKET; i++) {
		if (!lp[i].empty()) {
			it = lp[i].begin();
			break;
		}
	}
	return (*it);
}

void Hash::adicionaAh(Aula a,Professor prof) {
	list <Professor> ::iterator it;
	int index = hashFunction(prof, prof.getName());

	//adiciona aula ao professor de indice index
	for (it = lp[index].begin(); it != lp[index].end(); it++) {
		if ((*it).getName() == prof.getName()) {
			Professor p = prof;
			deleteProf(prof);
			p.pushAula(a);
			insertProf(p);
			break;
		}

	}
}


bool Hash::existProf(string np) {
	list <Professor> ::iterator it;

	//verifica se o professor existe na tabela de dispersao
	for (int i = 0; i < BUCKET; i++) {
		for (it = lp[i].begin(); it != lp[i].end(); it++) {
			if ((*it).getName() == np)
				return true;
		}
	}

	return false;
}

int Hash::indexProf(string np) {
 
	list <Professor> ::iterator it;

	//encontra indice do professor
	for (int i = 0; i < BUCKET; i++) {
		for (it = lp[i].begin(); it != lp[i].end(); it++) {
			if ((*it).getName() == np)
				return i;
		}
	}

	return -1;
}


vector<Aula> Hash::aulasDoProf(string np) {
	list <Professor> ::iterator it;
	vector<Aula> aulasProf;

	for (int i = 0; i < BUCKET; i++) {
		for (it = lp[i].begin(); it != lp[i].end(); it++) {
			if ((*it).getName() == np) {
				aulasProf = (*it).getAulaVec();		//vetor de aulas do professor passado como parametro
			}
		}
	}

	return aulasProf;
}