#include "common.h"

#include "Parseur.hpp"

#include "Conteneur.hpp"
#include "TacheAperiodique.hpp"
#include "TachePeriodique.hpp"
#include "Ordonnanceur.hpp"

#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	string USAGE = "Usage : ./Ordonnanceur [fichier.txt]";
	
	/*
	if(argc != 1) {
		cout << USAGE << endl;
		return -1;
	}
	*/
	
	// TODO : parser le fichier reçu en entrée (ligne de commande)

		Conteneur* conteneur = new Conteneur();

		// ajout Tache Periodique 
		conteneur->addTacheP(2,2,8,8);
		conteneur->addTacheP(1,2,6,6);
		conteneur->addTacheP(3,2,12,12);
	
		// ajout Tache Aperiodique
		conteneur->addTacheA(1,1,3);
		conteneur->addTacheA(2,22,3);

		
	Ordonnanceur* ordo = new Ordonnanceur(conteneur);
	ordo->verifierCondNecessaireRM();
	ordo->verifierCondSuffisanteRM();
	ordo->verifierConditionEDF();
	ordo->RM();
	
	/*
	char action;
	bool sortir = false;
	while(!sortir) {
	
		cout << "\t\t************************************************" << endl;
		cout << "\t\t***** Simulateur d'ordonnanceur temps réel *****" << endl;
		cout << "\t\t************************************************" << endl << endl;
		cout << "\t0. Sortir" << endl;
		cout << "\t1. Analyser l'ordonnançabilité du système" << endl;
		cout << "\t2. Simuler l'ordonnancement sous RM (sans tâches apériodiques)" << endl;
		cout << "\t3. Simuler l'ordonnancement sous RM-BG" << endl;
		cout << "\t4. Simuler l'ordonnancement sous EDF (sans tâches apériodiques)" << endl;
		cout << "\t5. Simuler l'ordonnancement sous EDF-BG" << endl;
		cout << "\t6. Simuler l'ordonnancement sous EDF-TBS" << endl;
		cout << endl << "Selection : ";
	
		cin >> action;
		
		switch(action) {
			
			case '0':
				sortir = true;
				break;
				
			case '1':
				//ordo->verifierOrdonnancabilite();
				break;
				
			case '2':
				ordo->RM();
				break;
			
			case '3':
				ordo->RM_BG();
				break;
				
			case '4':
				ordo->EDF(NO_SERV);
				break;
				
			case '5':
				ordo->EDF(BG);
				break;
				
			case '6':
				// TODO pas de traitement si l'argument vaut TBS
				ordo->EDF(TBS);
				break;
		}
	
	}
*/
}
