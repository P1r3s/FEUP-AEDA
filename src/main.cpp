//include libraries
#include <iostream>

//include headers
#include "CampoTenis.h"
#include "Modos.h"
#include "Pessoa.h"

using namespace std;

int main() {
	Utente Joao("Joao", 18, true);
	cout << Joao.getGoldCard();
	
	return 0;
}