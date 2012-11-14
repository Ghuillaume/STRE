/*******************************************************
Nom ......... : main.cpp
Role ........ : fonction principale du générateur
Auteur ...... : BONCORPS, CHARON, PAGES 
********************************************************/

#include "GenerateurAleatoire.h"
#include "GenerateurControlee.h"

using namespace std;
int main(int argc, char** argv) {
	string USAGE = "./Generateur [-f fichier.txt|-c nbTaches|-a nbTaches utilisationCPU]";
	// Vérification du nombre d'arguments
	
	if (argc == 1) {
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
			cout << "Pourcentage d'Utilisation du CPU (periodique): ";
			cin >> utCPUP;
			cout << endl << endl << "Nombre de Taches Aperiodiques: ";
			cin >> nbTachesA;
			cout << "Pourcentage d'Utilisation du CPU (aperiodique): ";
			cin >> utCPUA;
			
			GenerateurAleatoire genAl(nbTachesP,nbTachesA,utCPUP,utCPUA);
		}
		else if(choix == '2') {
			// Generation Controlee
			cout << endl << endl << "Nombre de Taches Periodiques: ";
			cin >> nbTachesP;
			cout << endl << endl << "Nombre de Taches Aperiodiques: ";
			cin >> nbTachesA;
			GenerateurControlee genContr(nbTachesP,nbTachesA);
		}
		else {
			cout << "erreur";
		}
	}	
	else
		cout << "Arguments incorrects.\n" << USAGE << endl;
}


