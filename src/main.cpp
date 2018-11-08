//include libraries
#include <iostream>

//include headers
#include "CampoTenis.h"
#include "Modos.h"
#include "Pessoa.h"

using namespace std;

int main() {
	string nome = "Joao";
	Utente Joao(nome, 18, true);
	CampoTenis abctenis(1, "9:00", "18:00", 2);
	abctenis.addProf("Jose", 32);
	Aula fodasse(1, 3, 10, 2);
	abctenis.addAula(fodasse);
	cout << Joao.getGoldCard();
	bool thfy;
	for (size_t i = 0; i < nome.length(); i++)
	{

	}

	return 0;
}