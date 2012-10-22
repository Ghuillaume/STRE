#include "Parseur.hpp"

Parseur::Parseur() {

}

Parseur::~Parseur() {
	
}
	
void Parseur::lireFichier(string nomFichier, Conteneur c) {
	string line;
	ifstream streamFichier(nomFichier.c_str(), ifstream::in);
	
	if (streamFichier.is_open()) {
		while (streamFichier.good())
		{
			getline(streamFichier, line);
			if (verifierSyntaxe(line)) {
				//TODO: Récupérer les paramètres
				//TODO: créer les taches via c->addT?()
				
			} else {
				cout << "Syntaxe non valide : ";
			}
			cout << line << endl;
		}
    streamFichier.close();
	} else {
		cout << "Erreur : impossibilité d'ouvrir le fichier '"
				<< nomFichier << "'." << endl; 
	}
}

bool Parseur::verifierSyntaxe(string &line) {
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
