#include "Menu.h"
#include "Funcoes.h"
#include "CampoTenis.h"
#include "ServicoTecnico.h"
#include <Windows.h>
#include <stdlib.h>

using namespace std;

CampoTenis *c = new CampoTenis();

void menuPrincipal() {

	system("pause");
	system("cls");

	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "          ALUGUER DE CAMPOS DE TENIS          " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "1 - Consultar Informacao" << endl;
	cout << "2 - Alterar dados" << endl;
	cout << "3 - Servicos Tecnicos" << endl;
	cout << "4 - Sair" << endl;
	cout << "--------------------------------------------- " << endl;
	
	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";

	while (opcao < 1 || opcao > 3) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				menuInformacoes();
				break;
			case 2:
				menuAlteracoes();
				break;
			case 3:
				menuTecnicos();
				break;
			case 4:
				sair();
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

void menuInformacoes() {
	system("pause");
	system("cls");

	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "          ALUGUER DE CAMPOS DE TENIS          " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << " 1 - Informacao relativa aos Campos de Tenis" << endl;
	cout << " 2 - Informacao relativa as Aulas" << endl;
	cout << " 3 - Informacao relativa aos Utentes" << endl;
	cout << " 4 - Voltar ao menu anterior" << endl;
	cout << " 5 - Sair" << endl;
	cout << "--------------------------------------------- " << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	while (opcao < 1 || opcao > 6) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				menuInfoCampos();
				break;
			case 2:
				menuInfoAulas();
				break;
			case 3:
				menuInfoUtentes();
				break;
			case 4:
				menuPrincipal();
				break;
			case 5:
				sair();
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

void menuAlteracoes() {
	system("pause");
	system("cls");

	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "          ALUGUER DE CAMPOS DE TENIS          " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << " 1 - Adicionar Utente" << endl;
	cout << " 2 - Adicionar Professor" << endl;
	cout << " 3 - Remover Utente" << endl;
	cout << " 4 - Remover Professor" << endl;
	cout << " 5 - Voltar ao menu anterior" << endl;
	cout << " 6 - Sair" << endl;
	cout << "--------------------------------------------- " << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	string no, sigla, morada;
	int idade, gold, nif;
	while (opcao < 1 || opcao > 6) {
		if (cin >> opcao) {
			switch (opcao) {
			case 1:
				//adicionar utente
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do novo Utente: "; getline(cin, no, '\n');
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira a idade do Utente: "; cin >> idade;
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "O Utente tem goldCard? (se sim meta 1,se nao meta 0) "; cin >> gold;
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira a morada do Utente: ";getline(cin, morada, '\n');
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o NIF do Utente: "; cin >> nif;
				adicionarUtente(no, idade, gold, morada, nif);
				cout << endl;
				cout << "Utente adicionado com sucesso!" << endl << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				menuAlteracoes();
				break;
			case 2:
				//adiciona professor
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do novo Professor: "; getline(cin, no, '\n');
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira a sigla do Professor: "; cin >> sigla;
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira a idade do Professor: "; cin >> idade;
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira a morada do Professor: "; getline(cin, morada, '\n');
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o NIF do Professor: "; cin >> nif;
				adicionarProfessor(no, sigla, idade, morada, nif);
				cout << endl;
				cout << "Professor adicionado com sucesso!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				menuAlteracoes();
				break;
			case 3:
				//remover utente
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do Utente a remover: "; getline(cin, no, '\n');
				if (c->verificaExUten(no)) {
					if (c->removeUtente(no)) {
						cout << "Utente removido com sucesso!" << endl;
					}
					else
						cout << "Nao foi possivel remover o Utente!" << endl;

					cin.clear();
					cin.ignore(10000, '\n');
					menuAlteracoes();
				}
				else {
					cout << endl;
					cout << "Nome de utente invalido!" << endl;
					menuInfoAulas();
				}

				break;
			case 4:
				//remover professor
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do Professor a remover: "; getline(cin, no, '\n');
				if (c->verificaExProf(no)) {
					if (c->removeProf(no)) {
						cout << endl;
						cout << "Professor removido com sucesso!" << endl;
					}
					else {
						cout << endl;
						cout << "Nao foi possivel remover o Professor!" << endl;
					}

					cin.clear();
					cin.ignore(10000, '\n');
					menuAlteracoes();

				}
				else {
					cout << endl;
					cout << "Nome de professor invalido!" << endl;
					menuAlteracoes();
				}
				break;
			case 5:
				menuPrincipal();
				break;
			case 6:
				sair();
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


void menuTecnicos() {
	system("pause");
	system("cls");
	
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "          ALUGUER DE CAMPOS DE TENIS          " << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "1 - Consultar informacao de todos tecnicos" << endl;
	cout << "2 - Reparacao do Campo de Tenis" << endl;
	cout << "3 - Adicionar Tecnico" << endl;
	cout << "4 - Remover Tecnico" << endl;
	cout << "5 - Sair" << endl;
	cout << "--------------------------------------------- " << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	string noT;
	int nrRt, dispT;
	while (opcao < 1 || opcao > 3) {
		if (cin >> opcao) {

			switch (opcao) {
			case 1:
				//consulta informacao dos tecnicos
				infoTecnicos();
				cin.clear();
				cin.ignore(10000, '\n');
				menuTecnicos();
				break;
			case 2:
				//seleciona tecnico que fara a reparacao do campo
				reparacao();
				cin.clear();
				cin.ignore(10000, '\n');
				menuTecnicos();
				break;
			case 3:
				//adicionar tecnico 
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do novo Tecnico: "; getline(cin, noT, '\n');
				cin.clear();
				cout << "Insira a disponibilidade do novo Tecnico: "; cin >> dispT;
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o numero de reparacoes do novo Tecnico: "; cin >> nrRt;
				cin.clear();
				cin.ignore(10000, '\n');
				adicionarTecnico(noT, dispT, nrRt);
				cout << endl;
				cout << "Tecnico adicionado com sucesso!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				menuTecnicos();
				break;
			case 4:
				//remover tecnico 
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do Tecnico a remover: "; getline(cin, noT, '\n');
				if (c->verificaExTec(noT)) {
					if (c->removeTec(noT)) {
						cout << endl;
						cout << "Tecnico removido com sucesso!" << endl;
					}
					else {
						cout << endl;
						cout << "Nao foi possivel remover o Tecnico!" << endl;
					}
					cin.clear();
					cin.ignore(10000, '\n');
					menuTecnicos();
				}
				else {
					cout << endl;
					cout << "Nome de tecnico invalido!" << endl;
					menuTecnicos();
				}
				break;
			case 5:
				sair();
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

void infoTecnicos() {
	system("pause");
	system("cls");

	cin.clear();
	cin.ignore(10000, '\n');
	
	c->infoTec();
}

void reparacao() {
	system("pause");
	system("cls");

	cin.clear();
	cin.ignore(10000, '\n');
	int maxRep;

	cout << "Insira o numero maximo de reparacoes de um tecnico: ";
	cin >> maxRep;

	c->tecDisp(maxRep);
}


void menuInfoCampos() {
	system("pause");
	system("cls");

	cout << endl << endl;
	cout << "Numero de Campos de Tenis: " << endl;
	
	int n = c->getNumCampos();
	cout << n << endl;
	cout << endl;

	cout << "Disponibilidade dos Campos de Tenis: " << endl;
	c->displayDispCampos();
	cout << endl;
	cout << "Informacao: As marcacoes de livres so poderao ser feitas nos dias/horas onde a disponibilidade for diferente de zero." << endl;

	cout << endl << endl;
	menuInformacoes();
}

void menuInfoAulas() {
	system("pause");
	system("cls");

	string no;
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
				cout << endl;
				cout << "HORARIO DAS AULAS: " << endl << endl;
				for (int i = 9; i < 19; i++) {
					cout << "Aula" << t << ": " << " Das " << i << "h" << " as " << i + 1 << "h" << endl;
					t = t + 1;
				}
				cout << endl;
				menuInfoAulas();
				break;
			case 2:
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do professor: "; getline(cin, no, '\n');
				cout << endl;
				if (c->verificaExProf(no)) {
					cout << "Aulas do professor: " << endl << endl;
					professorDasAulas(no);
					menuInfoAulas();
				}
				else {
					cout << endl;
					cout << "Nome de professor invalido!" << endl;
					menuInfoAulas();
				}
				break;
			case 3:
				menuInformacoes();
				break;
			case 4:
				sair();
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

void menuInfoUtentes() {
	system("pause");
	system("cls");

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
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do Utente: "; getline(cin, no, '\n');
				cout << endl;

				if (c->verificaExUten(no)) {
					cout << no << " frequentou os campos de tenis " << freqUtentes(no) << " vezes durante este mes.\n" << endl;
					freqUtentes(no);
					menuInfoUtentes();
				}
				else {
					cout << endl;
					cout << "Nome de utente invalido!" << endl;
					menuInfoUtentes();
				}
				
				break;
			case 2:
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do Utente: "; getline(cin, no, '\n');
				cout << endl;

				if (c->verificaExUten(no)) {
					cout << "Conta do Utente" << endl << endl;
					cout << "Nome: "; cout << no << endl;
					cout << "Age: "; cout << contasUtentes(no).at(0) << endl;
					cout << "Gold Card: ";
					if (contasUtentes(no).at(1) == 1)
						cout << "Tem cartao gold" << endl << endl;
					else
						cout << "Nao tem cartao gold" << endl << endl;

					menuInfoUtentes();
				}
				else {
					cout << endl;
					cout << "Nome de utente invalido!" << endl<<endl;
					menuInfoUtentes();
				}
				break;
			case 3:
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Insira o nome do Utente: "; getline(cin, no, '\n');

				if (c->verificaExUten(no)) {
					criarDoc(no);
					cout << endl;
					cout << "Relatorio de fim do mes criado com sucesso!" << endl << endl;
					menuInfoUtentes();
				}
				else {
					cout << endl;
					cout << "Nome de utente invalido!" << endl << endl;
					menuInfoUtentes();
				}
				break;
			case 4:
				menuInformacoes();
				break;
			case 5:
				sair();
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

void sair() {
	string opcao;
	cout << endl;
	cout << "Tem a certeza que quer sair da aplicacao? (S/N): ";
	cin.clear();
	cin.ignore(10000, '\n');
	while (opcao != "s" && opcao != "S" && opcao != "n" && opcao != "N") {
		getline(cin, opcao);
		if (opcao == "s" || opcao == "S") {
			exit(0);
			break;
		}
		if (opcao == "n" || opcao == "N") {
			menuPrincipal();
			break;
		}
		else {
			cout << "Opcao invalida! Introduza uma opcao: ";
		}
	}
}

void titulo() {
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

	cout << endl << endl << endl;

	cout << "A carregar ficheiros existentes......" << endl << endl;
}

void carregarFicheiros() {
	system("pause");
	system("cls");

	lerficheiroServicoT(c);
	lerficheiroProfessores(c);
	lerficheiroUtentes(c);
	lerficheiroAulas(c);
	c->atualizaVetorDisp();
	lerficheiroLivres(c);
	cout << endl;

	cout << "Ficheiros carregados!" << endl << endl;
	menuPrincipal();
}
