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
