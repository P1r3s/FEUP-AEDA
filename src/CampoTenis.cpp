#include <iostream>
#include <string>
#include <vector>


#include "CampoTenis.h"

using namespace std;

CampoTenis::CampoTenis(int nCampos, string horaA, string horaE, int lotacao)
{
	this->nCampos = nCampos;
	horaAbertura = horaA;
	horaEncerramento = horaE;
	lotacao_por_campo = lotacao;
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
	Professor prof (nome, idade);
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
		Exception::Exception(nome);
	}
	else
	{
		for (size_t i = 0; i < aulas.size(); i++)
		{
			addAula(aulas[i]);
		}
	}

}