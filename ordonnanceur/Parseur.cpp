#include "Parseur.h"

Parseur::Parseur(string nomFichier, ConteneurTacheAperiodique* conteneurApe, ConteneurTachePeriodique* conteneurPe) :nomFichier_(nomFichier), conteneurApe_(conteneurApe), conteneurPe_(conteneurPe) {

}

Parseur::~Parseur() {
	
}
	
void Parseur::lireFichier() {
	string line;
	ifstream streamFichier(nomFichier_.c_str(), ifstream::in);
	
	if (streamFichier.is_open()) {
		while (streamFichier.good())
		{
			getline(streamFichier, line);
			if (verifierSyntaxe(line)) {
				//TODO: Récupérer les paramètres et appeler la bonne méthode statique
			} else {
				cout << "Syntaxe non valide : ";
			}
			cout << line << endl;
		}
    streamFichier.close();
	} else {
		cout << "Erreur : impossibilité d'ouvrir le fichier '"
				<< nomFichier_ << "'." << endl; 
	}
}

void Parseur::ajouterTachePeriodique(int Ci, int Pi, int Di) {
	
}

void Parseur::ajouterTacheAperiodique(int ri, int Ci) {
	
}

bool Parseur::verifierSyntaxe(string line) {
	//TODO: Vérifier que la syntaxe est bonne via une regex
	if (line[0] == 'T') {
		cout << "c'est un T" << endl;
	}
	else if (line[0] == 'R') {
		cout << "ou pas " << endl;
	}
	else {
		cout << "fichier mal formé" << endl;
	}
	 
	return true;
}
