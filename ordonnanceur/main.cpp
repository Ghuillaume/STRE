#include "common.h"

#include "Parseur.hpp"
#include "Traceur.hpp"

#include "Conteneur.hpp"
#include "TacheAperiodique.hpp"
#include "TachePeriodique.hpp"
#include "Ordonnanceur.hpp"

#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	string USAGE = "Usage : ./Ordonnanceur file.txt";
	
	/*
	if(argc != 1) {
		cout << USAGE << endl;
		return -1;
	}
	*/
	
	Conteneur* conteneur = new Conteneur();
	Traceur* traceur = new Traceur();
	Parseur* parser = new Parseur();
	
	parser->lireFichier(argv[1], conteneur);
	
	Ordonnanceur* ordo = new Ordonnanceur(conteneur,traceur);
	
	traceur->fermetureFichier();
	
	
	char action;
	bool sortir = false;
	while(!sortir) {
	
		cout << "\t\t************************************************" << endl;
		cout << "\t\t***** Simulateur d'ordonnanceur temps réel *****" << endl;
		cout << "\t\t************************************************" << endl << endl;
		cout << "\t0. Sortir" << endl;
		cout << "\t1. Afficher la liste des tâches" << endl;
		cout << "\t2. Analyser l'ordonnançabilité du système" << endl;
		cout << "\t3. Simuler l'ordonnancement sous RM (sans tâches apériodiques)" << endl;
		cout << "\t4. Simuler l'ordonnancement sous RM-BG" << endl;
		cout << "\t5. Simuler l'ordonnancement sous EDF (sans tâches apériodiques)" << endl;
		cout << "\t6. Simuler l'ordonnancement sous EDF-BG" << endl;
		cout << "\t7. Simuler l'ordonnancement sous EDF-TBS" << endl;
		cout << endl << "Selection : ";
	
		cin >> action;
		
		switch(action) {
			
			case '0':
				sortir = true;
				break;
				
			case '1':
				conteneur->toString();
				break;
				
			case '2':
				ordo->verifierCondNecessaireRM();
				ordo->verifierCondSuffisanteRM();
				ordo->verifierConditionEDF();
				break;
				
			case '3':
				ordo->RM(NO_SERV);
				break;
			
			case '4':
				ordo->RM(BG);
				break;
				
			case '5':
				ordo->EDF(NO_SERV);
				break;
				
			case '6':
				ordo->EDF(BG);
				break;
				
			case '7':
				// TODO pas de traitement si l'argument vaut TBS
				ordo->EDF(TBS);
				break;
		}
	
	}

}
