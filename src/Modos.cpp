#include "Modos.h"
#include <string>

using namespace std;

//Funçoes independentes
int hours(string horas)
{
	int i;
	i = horas.find_first_of(':');
	string h = horas.substr(0, i);
	return stoi(h);
}

int minutes(string horas)
{
	int i;
	i = horas.find_first_of(':');
	string m = horas.substr(i+1);
	return stoi(m);
}

/*string addHour(string hora, int duracao)
{
	int x = hours(hora);
	x++;
	string novaHora = to_string(x);
	int m = minutes(hora);
	m += duracao;
	string min;
	if(m == 60)
	{
		return novaHora + ":00";
	}
	min = to_string(m);
	return novaHora + ':' + min;
}*/

string addHour(string hora, int duracao)
{
	int x = hours(hora);
	int m = minutes(hora);
	if(duracao == 30)
	{
		m += duracao;
		if(m == 60)
		{
			x++;
			string novaHora = to_string(x);
			return novaHora + ":00";
		}
		else if(m == 30)
		{
			string novaHora = to_string(x);
			return novaHora + ":30";
		}
	}
	else if(duracao == 60)
	{
		x++;
		string novaHora = to_string(x);
		return novaHora + ':' + to_string(m);
	}
	else if(duracao == 90)
	{
		m += 30;
				if(m == 60)
				{
					x++;
					string novaHora = to_string(x);
					novaHora = novaHora + ":00";
				}
				else if(m == 30)
				{
					string novaHora = to_string(x);
					novaHora = novaHora + ":30";
				}
	}
}

string changeHour(string hora, int duracao)
{
	switch(duracao)
	{
	case 30:
		if(minutes(hora)+30 == 60)
		{
			addHour(hora, 30);
		}
		break;
	case 60:
		break;
	case 90:
		break;
	case 120:
		break;
	}
}
////

//Classe Modos
Modos::Modos(int campo, double preco) {
	// TODO Auto-generated constructor stub

	this->campo = campo;
	this->preco = preco;

}

//Classe Modo de Aula
Aula::Aula(int campo, double preco, string horaI, string horaF): Modos(campo, preco)
{
	this->duracao=60;
	this->horaI = horaI;
	this->preco = preco;
	horaF = addHour(horaI, 0);

}

double Aula::PrecoSessao() const {

	return preco;
}

//Classe Modo Livre
Livre::Livre(int campo, double preco, int duracao, string horaI, string horaF): Modos(campo, preco)
{
	this->duracao = duracao;
	this->horaI = horaI;
	this->preco = preco;
}

double Livre::PrecoSessao() const {
	return (duracao/30)*preco;
}

