#include "GenerateurControlee.hpp"

GenerateurControlee::GenerateurControlee(int nbTachesP, int nbTachesA) : nbTachesP_(nbTachesP), nbTachesA_(nbTachesA) {
	tabCiP_ = Tableau(nbTachesP);
	tabPiP_ = Tableau(nbTachesP);
	tabDiP_ = Tableau(nbTachesP);
	tabriA_ = Tableau(nbTachesA);
	tabCiA_ = Tableau(nbTachesA);
	this->generation();
	this->ecritureFichier();
}

GenerateurControlee::~GenerateurControlee() {

}

void GenerateurControlee::generation() {
	// periodique
	for (int i = 0 ; i < nbTachesP_ ; i++) {
		cout << "Tache Periodique:" << i+1;
		cout << "	Ci = ";
		cin >> tabCiP_[i];
		cout << "	Pi = ";
		cin >> tabPiP_[i];
		cout << "	Di = ";
		cin >> tabDiP_[i];
		cout << endl;
	}
	
	//aperiodique
	for (int i = 0 ; i < nbTachesA_ ; i++) {
		cout << "Tache Aperiodique:" << i+1;
		cout << "	ri = ";
		cin >> tabriA_[i];
		cout << "	Ci = ";
		cin >> tabCiA_[i];
		cout << endl;
	}
}

void GenerateurControlee::ecritureFichier() {
	ofstream fichier;
	fichier.open(FILEOUT);
	for (int i = 0 ; i < nbTachesP_; i++) {
		fichier << "T" << i+1 << ": " << tabCiP_[i] << "," << tabPiP_[i] << "," << tabDiP_[i] << endl;
	}
	for (int i = 0 ; i < nbTachesA_; i++) {
		fichier << "R" << i+1 << ": " << tabriA_[i] << "," << tabCiA_[i] << endl;
	}
	fichier.close();
}
