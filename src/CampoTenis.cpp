
#include "CampoTenis.h"

using namespace std;

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


CampoTenis::CampoTenis()
{
	this->nCampos = 5;
	this->lotCampo = 4;
	this->horaAbertura = "9h00";
	this->horaEncerramento = "19h00";
	int horas = hours(horaEncerramento) - hours(horaAbertura);
	horas = horas * 60;
	int minutos = minutes(horaEncerramento) - minutes(horaAbertura);
	nSlots = (horas + minutos) / 30;

	
}

void CampoTenis::Calendar()
{
	Horario h;
	h.makeCalendar();
	campoHorario.push_back(h);
}

int CampoTenis::getNumCampos() {
	return nCampos;
}

int CampoTenis::getNumSlots() const {

	return nSlots;
}

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
	return lotCampo;
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

string CampoTenis::returnSigla() {
	unsigned int minimo = 999;
	int index = 0;
	for (unsigned int i = 0; i < getProfessors().size(); i++)
	{
		if (getProfessors()[i].getAulaVec().size() < minimo)
		{
			minimo = getProfessors()[i].getAulaVec().size();
			index = i;
		}
	}

	string sigla = getProfessors()[index].getSigla();
	return sigla;
}

bool CampoTenis::addAula(int dia, string horaInicio)
{
	
	if (insertHorario(dia, horaInicio, 2) == false)
	{
		return false;
	}

	string sigla = returnSigla();

	Aula a(dia, sigla, horaInicio);
	aulas.push_back(a);

	unsigned int minimo = 999;
	int index = 0;
	for (unsigned int i = 0; i < getProfessors().size(); i++)
	{
		if (getProfessors()[i].getAulaVec().size() < minimo)
		{
			minimo = getProfessors()[i].getAulaVec().size();
			index = i;
		}
	}

	professores[index].pushAula(a);

	return true;
}

void CampoTenis::addAulaUtente(string nome, int dia, string horai) {
	 
	string sigla = returnSigla();
	Aula a(dia, sigla, horai);

	for (unsigned int i = 0; i < getUtentes().size(); i++)
	{
		if (nome == getUtentes()[i].getName())
		{
			utentes[i].pushAula(a);
		}
	}

}

bool CampoTenis::addLivre(int dia, string horaInicio, int nrSlots)
{
	if (insertHorario(dia, horaInicio, nrSlots) == false)
	{
		return false;
	}

	Livre l(dia, horaInicio, nrSlots);
	livres.push_back(l);

	return true;
}

void CampoTenis::addLivreUtente(string nome, int dia, string horai, int nrSlots) {

	Livre l(dia,horai,nrSlots);

	for (unsigned int i = 0; i < getUtentes().size(); i++)
	{
		if (nome == getUtentes()[i].getName())
		{
			utentes[i].pushLivre(l);
		}
	}

}

void CampoTenis::addProf(string nome, string sigla, int idade)
{
	Professor prof(nome, sigla, idade);
	professores.push_back(prof);
}

void CampoTenis::removeUtente(string nome)
{
	vector<Aula> aulas;
	bool removal = false;

	for (size_t i = 0; i < utentes.size(); i++)
	{
		if (utentes[i].getName() == nome)
		{
			utentes.erase(utentes.begin() + i);
			removal = true;
			break;
		}
	}

	if (!removal)
		throw Exception::Exception(nome);

	ofstream file;
	file.open("Utentes.txt");
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
			break;
		}
	}

	if (!removal)
		throw Exception::Exception(nome);


	ofstream file;
	file.open("Professores.txt");
}

vector<Livre> CampoTenis::getLivres() {
	return livres;
}



void CampoTenis::displayHorario()
{
	vector<string> horas = { "09:00","09:30","10:00","10:30","11:00","11:30","12:00","12:30","13:00","13:30","14:00","14:30","15:00","15:30","16:00","16:30","17:00","17:30","18:30","19:00" };

		unsigned int month_size = campoHorario[0].getMonthVec().size();
		unsigned int slot_size = campoHorario[0].getDayVec().size();
		cout << endl;
		cout << "Horas Dia -->\n";
		cout << "  |\n";
		cout << "  V\n";

		cout << "            ";
		for (size_t i = 1; i < 32; i++)
		{
			cout << setw(4) << i;
		}
		cout << endl;
		for (unsigned int k = 1; k < month_size; k++)
		{
			cout << horas[k - 1] << "-" << horas[k] << " ";
			for (unsigned int j = 0; j < slot_size; j++)
			{
				cout << setw(4) << campoHorario[0].getMonthVec()[k - 1][j];
			}
			cout << endl;
		}
		cout << endl << endl;
	
}

bool CampoTenis::insertHorario(int dia, string horaI, int nrSlots)
{
	int indexSlot, tempHoraA, tempHoraI;
	tempHoraI = (hours(horaI) * 60) + minutes(horaI);
	tempHoraA = (hours(horaAbertura) * 60) + minutes(horaAbertura);
	indexSlot = (tempHoraI - tempHoraA) / 30;


	for (int i = 0; i < nrSlots; i++)
	{
		if ((campoHorario[0].getOcupation(dia, indexSlot) < 20) && (i = (nrSlots - 1)))
		{
			campoHorario[0].addOcupation(dia, indexSlot);
			return true;
		}
		if (campoHorario[0].getOcupation(dia, indexSlot) < 20)
		{
			campoHorario[0].addOcupation(dia, indexSlot);
		}
		
	}

	return false;
}
