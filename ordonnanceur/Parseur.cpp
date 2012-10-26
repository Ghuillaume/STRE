#include "Parseur.hpp"

Parseur::Parseur() {

}

Parseur::~Parseur() {
	
}
	
void Parseur::lireFichier(string nomFichier, Conteneur* c) {
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

			// Si la longueur est nulle, c'est la dernière ligne, on ne la considère pas
			if(line.length() < 1)
				return true;
			
			cout << endl << "Verif line " << line << endl;

			int err;
			regex_t pregP;
			regex_t pregAp;
			const char *exprPeriodique = "^T[0-9]+: [0-9]+,[0-9]+,[0-9]+$";
			const char *exprAperiodique = "^R[0-9]+: [0-9]+,[0-9]+$";
			
			// Compilation des regex
			if(regcomp (&pregP, exprPeriodique, REG_NOSUB | REG_EXTENDED | REG_ICASE) == 0
					&& regcomp (&pregAp, exprAperiodique, REG_NOSUB | REG_EXTENDED | REG_ICASE) == 0 ) {
			
				if (regexec (&pregP, line.c_str(), 0, NULL, 0) == 0)
					return true;
				else if (regexec (&pregAp, line.c_str(), 0, NULL, 0) == 0)
					return true;
				else
					return false;
				
			}
   
			
			return true; 
}
