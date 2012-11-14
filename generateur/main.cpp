/*******************************************************
Nom ......... : main.cpp
Role ........ : fonction principale du générateur
Auteur ...... : BONCORPS, CHARON, PAGES 
********************************************************/

#include "GenerateurAleatoire.hpp"
#include "GenerateurControlee.hpp"

using namespace std;
int main(int argc, char** argv) {	
	char choix;
	int nbTachesP = 0;
	int nbTachesA = 0;
	int utCPUP = 0;
	int utCPUA = 0;
	
	//interface de selection
	cout << endl << "Choix de Generation :" << endl;
	cout << "	1 : Generation Aleatoire" << endl;
	cout << "	2 : Generation Controlee" << endl;
	cout << "Selection : ";
	cin >> choix;
	
	if (choix == '1') {
		// Generation Aleatoire
		cout << endl << endl << "Nombre de Taches Periodiques: ";
		cin >> nbTachesP;
		if(nbTachesP == 0) {
			cout << "ATTENTION : l'application doit générer au moins une tache périodique" << endl;
			exit(0);
		}
		cout << "Pourcentage d'Utilisation du CPU (periodique): ";
		cin >> utCPUP;
		cout << endl << endl << "Nombre de Taches Aperiodiques: ";
		cin >> nbTachesA;
		if(nbTachesA != 0) {
			cout << "Pourcentage d'Utilisation du CPU (aperiodique): ";
			cin >> utCPUA;
		}
		else {
			utCPUA = 0;
		}
		
		GenerateurAleatoire genAl(nbTachesP,nbTachesA,utCPUP,utCPUA);
	}
	else if(choix == '2') {
		// Generation Controlee
		cout << endl << endl << "Nombre de Taches Periodiques: ";
		cin >> nbTachesP;
		if(nbTachesP == 0) {
			cout << "ATTENTION : l'application doit générer au moins une tache périodique" << endl;
			exit(0);
		}
		cout << endl << endl << "Nombre de Taches Aperiodiques: ";
		cin >> nbTachesA;
		GenerateurControlee genContr(nbTachesP,nbTachesA);
	}
	else {
		cout << "Erreur : choix non valide. \n(Rappel : 1 pour la génération aléatoire ou 2 pour la génération contrôlée)\n";
	}
}


