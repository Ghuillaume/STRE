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
			smatch sm;
			try {
				regex exprPeriodique("\^T(\d*)(.*)");
				if (regex_match(line,sm,exprPeriodique)) {
					for (unsigned i=0; i<sm.size(); ++i) {
	   					cout << "[" << sm[i] << "] ";
	  				}
					cout << "c'est une tache Periodique" << endl;
				}
				else {
					cout << "raté" << endl;
				}
			}
			catch (regex_error& e) {
				if (e.code() == regex_constants::error_collate) {
					cout << "erreur : error_collate" << endl;
				}
				else if (e.code() == regex_constants::error_ctype) {
					cout << "erreur : error_ctype" << endl;
				}
				else if (e.code() == regex_constants::error_escape) {
					cout << "erreur : error_escape" << endl;
				}
				else if (e.code() == regex_constants::error_backref) {
					cout << "erreur : error_backref" << endl;
				}
				else if (e.code() == regex_constants::error_brack) {
					cout << "erreur : error_brack" << endl;
				}
				else if (e.code() == regex_constants::error_paren) {
					cout << "erreur :error_paren " << endl;
				}
				else if (e.code() == regex_constants::error_brace) {
					cout << "erreur : error_brace" << endl;
				}
				else if (e.code() == regex_constants::error_badbrace) {
					cout << "erreur : error_badbrace" << endl;
				}	
				else {
				}		
				
			}
			
			
			return true; 
}
