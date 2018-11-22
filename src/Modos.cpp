#include <string>

#include "Modos.h"

using namespace std;

//Funçoes independentes

/*
string addHour(string hora, int duracao)
{
	string novaHora;
	int x = hours(hora);
	int m = minutes(hora);
	switch (duracao)
	{
	case 30:
		m += duracao;
		if (m == 60)
		{
			x++;
			novaHora = to_string(x);
			novaHora = novaHora + ":00";
		}
		else if (m == 30)
		{
			novaHora = to_string(x);
			novaHora = novaHora + ":30";
		}
		break;
	case 60:
		x++;
		novaHora = to_string(x);
		novaHora = novaHora + ':' + to_string(m);
		break;
	case 90:
		x++;
		m += 30;
		if (m == 30)
		{
			novaHora = to_string(x);
			novaHora = novaHora + ":30";
		}
		else if (m == 60)
		{
			x++;
			novaHora = to_string(x);
			novaHora = novaHora + ":00";
		}
		break;
	case 120:
		x += 2;
		novaHora = to_string(x);
		novaHora = novaHora + ':' + to_string(m);
		break;
	}
	return novaHora;
}*/


///Classe Modos
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

///Classe Modo de Aula
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