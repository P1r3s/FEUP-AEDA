#include "Menu.h"

using namespace std;

void Menu() {
	cout << "--------------------------------------------- " << endl;
	cout << "                CAMPOS DE TENIS               " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Carregar ficheiros existentes" << endl;
	cout << " 2 - Criar novos ficheiros" << endl;
	cout << " 3 - Sair" << endl;
	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";

	while (opcao < 1 || opcao > 3) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				lerficheiroAulas();
				lerficheiroProfessores();
				lerficheiroUtentes();

				cout << "Ficheiros carregados!" << endl;
				Menu1();
				break;
			case 2:
				criarFicheiros();
				cout << "Ficheiros criados!" << endl;
				Menu1();
				break;
			case 3:
				Sair();
				break;
			default:
				cout << "Opcao invalida! Introduza uma opcao: ";
			}
		}

		else {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Opcao invalida! Introduza nova opcao: ";
		}
	}
}

void Menu1() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "                CAMPOS DE TENIS               " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Informacao relativa aos Campos de Tenis" << endl;
	cout << " 2 - Informacao relativa as Aulas" << endl;
	cout << " 3 - Informacao relativa aos Utentes" << endl;
	cout << " 4 - Informacao relativa aos Professores" << endl;
	cout << " 5 - Voltar ao menu anterior" << endl;
	cout << " 6 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	while (opcao < 1 || opcao > 6) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				menu1();
				break;
			case 2:
				menu2();
				break;
			case 3:
				menu3();
				break;
			case 4:
				menu4();
				break;
			case 5:
				Menu();
				break;
			case 6:
				Sair();
				break;
			default:
				cout << "Opcao invalida! Introduza uma opcao: ";
			}
		}
		else {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Opcao invalida! Introduza opcao: ";
		}
	}
}


void menu1() {
	cout << endl << endl;;
	cout << "Ocupacao dos Campos de Tenis: " << endl;
	cout << endl;
	
	ocupacaoCampos(); //implementar
	
	cout << endl << endl;
	Menu1();
}

void menu2() {
	cout << endl << endl;
	cout << " 1 - Horario das aulas" << endl;
	cout << " 2 - Aulas lecionadas por professores" << endl;
	cout << " 3 - Voltar ao menu anterior" << endl;
	cout << " 4 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	while (opcao < 1 || opcao > 4) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				consultarHorario();
				break;
			case 2:
				professorDasAulas();
				break;
			case 3:
				Menu1();
				break;
			case 4:
				Sair();
				break;
			default:
				cout << "Opcao invalida! Introduza uma opcao: ";
			}
		}
		else {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Opcao invalida! Introduza opcao: ";
		}
	}
}

void menu3() {
	cout << endl << endl;
	cout << " 1 - Frequencia dos Utentes" << endl;
	cout << " 2 - Conta dos Utentes" << endl;
	cout << " 3 - Voltar ao menu anterior" << endl;
	cout << " 4 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	while (opcao < 1 || opcao > 4) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				freqUtentes();
				break;
			case 2:
				contasUtentes();
				break;
			case 3:
				Menu1();
				break;
			case 4:
				Sair();
				break;
			default:
				cout << "Opcao invalida! Introduza uma opcao: ";
			}
		}
		else {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Opcao invalida! Introduza opcao: ";
		}
	}
}

void menu4() {
	cout << endl << endl;;
	cout << "Horario dos Professores: " << endl;
	cout << endl;

	horarioProfessores(); 

	cout << endl << endl;
	Menu1();
}

void Sair() {
	string opcao;
	cout << endl;
	cout << "Deseja guardar as alteracoes feitas? (S/N): ";
	cin.clear();
	cin.ignore(10000, '\n');
	while (opcao != "s" && opcao != "S" && opcao != "n" && opcao != "N") {
		getline(cin, opcao);
		if (opcao == "s" || opcao == "S") {
			//guardarficheiroAulas();
			//guardarficheiroProfessores();
			//guardarficheiroUtentes();
			cout << "\nAlteracoes guardadas!\n";
			exit(0);
			break;
		}
		if (opcao == "n" || opcao == "N") {
			exit(0);
			break;
		}
		else {
			cout << "Opcao invalida! Introduza uma opcao: ";
		}
	}
}