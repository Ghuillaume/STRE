#include "Traceur.hpp"

Traceur::Traceur() {
	this->creationFichier();
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
	ostringstream oss;
	oss << time << " READY-B " << numTache << endl;
	oss << time << " START " << numTache << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::reveilAperiodique(int time, int Ci, int nbTacheA) {
	ostringstream oss;
	oss << time << " ARROWUP " << nbTacheA << " " << Ci << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::execution(int time, int numTache) {
	ostringstream oss;
	//oss << time << " READY-E " << numTache << endl;
	oss << time << " EXEC-B " << numTache << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::preemption(int time, int numTache) {
	ostringstream oss;
	oss << time << " EXEC-E " << numTache << endl;
	this->ecritureFichier(oss.str());
}

void Traceur::finExecution(int time, int numTache) {
	ostringstream oss;
	oss << time << " STOP " << numTache << endl;
	oss << time << " EXEC-E " << numTache << endl;
	this->ecritureFichier(oss.str());
}


void Traceur::dateEcheance(int time, int numTache) {
	ostringstream oss;
	oss << time << " DEADLINE " << numTache << endl;
	this->ecritureFichier(oss.str());
}



void Traceur::creationFichier() {
	file_.open("fichierTraceur.ktr");
}

void Traceur::fermetureFichier() {
	file_.close();
}

void Traceur::ecritureFichier(string line) {
	file_ << line;
}
