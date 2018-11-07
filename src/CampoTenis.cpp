#include <iostream>
#include <string>
#include <vector>


#include "Pessoa.h"
#include "CampoTenis.h"

using namespace std;

CampoTenis::CampoTenis(int nCampos, string horaA, string horaE, int lotacao)
{
	this->nCampos = nCampos;
	horaAbertura = horaA;
	horaEncerramento = horaE;
	this->lotacao = lotacao;
}

string CampoTenis::getHoraAbertura()
{
	return horaAbertura;
}

string CampoTenis::getHoraEncerramento()
{
	return horaEncerramento;
}

//vector<Pessoa> CampoTenis::getProfessors()
//{
//	return professores;
//}

int CampoTenis::NumMaximoUtentes() const
{
	return lotacao;
}

void CampoTenis::addAula(Aula a)
{
	int minimo = professores[0].getAulaVec().size(), index = 0;
	for (size_t i = 1; i < professores.size(); i++)
	{
		if (professores[i].getAulaVec().size() < minimo)
		{
			minimo = professores[i].getAulaVec().size();
			index = i;
		}
	}

	professores[index].getAulaVec().push_back(a);

}