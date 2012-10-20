#include "common.h"

#include "Parseur.h"

#include "TacheAperiodique.h"
#include "TachePeriodique.h"
#include "Ordonnanceur.h"

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
	/*	
	Parseur* parse = new Parseur(argv[0],contAper,contPer);
	parse->lireFichier();
	*/
	
	// A la place, on ajoute manuellement pour l'instant
		ConteneurTachePeriodique* contPer = new ConteneurTachePeriodique();
		ConteneurTacheAperiodique* contAper = new ConteneurTacheAperiodique();

		// ajout Tache Periodique 
		TachePeriodique* tacheP2 = new TachePeriodique(2,8,8,2);
		TachePeriodique* tacheP1 = new TachePeriodique(2,6,6,1);
		TachePeriodique* tacheP3 = new TachePeriodique(2,12,12,3);
		contPer->ajouterTachePeriodique(tacheP1);
		contPer->ajouterTachePeriodique(tacheP2);
		contPer->ajouterTachePeriodique(tacheP3);
	
		// ajout Tache Aperiodique
		TacheAperiodique* tacheA = new TacheAperiodique(1,3,1);
		TacheAperiodique* tacheB = new TacheAperiodique(22,3,2);
		contAper->ajouterTacheAperiodique(tacheA);
		contAper->ajouterTacheAperiodique(tacheB);
		
		
	Ordonnanceur* ordo = new Ordonnanceur(contPer,contAper);
	
	char action;
	bool sortir = false;
	while(!sortir) {
	
		cout << "\t\t************************************************" << endl;
		cout << "\t\t***** Simulateur d'ordonnanceur temps réel *****" << endl;
		cout << "\t\t************************************************" << endl << endl;
		cout << "\t0. Sortir" << endl;
		cout << "\t1. Analyser l'ordonnançabilité du système" << endl;
		cout << "\t2. Simuler l'ordonnancement sous RM-BG" << endl;
		cout << "\t3. Simuler l'ordonnancement sous RM-TBS" << endl;
		cout << "\t4. Simuler l'ordonnancement sous EDF-BG" << endl;
		cout << "\t5. Simuler l'ordonnancement sous EDF-TBS" << endl;
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
				ordo->RM_BG();
				break;
			
			case '3':
				// TODO RM-TBS
				break;
				
			case '4':
				ordo->EDF(BG);
				break;
				
			case '5':
				// TODO pas de traitement si l'argument vaut TBS
				ordo->EDF(TBS);
				break;
		}
	
	}

}
