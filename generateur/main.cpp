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
/*	else if (argc == 3) {
		string arg1 = argv[1];
		string arg2 = argv[2];
		
		if (arg1.compare("-f") == 0) {
			//fichier en entrée : rien a faire 
			FILE * pFile;
			pFile = fopen (argv[2] , "r");
			if (pFile == NULL){
				string error_msg = "Erreur lors de l'ouverture du fichier \""
				  + arg2 + "\". Peut-être n'existe-il pas ?";
				  cout << error_msg << endl;
			} 
			else {
				fclose (pFile);
				cout << "Nothing to do." << endl;
				exit(0);
			}
		}
		else if (arg1.compare("-c") == 0) {
			//generation Controlee
			GenerateurControlee genCtr(atoi(arg2.c_str()),);
		}
		
		else {
			cout << "Arguments incorrects.\n" << USAGE << endl;
		}
	}	
	else if (argc == 4) {
		string arg1 = argv[1];
		string arg2 = argv[2];
		string arg3 = argv[3];
		
		if (arg1.compare("-a") == 0) {
			GenerateurAleatoire genAlea(atoi(arg2.c_str()),atoi(arg3.c_str()));
		}
		else 
			cout << "Arguments incorrects.\n" << USAGE << endl;
	}*/		
	else
		cout << "Arguments incorrects.\n" << USAGE << endl;
}


