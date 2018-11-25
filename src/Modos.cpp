#include <string>

#include "Modos.h"

using namespace std;

//Classe Modos
Modos::Modos(int dia, string horaInicio) {

	this->dia = dia;
	this->horaInicio = horaInicio;
}

int Modos::getDia() {
	return dia;
}


string Modos::getHoraI() {
	return horaInicio;
}

int Aula::getDia() {
	return dia;
}

string Aula::getHoraI() {
	return horaInicio;
}

string Aula::getSigla() {
	return sigla;
}

int Livre::getDia() {
	return dia;
}

string Livre::getHoraI() {
	return horaInicio;
}

int Livre::getNrSlots() {
	return nrSlots;
}

//Classe Modo de Aula
Aula::Aula(int dia, string sigla, string horaInicio) : Modos(dia, horaInicio)
{
	this->sigla = sigla;
	this->preco = 30;
}

double Aula::PrecoSessao() const {

	return preco;
}

//Classe Modo Livre
Livre::Livre(int dia, string horaInicio, int nrSlots) : Modos(dia, horaInicio)
{
	this->nrSlots = nrSlots;
	preco = 20;
}

double Livre::PrecoSessao() const {

	return nrSlots * preco;
}