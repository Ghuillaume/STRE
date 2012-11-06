#include "Traceur.hpp"

Traceur::Traceur() {

}

Traceur::~Traceur() {

}

void Traceur::entete(int hyperperiode) {
	ostringstream oss;
	oss << "DECIMAL_DIGITS 0" << endl;
	oss << "PALETTE Rainbow" << endl;
	oss << "DURATION " << hyperperiode << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::declarationTache(int indice, string nameTache) {
	ostringstream oss;
	oss << "LINE_NAME " << indice << " \"" << nameTache << "\"" << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::reveil(int time, int numTache){
	this->start(time,numTache);
	this->ready_B(time,numTache);
}

void Traceur::reveilAperiodiqueExec(int time, int Ci, int nbTacheA) {
	this->start(time,nbTacheA);
	this->ready_B(time,nbTacheA);
	this->arrow_Up(time,Ci, nbTacheA);
}

void Traceur::reveilAperiodiqueAttente(int time, int Ci, int nbTacheA) {
	this->arrow_Up(time,Ci,nbTacheA);
}

void Traceur::execution(int time, int numTache) {
	this->exec_B(time, numTache);
}

void Traceur::preemption(int time, int numTache) {
	this->exec_E(time, numTache);
}

void Traceur::finExecution(int time, int numTache) {
	this->ready_E(time,numTache);
	this->stop(time,numTache);
	this->exec_E(time,numTache);
}

void Traceur::dateEcheance(int time, int numTache) {
	this->deadline(time, numTache);
}

void Traceur::creationFichier(string nameFile) {
	ostringstream name;
	name << nameFile << ".ktr";
	string nom = name.str();
	file_.open(nom.c_str());
}

void Traceur::fermetureFichier() {
	file_.close();
}

void Traceur::ecritureFichier(string line) {
	file_ << line;
}

void Traceur::start(int time, int numTache) {
	ostringstream oss;
	oss << time << " START " << numTache << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::stop(int time, int numTache) {
	ostringstream oss;
	oss << time << " STOP " << numTache << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::deadline(int time, int numTache) {
	ostringstream oss;
	oss << time << " DEADLINE " << numTache << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::ready_B(int time, int numTache) {
	ostringstream oss;
	oss << time << " READY-B " << numTache << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::ready_E(int time, int numTache) {
	ostringstream oss;
	oss << time << " READY-E " << numTache << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::exec_B(int time, int numTache) {
	ostringstream oss;
	oss << time << " EXEC-B " << numTache << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::exec_E(int time, int numTache) {
	ostringstream oss;
	oss << time << " EXEC-E " << numTache << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::arrow_Up(int time, int Ci, int nbTacheA) {
	ostringstream oss;
	oss << time << " ARROWUP " << nbTacheA << " " << Ci << endl;
	this->ecritureFichier(oss.str());
}

