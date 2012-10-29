#include "Parseur.hpp"

Parseur::Parseur() {

}

Parseur::~Parseur() {
	
}
	
void Parseur::lireFichier(char* nomFichier, Conteneur* c) {
	string line;
	int numLine = 0;
	ifstream streamFichier(nomFichier, ifstream::in);
	
	int delimiter;
	ListOfString params;
	
	int numT = 0, Ci = 0, Pi = 0, Di = 0, Ri = 0;
	
	if (streamFichier.is_open()) {
		while (streamFichier.good())
		{
			numLine++;
			getline(streamFichier, line);
			if(line.length() < 1) // Si la longueur est nulle, c'est la dernière ligne, on ne la considère pas
				break;
				
			if (verifierSyntaxe(line)) {
			
				params = explode(line.substr(line.find(':')+1), ',' );
				
				numT = std::atoi(line.substr(1,line.find(':')-1).c_str());
				// Ajout d'une tâche périodique au conteneur
				if(*line.begin() == 'T') {
					Ci = std::atoi(params[0].c_str());
					Pi = std::atoi(params[1].c_str());
					Di = std::atoi(params[2].c_str());
					c->addTacheP(numT, Ci, Pi, Di);
				}
				// Ajout d'une tâche apériodique au conteneur
				else if(*line.begin() == 'R') {
					Ri = std::atoi(params[0].c_str());
					Ci = std::atoi(params[1].c_str());
					c->addTacheA(numT, Ri, Ci);
				}
				
			} else {
				cout << "Erreur : Syntaxe non valide, ligne " << numLine << " ignorée" << endl;
			}
		}
		streamFichier.close();
	} else {
		cout << "Erreur : impossibilité d'ouvrir le fichier '" << nomFichier << endl; 
	}
}

bool Parseur::verifierSyntaxe(string &line) {
			
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
 
}
