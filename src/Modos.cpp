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

////

//Classe Modos
Modos::Modos(string nU, int nSlots,int data) {
	// TODO Auto-generated constructor stub
	this->data = data;
	//this->campo = campo;
	//this->preco = preco;
	this->nSlots = nSlots;
	this->nU = nU;
}

double Modos::PrecoSessao() const {

	return preco;
}

//Classe Modo de Aula
Aula::Aula(string nU, int indexAula, int data, int nSlots) : Modos(nU, nSlots,data)
{
	//this->nU = nU;
	this->indexAula = indexAula;
	//this->data = data;
	//this->horaI = horaI;
	//horaF = addHour(horaI, 60);
	if (nSlots != 2)
	{
		InvalidSlot::InvalidSlot(nSlots);
	}
}

double Aula::PrecoSessao() const {

	return preco*2;
}

//Classe Modo Livre
Livre::Livre(string nU, int nSlots,int horaI,int data) : Modos(nU,nSlots,data)
{
	
	this->horaI = horaI;
	//horaF = addHour(horaI, duracao);
}

double Livre::PrecoSessao() const {
	//return (duracao / 30)*preco;
	return nSlots * preco;
}