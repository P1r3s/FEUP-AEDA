#include "ServicoTecnico.h"

using namespace std;

string ServicoTecnico::getNomeTec() {
	return nomeTecnico;
}

int ServicoTecnico::getDisponibilidade() {
	return disponibilidade;
}

int ServicoTecnico::getNrReparacoes() {
	return nrReparacoes;
}


bool ServicoTecnico::operator <(const ServicoTecnico& o1) const {
	return disponibilidade > o1.disponibilidade;
}
