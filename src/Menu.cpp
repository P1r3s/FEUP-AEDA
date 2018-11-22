#include "Menu.h"
#include "Funcoes.h"
#include "CampoTenis.h"
#include <Windows.h>

using namespace std;

CampoTenis *c = new CampoTenis();

void Menu() {

	char quote = 34;

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 016);

	cout << "   ,odOO" << quote << "bo," << setw(58) << "   ,odOO" << quote << "bo," << endl;
	cout << " ,dOOOP'dOOOb," << setw(62) << " ,dOOOP'dOOOb," << endl;
	cout << ",O3OP'dOO3OO33, --------------------------------------------- ,O3OP'dOO3OO33," << endl;
	cout << "P" << quote << ",ad33O333O3Ob          ALUGUER DE CAMPOS DE TENIS           P" << quote << ",ad33O333O3Ob" << endl;
	cout << "?833O338333P" << quote << ",d --------------------------------------------- ?833O338333P" << quote << ",d" << endl;
	cout << "`88383838P,d38'" << setw(62) << "`88383838P,d38'" << endl;
	cout << " `Y8888P,d88P'" << setw(62) << " `Y8888P,d88P'" << endl;
	cout << "   `" << quote << "?8,8P" << quote << "'" << setw(54) << "   `" << quote << "?8,8P" << quote << "'" << endl;

	SetConsoleTextAttribute(color, 017);

	cout << endl << endl;
	cout << "1 - Carregar ficheiros existentes" << endl;
	cout << "2 - Criar novos ficheiros" << endl;
	cout << "3 - Sair" << endl;
	
	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";

	while (opcao < 1 || opcao > 3) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				lerficheiroProfessores(c);
				lerficheiroUtentes(c);
				lerficheiroModos(c);
				cout << endl;
				cout << "Ficheiros carregados!" << endl;

				//for (unsigned int i = 0; i < c->getLivres().size(); i++)
					//cout << c->getLivres()[i].getDia() << endl;

				Menu1();
				break;
			case 2:
				criarFicheiros();
				cout << endl;
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
	cout << "          ALUGUER DE CAMPOS DE TENIS          " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Informacao relativa aos Campos de Tenis" << endl;
	cout << " 2 - Informacao relativa as Aulas" << endl;
	cout << " 3 - Informacao relativa aos Utentes" << endl;
	cout << " 4 - Informacao relativa aos Professores" << endl;
	cout << " 5 - Voltar ao menu anterior" << endl;
	cout << " 6 - Sair" << endl;
	cout << "--------------------------------------------- " << endl;

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

void Menu2() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "          ALUGUER DE CAMPOS DE TENIS          " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Adicionar Utente" << endl;
	cout << " 2 - Remover Utente" << endl;
	cout << " 3 - Adicionar Professor" << endl;
	cout << " 4 - Remover Professor" << endl;
	cout << " 5 - Voltar ao menu anterior" << endl;
	cout << " 6 - Sair" << endl;
	cout << "--------------------------------------------- " << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	string no, sigla;
	int idade, gold;
	while (opcao < 1 || opcao > 6) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				//adicionar utente
				cout << "Insira o nome do novo Utente: "; getline(cin, no, '\n');
				cout << "Insira a idade do Utente: "; cin >> idade;
				cout << "O Utente tem goldCard? (se sim meta 1,senao meta 0) "; cin >> gold;
				adicionarUtente(no, idade, gold);
				break;
			case 2:
				//adiciona professor
				cout << "Insira o nome do novo Professor: "; getline(cin, no, '\n');
				cout << "Insira a sigla do Utente: "; cin >> sigla;
				cout << "Insira a idade do Utente: "; cin >> idade;
				adicionarProfessor(no,sigla, idade);
				break;
			case 3:
				//remover utente                 FALTA IMPLEMENTAR
				break;
			case 4:
				//remover professor              FALTA IMPLEMENTAR
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
	cout << endl << endl;
	cout << "Numero de Campos de Tenis: " << endl;
	
	int n = c->getNumCampos();
	cout << n << endl;
	cout << endl;
	cout << "Ocupacao dos Campos de Tenis: " << endl;


	//FAZER DISPLAY DO VETOR 
	/*
	for (unsigned int i = 0; i < n; i++) {
		unsigned int t = i + 1;
		int c= ocupacaoC(i);
		cout << "Campo" << t << ": " << c << endl;
	}
	 */

	c->displayHorario();

	cout << endl;

	cout << endl << endl;
	Menu1();
}

void menu2() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "          ALUGUER DE CAMPOS DE TENIS          " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << " 1 - Horario das aulas" << endl;
	cout << " 2 - Aulas lecionadas por professores" << endl;
	cout << " 3 - Voltar ao menu anterior" << endl;
	cout << " 4 - Sair" << endl;
	cout << "--------------------------------------------- " << endl;
	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	int t = 1;
	while (opcao < 1 || opcao > 4) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				for (int i = 9; i < 20; i++) {
					cout << "Aula" << t << ": " << " Das " << i << "h" << " as " << i + 1 << "h" << endl;
					t = t + 1;
				}
				menu2();
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
	cout << "--------------------------------------------- " << endl;
	cout << "          ALUGUER DE CAMPOS DE TENIS          " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << " 1 - Frequencia dos Utentes" << endl;
	cout << " 2 - Conta dos Utentes" << endl;
	cout << " 3 - Gerar relatorio de fim do mes" << endl;
	cout << " 4 - Voltar ao menu anterior" << endl;
	cout << " 5 - Sair" << endl;
	cout << "--------------------------------------------- " << endl;
	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	string no;
	while (opcao < 1 || opcao > 4) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				cout << "Insira o nome do Utente: "; getline(cin, no, '\n');
				cout << no<< " frequentou os campos de tenis "<< freqUtentes(no)<<" vezes.";
				freqUtentes(no);
				break;
			case 2:
				cout << "Insira o nome do Utente: "; getline(cin, no, '\n');
				cout << endl;
				cout << "Conta do Utente" << endl << endl;
				cout << "Nome: "; cout << no << endl;
				cout << "Age: "; cout << contasUtentes(no).at(0) << endl;
				cout << "Gold Card: "; 
				if (contasUtentes(no).at(0) == 1)
					cout << "Tem cartao gold" << endl;
				else 
					cout << "Nao tem cartao gold" << endl;
				break;
			case 3:
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do Utente: "; getline(cin, no, '\n');
				criarDoc(no);
				break;
			case 4:
				Menu1();
				break;
			case 5:
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
			//escrever para os ficheiros
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
