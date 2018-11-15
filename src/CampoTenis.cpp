
#include "CampoTenis.h"

using namespace std;

CampoTenis::CampoTenis(int nCampos, int lotacao_por_campo)
{
	this->nCampos = nCampos;
	this->lotacao_por_campo = lotacao_por_campo;
}

int CampoTenis::getNumCampos() {
	return nCampos;
}

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
	string m = horas.substr(i + 1);
	return stoi(m);
}
/*
CampoTenis::CampoTenis(int nCampos, string horaA, string horaE, int lotacao)
{
	this->nCampos = nCampos;
	horaAbertura = horaA;
	horaEncerramento = horaE;
	lotacao_por_campo = lotacao;
	int horas = hours(horaE) - hours(horaA);
	horas = horas * 60;
	int minutos = minutes(horaE) - minutes(horaA);
	numeroSlots = (horas + minutos) / 30;

}*/

string CampoTenis::getHoraAbertura()
{
	return horaAbertura;
}

string CampoTenis::getHoraEncerramento()
{
	return horaEncerramento;
}

vector<Professor> CampoTenis::getProfessors()
{
	return professores;
}

vector<Utente> CampoTenis::getUtentes()
{
	return utentes;
}

vector<Horario> CampoTenis::getHorario()
{
	return campoHorario;
}

void CampoTenis::addUtente(string nome, int idade, bool goldCard) {
	Utente u(nome, idade, goldCard);
	utentes.push_back(u);
}

int CampoTenis::NumMaximoUtentesPorCampo() const
{
	return lotacao_por_campo;
}

int CampoTenis::getNumProfessores()
{
	return professores.size();
}

int CampoTenis::getNumUtentes()
{
	return utentes.size();
}

vector<Aula> CampoTenis::getAulas() {
	return aulas;
}

void CampoTenis::addAulaVec(string nU, int indexAula, int data, int nSlots) {
	Aula a(nU,indexAula,data,nSlots);
	aulas.push_back(a);
}


void CampoTenis::addAula(Aula a)
{
	unsigned int minimo = professores[0].getAulaVec().size(), index = 0;
	for (unsigned int i = 1; i < professores.size(); i++)
	{
		if (professores[i].getAulaVec().size() < minimo)
		{
			minimo = professores[i].getAulaVec().size();
			index = i;
		}
	}

	professores[index].getAulaVec().push_back(a);
	
}

void CampoTenis::addProf(string nome, int idade)
{
	Professor prof(nome, idade);
	//cout << nome << ", " << idade<<endl;
	professores.push_back(prof);
}

void CampoTenis::removeProf(string nome)
{
	vector<Aula> aulas;
	bool removal = false;

	for (size_t i = 0; i < professores.size(); i++)
	{
		if (professores[i].getName() == nome)
		{
			aulas = professores[i].getAulaVec();
			professores.erase(professores.begin() + i);
			removal = true;
		}
	}

	if (!removal)
	{
		throw Exception::Exception(nome);
	}
	else
	{
		for (size_t i = 0; i < aulas.size(); i++)
		{
			addAula(aulas[i]);
		}
	}

}

vector<Livre> CampoTenis::getLivres() {
	return livres;
}

void CampoTenis::addLivre(string nU, int nSlots, int horaI, int data) {
	Livre l(nU,nSlots,horaI,data);
	livres.push_back(l);
}

void CampoTenis::addCampo()
{
	vector<Horario> v;
	v = getHorario();
	for (int i = 0; i < getNumCampos(); i++)
	{
		v.push_back();
	}
}

void CampoTenis::displayHorario()
{
	

	for (unsigned int i = 0; i < campoHorario.size(); i++)
	{
		unsigned int month_size = campoHorario[i].getMonthVec().size();
		unsigned int slot_size = campoHorario[i].getSlotVec().size();

		cout << "Campo " << i << " :\n\n";
		for (unsigned int j = 0; j < slot_size; j++)
		{
			int resto = j % 5;
			switch (resto)
			{
			case 0:
				cout << setw(9) << "MONDAY";
				break;
			case 1:
				cout << setw(9) << "TUESDAY";
				break;
			case 2:
				cout << setw(9) << "WEDNSDAY";
				break;
			case 3:
				cout << setw(9) << "THUSDAY";
				break;
			case 4:
				cout << setw(9) << "FRIDAY";
				break;
			default:
				break;
			}
		}

		for (unsigned int k= 0; k < month_size; k++)
		{
			for (unsigned int j = 0; j < slot_size; j++)
			{
				cout << setw(9) << campoHorario[i].getMonthVec()[k][j];
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}
