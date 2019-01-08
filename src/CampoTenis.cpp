#include "CampoTenis.h"

using namespace std;


int CampoTenis::hours(string horas)				//converte a string horas para um int
{
	int i;
	i = horas.find_first_of(':');
	string h = horas.substr(0, i);
	return stoi(h);
}

int CampoTenis::minutes(string horas)			//converte a string minutos para um int
{
	int i;
	i = horas.find_first_of(':');
	string m = horas.substr(i + 1);
	return stoi(m);
}


CampoTenis::CampoTenis() : utentes(Utente("", 0, 0, "", 0))
{
	this->nCampos = 5;
	this->lotCampo = 2;
	this->horaAbertura = "9h00";
	this->horaEncerramento = "19h00";
	int horas = hours(horaEncerramento) - hours(horaAbertura);
	horas = horas * 60;
	int minutos = minutes(horaEncerramento) - minutes(horaAbertura);
	nSlots = (horas + minutos) / 30;
}


int CampoTenis::getNumCampos() {
	return nCampos;
}

int CampoTenis::getLotacao() {
	return nCampos * lotCampo;
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

BST<Utente> CampoTenis::getUtentes()
{
	return utentes;
}

void CampoTenis::addUtente(string nome, int idade, bool goldCard, string morada, int nif) {
	Utente u(nome, idade, goldCard, morada, nif);
	utenTemp.push_back(u);
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
	//return utentes.size();
	int count = 0;

	BSTItrIn<Utente> it(utentes);
	while (!it.isAtEnd())
	{
		count++;
		it.advance();
	}

	return count;
}

vector<Aula> CampoTenis::getAulas() {
	return aulas;
}

string CampoTenis::returnSigla() {				//retorna a sigla do professor com menos aulas
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

void CampoTenis::addAula(int dia, string horaInicio)
{

	string sigla = returnSigla();

	Aula a(dia, sigla, horaInicio);
	aulas.push_back(a);

	//encontra o indice do professor com menos aulas
	/**
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

	professores[index].pushAula(a);				//atribui a aula ao professor que tem menor nr de aulas
	*/

	HashProfessores::iterator it;
	
	
	for(it = allProf.begin(); it != allProf.end(); it++)
	{
		list<Professor>::iterator lt = it.;
		if (it->getEstado())
		{
			Professor p(it->getName(), it->getSigla(), it->getAge(), it->getMorada(), it->getNif());
			allProf.erase(*it);
			p.pushAula(a);
			allProf.insert(p);
			break;
		}
	}

}

void CampoTenis::addAulaUtente(string nome, int dia, string horai) {

	string sigla = returnSigla();
	Aula a(dia, sigla, horai);

	for (unsigned int i = 0; i < utenTemp.size(); i++)
	{
		if (nome == utenTemp[i].getName())
		{
			utenTemp[i].pushAula(a);
		}
	}

}

void CampoTenis::addLivre(int dia, string horaInicio, int nrSlots)
{
	Livre l(dia, horaInicio, nrSlots);
	livres.push_back(l);				//adiciona o livre ao vetor de livres
}


void CampoTenis::addLivreUtente(string nome, int dia, string horai, int nrSlots) {

	Livre l(dia, horai, nrSlots);

	/*BSTItrIn<Utente> it(utentes);

	while (!it.isAtEnd())
	{
		Utente u = it.retrieve();
		if (nome == u.getName())
		{
			u.pushLivre(l);			//adiciona o livre ao utente com o nome recebido como parametro
		}
		it.advance();
	}*/

	for (unsigned int i = 0; i < utenTemp.size(); i++)
	{
		utenTemp[i].pushLivre(l);
	}

}


void CampoTenis::addProf(string nome, string sigla, int idade, string morada, int nif)
{
	Professor prof(nome, sigla, idade, morada, nif);			//cria professor
	professores.push_back(prof);			//adiciona o professor ao vetor de professores
}

bool CampoTenis::removeUtente(string nome)
{
	//verifica se o utente existe
	unsigned int p = 0;
	bool existenciaUtente = false;

	BSTItrIn<Utente> it(utentes);

	while (!it.isAtEnd()) {
		if (it.retrieve().getName() == nome) {
			existenciaUtente = true;
			break;
		}
		it.advance();
	}

	if (!existenciaUtente) {
		cout << "Nome do utente invalido!" << endl;
		return false;
	}

	//remove utente do vetor de utentes

	BSTItrIn<Utente> ut(utentes);

	while (!ut.isAtEnd())
	{
		if (it.retrieve().getName() == nome)
		{
			utentes.remove(it.retrieve());
			break;
		}
		ut.advance();
	}

	//remove utente do ficheiro utentes 

	fstream ficheiroU;
	ficheiroU.open("Utentes.txt");
	string nomeUfich, linhaUfich, idadeU, cartaoU, moradaU, nifU;
	int contLinhas = 0, i = 0;
	vector<string> infoFichU;

	if (!ficheiroU.is_open())
	{
		//Caso o ficheiro nao exista
		cout << "Erro na abertura do ficheiro de Utentes!" << std::endl;
		return false;
	}

	//guarda o indice da linha que é para apagar

	while (!ficheiroU.eof())
	{
		getline(ficheiroU, nomeUfich, ',');
		getline(ficheiroU, idadeU, ',');
		getline(ficheiroU, cartaoU, ',');
		getline (ficheiroU, moradaU, ',');
		getline(ficheiroU, nifU, '\n');

		if (nomeUfich == nome) {
			break;
		}

		contLinhas++;
	}

	ficheiroU.close();


	//guarda toda a informacao do ficheiro, exceto da linha de indice contLinhas;

	fstream lerficheiroU;
	lerficheiroU.open("Utentes.txt");

	if (!lerficheiroU.is_open())
	{
		//Caso o ficheiro nao exista
		cout << "Erro na abertura do ficheiro de Utentes!" << std::endl;
		return false;
	}

	while (!lerficheiroU.eof())
	{
		getline(lerficheiroU, linhaUfich, '\n');

		if (i == contLinhas) {
			i++;
		}
		else {
			infoFichU.push_back(linhaUfich);
			i++;
		}
	}

	lerficheiroU.close();

	//elimina ficheiro utentes 
	remove("Utentes.txt");

	//criar novo ficheiro utentes com as informacoes do vetor(ja sem o utente removido)

	ofstream novoFicheiro;
	novoFicheiro.open("Utentes.txt");

	if (!novoFicheiro.is_open())
	{
		//Caso o ficheiro nao exista
		cout << "Erro na abertura do ficheiro de Utentes!" << std::endl;
		return false;
	}

	for (unsigned int j = 0; j < infoFichU.size(); j++) {
		if (j == infoFichU.size() - 1) {
			novoFicheiro << infoFichU[j];  //nao coloca o endl se for o ultimo utente a escrever para o ficheiro
		}
		else
			novoFicheiro << infoFichU[j] << endl;
	}

	novoFicheiro.close();

	return true;

}

bool CampoTenis::removeProf(string nome)
{
	//verifica se o professor existe
	unsigned int p = 0;
	bool existenciaProf = false;
	while (p < professores.size()) {
		if (professores[p].getName() == nome) {
			existenciaProf = true;
			break;
		}
		p++;
	}

	if (!existenciaProf) {
		cout << "Nome do professor invalido!" << endl;
		return false;
	}

	//remove o professor do vetor de professores
	for (unsigned int i = 0; i < professores.size(); i++)
	{
		if (professores[i].getName() == nome)
		{
			professores.erase(professores.begin() + i);
			break;
		}
	}

	//remove professor do ficheiro professores

	fstream ficheiroP;
	ficheiroP.open("Professores.txt");
	string nomePfich, linhaPfich, idadeP, siglaP, moradaP, nifP;
	int contLinhas = 0, i = 0;
	vector<string> infoFichP;

	if (!ficheiroP.is_open())
	{
		//Caso o ficheiro nao exista
		cout << "Erro na abertura do ficheiro de Professores!" << std::endl;
		return false;
	}

	//guarda o indice da linha que é para apagar

	while (!ficheiroP.eof())
	{
		getline(ficheiroP, nomePfich, ',');
		getline(ficheiroP, siglaP, ',');
		getline(ficheiroP, idadeP, ',');
		getline(ficheiroP, moradaP, ',');
		getline(ficheiroP, nifP, '\n');

		if (nomePfich == nome) {
			break;
		}

		contLinhas++;
	}

	ficheiroP.close();


	//guarda toda a informacao do ficheiro, exceto da linha de indice contLinhas;

	fstream lerficheiroP;
	lerficheiroP.open("Professores.txt");

	if (!lerficheiroP.is_open())
	{
		//Caso o ficheiro nao exista
		cout << "Erro na abertura do ficheiro de Professores!" << std::endl;
		return false;
	}

	while (!lerficheiroP.eof())
	{
		getline(lerficheiroP, linhaPfich, '\n');

		if (i == contLinhas) {
			i++;
		}
		else {
			infoFichP.push_back(linhaPfich);
			i++;
		}
	}

	lerficheiroP.close();

	//elimina ficheiro professores
	remove("Professores.txt");

	//criar novo ficheiro professores com as informacoes do vetor(ja sem o professor removido)

	ofstream novoFicheiro;
	novoFicheiro.open("Professores.txt");

	if (!novoFicheiro.is_open())
	{
		//Caso o ficheiro nao exista
		cout << "Erro na abertura do ficheiro de Professores!" << std::endl;
		return false;
	}

	for (unsigned int j = 0; j < infoFichP.size(); j++) {
		if (j == infoFichP.size() - 1) {
			novoFicheiro << infoFichP[j];  //nao coloca o endl se for o ultimo professor a escrever para o ficheiro
		}
		else
			novoFicheiro << infoFichP[j] << endl;
	}

	novoFicheiro.close();

	//alterar os dados do professor

	HashProfessores::iterator it;
	vector<Aula> aulasProfaux;
	

	for (it = allProf.begin(); it != allProf.end(); it++)
	{
		if (it->getEstado() == true && it->getName() == nome)
		{
			Professor prof = (*it);
			aulasProfaux = it->getAulaVec();
			allProf.erase(*it);
			prof.changeEstado(false);
			prof.emptyAulas();
			allProf.insert(prof);

			for (unsigned int i = 0; i < aulasProfaux.size(); i++)
			{
				addAula(aulasProfaux[i].getDia(), aulasProfaux[i].getHoraI());
			}

		}
	}

	return true;

}

vector<Livre> CampoTenis::getLivres() {
	return livres;
}

void CampoTenis::atualizaVetorDisp() {

	//preenche o vetor de vetores com todos os elemntos iguais a lotacao

	for (int i = 0; i < 20; i++) {
		dispCamposPorSlot.push_back(vector<int>());     //adiciona linha vazia
	}


	for (unsigned int i = 0; i < 20; i++) {				//i corresponde ao nr de slots
		for (unsigned int j = 0; j < 31; j++) {			//j corresponde ao dia
			dispCamposPorSlot[i].push_back(10);
		}
	}

	//cada aula ira subtrair 1 aos dois slots correspondentes a hora de inicio da aula
	int diaAula, horasI, minutosI, nrSubtr, nrSlot;
	string horaInicio;

	for (unsigned int i = 0; i < aulas.size(); i++) {
		diaAula = aulas[i].getDia();
		horaInicio = aulas[i].getHoraI();

		horasI = hours(horaInicio);
		minutosI = minutes(horaInicio);

		//descobrir qual e o nr do slot a q as horas da aula correspondem

		if (horasI == 9)
			nrSubtr = 9;

		if (horasI == 10)
			nrSubtr = 8;

		if (horasI == 11)
			nrSubtr = 7;

		if (horasI == 12)
			nrSubtr = 6;

		if (horasI == 13)
			nrSubtr = 5;

		if (horasI == 14)
			nrSubtr = 4;

		if (horasI == 15)
			nrSubtr = 3;

		if (horasI == 16)
			nrSubtr = 2;

		if (horasI == 17)
			nrSubtr = 1;

		if (horasI == 18)
			nrSubtr = 0;


		if (minutosI == 30) {
			nrSlot = nrSubtr + 1;
		}
		else
			nrSlot = nrSubtr;

		int indSlot = horasI - nrSubtr;
		int nr = dispCamposPorSlot[indSlot][diaAula - 1];

		dispCamposPorSlot[indSlot][diaAula - 1] = nr - 1;		//decrementa 1 a disponibilidade desse indice
		if (indSlot + 1 < 20) {										//verifica se nao excede o o nr de slots
			dispCamposPorSlot[indSlot + 1][diaAula - 1] = nr - 1;		//decrementa 1 a disponibilidade do indice seguinte(porque aula tem 2 slots)
		}
	}
}


void CampoTenis::displayDispCampos() {

	vector<string> todasHoras = { "09:00","09:30","10:00","10:30","11:00","11:30","12:00","12:30","13:00","13:30","14:00","14:30","15:00","15:30","16:00","16:30","17:00","17:30","18:00","18:30","19:00" };

	cout << endl;
	cout << "Horas Dia -->\n";
	cout << "  |\n";
	cout << "  V\n";

	cout << "            ";

	for (unsigned int i = 1; i <= 31; i++)			//escreve os dias no ecra
	{
		cout << setw(4) << i;
	}
	cout << endl << endl;
	for (unsigned int k = 0; k < 20; k++)
	{
		cout << todasHoras[k] << "-" << todasHoras[k + 1] << " ";			//escreve os intervalos de horas(30 em 30 min)
		for (unsigned int j = 0; j < 31; j++)
		{
			cout << setw(4) << dispCamposPorSlot[k][j];			//escreve a disponibilidade do campo nesse dia e hora
		}
		cout << endl;
	}
	cout << endl << endl;
}

vector<vector<int>> CampoTenis::getDispCampos() {
	return dispCamposPorSlot;		//retorna o vetor de disponibilidade dos campos
}

bool CampoTenis::verificaExProf(string nome) {
	/*
	for (unsigned int i = 0; i < professores.size(); i++) {
		if (professores[i].getName() == nome) {			//verifica se o professor de nome "nome" existe no vetor de professores
			return true;
		}
	}
	return false;
	*/

	HashProfessores::iterator it;

	for (it = allProf.begin(); it != allProf.end(); it++)
	{
		if (it->getName() == nome && it->getEstado() == true)
		{
			return true;
		}
	}
	return false;

}

bool CampoTenis::verificaExUten(string nome) {

	BSTItrIn<Utente> it(utentes);

	while (!it.isAtEnd())
	{
		if (it.retrieve().getName() == nome) {			//verifica se o utente de nome "nome" existe no vetor de utentes
			return true;
		}
		it.advance();
	}
	return false;
}

void CampoTenis::addTecnico(string nome, int disp, int nrR) {
	
	ServicoTecnico tec(nome, disp,nrR);			//cria tecnico
	
	tecnicos.push(tec);			//adiciona o tecnico a fila de prioridade
}


void CampoTenis::addTec(string nome, int disp, int nrR) {
	ServicoTecnico tec(nome, disp, nrR);			//cria tecnico

	tecnicos.push(tec);			//adiciona o tecnico a fila de prioridade


	//atualiza ficheiro .txt
	ofstream stec;
	stec.open("ServicoTecnico.txt");

	priority_queue<ServicoTecnico> aux = tecnicos;

	while (!aux.empty())
	{
		ServicoTecnico tec = aux.top();
		aux.pop();

		if (aux.size() == 0) {
			stec << tec.getNomeTec() << "," << tec.getDisponibilidade() << "," << tec.getNrReparacoes();
		}
		else {
			stec << tec.getNomeTec() << "," << tec.getDisponibilidade() << "," << tec.getNrReparacoes()<<endl;
		}
	}

	stec.close();
}

void CampoTenis::infoTec() {

	priority_queue<ServicoTecnico> temp = tecnicos;
	cout << "NOME,DISPONIBILIDADE,NUMERO DE REPARACOES" << endl << endl;
	while (!temp.empty())
	{
		ServicoTecnico st = temp.top();
		temp.pop();
		string nome = st.getNomeTec();
		int dis = st.getDisponibilidade();
		int rep = st.getNrReparacoes();
		cout <<nome << ","<< dis << "," << rep << endl;
	}
}


void CampoTenis::tecDisp(int maxReparacoes) {
	priority_queue<ServicoTecnico> temp = tecnicos;
	priority_queue<ServicoTecnico> aux;

	while (!temp.empty())
	{
		ServicoTecnico s = temp.top();
		if (s.getNrReparacoes() < maxReparacoes) {
			cout << "Tecnico " << s.getNomeTec() << " fara a reparacao do campo daqui a " << s.getDisponibilidade() << " dias" << endl;
			
			string nome = s.getNomeTec();
			int disp = s.getDisponibilidade();
			int rep = s.getNrReparacoes();

			ServicoTecnico t(nome,disp + 1, rep + 1);
			aux.push(t);
			temp.pop();
			while (!temp.empty())
			{
				aux.push(temp.top());
				temp.pop();
			}

			break;
		}
		
		aux.push(s);
		temp.pop();
	}

	tecnicos = aux;
	
	//atualiza ficheiro .txt
	ofstream stec;
	stec.open("ServicoTecnico.txt");

	aux = tecnicos;

	while (!aux.empty())
	{
		ServicoTecnico tec = aux.top();
		aux.pop();
		if (aux.size() == 0) {
			stec << tec.getNomeTec() << "," << tec.getDisponibilidade() << "," << tec.getNrReparacoes();
		}
		else {
			stec << tec.getNomeTec() << "," << tec.getDisponibilidade() << "," << tec.getNrReparacoes()<<endl;
		}
	}

	stec.close();
}


bool CampoTenis::verificaExTec(string nome) {
	priority_queue<ServicoTecnico> aux = tecnicos;
	bool exTec = false;

	while (!aux.empty()) {
		ServicoTecnico servico = aux.top();
		string nomeT = servico.getNomeTec();
		if (nomeT == nome) {
			exTec = true;
			break;
		}
		aux.pop();
	}

	return exTec;
}

bool CampoTenis::removeTec(string nomeTec) {
	
	//atualiza ficheiro .txt
	ofstream stec;
	stec.open("ServicoTecnico.txt");

	priority_queue<ServicoTecnico> aux = tecnicos;

	while (!aux.empty())
	{
		ServicoTecnico tec = aux.top();
		aux.pop();

		if (aux.size() == 0) {
			stec << tec.getNomeTec() << "," << tec.getDisponibilidade() << "," << tec.getNrReparacoes();
		}
		else {
			stec << tec.getNomeTec() << "," << tec.getDisponibilidade() << "," << tec.getNrReparacoes()<<endl;
		}
	}

	stec.close();

	return true;
}

void CampoTenis::insertBST(Utente uten)
{
	utentes.insert(uten);
}

void CampoTenis::insertHash(string nome, string sigla, int idade, string morada, int nif)
{
	Professor prof(nome, sigla, idade, morada, nif);
	allProf.insert(prof);
}

