#include "Parseur.h"

Parseur::Parseur(string nomFichier, ConteneurTache* conteneur) :
				nomFichier_(nomFichier), conteneur_(conteneur) {
	
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
	return true;
}
