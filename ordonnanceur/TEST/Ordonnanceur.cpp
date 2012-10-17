#include "Ordonnanceur.h"

Ordonnanceur::Ordonnanceur() {

}

Ordonnanceur::~Ordonnanceur() {

}

void Ordonnanceur::OrdonnancementRM(ConteneurTachePeriodique* conteneur) {
	

}

void Ordonnanceur::OrdonnancementEDF(ConteneurTachePeriodique* conteneur) {

	TabTachePeriodique vector = conteneur.getVector();

	int elected, timeAllocated;

	int nbTaches = conteneur.size();

	// Initialisation d'une matrice 
	// [i]	temps d'exec restant		prochaine deadline		Pi		Ci
	taches = new int* [ nbTaches ];
	for (int i = 0 ; i < nbTaches ; i++)
		taches[i] = new int[ 2 ];
		
	// Parcours des tâches pour les mettre dans cette matrice
	for(int i = 0 ; i < vector.size() ; i++) {
		taches[i][0] = vector.at(i).getCi();
		taches[i][1] = vector.at(i).getDi();	
	}
	
	// Initialisation du temps courant
	unsigned int t_cur = 0;
	
	
	//
	// Début de l'algorithme EDF
	//
	
	while( t_cur < conteneur.getHyperPeriode() ) {
	
		// Recherche de la tache dont la prochaine deadline est la plus proche
		elected = 0;
		for(int i = 1 ; i < nbTaches ; i++) {
		
			// Si la tâche i a encore du temps d'execution, et si sa deadline est plus proche que celle de la tache i-1, alors on la retient
			if(taches[i][0] != 0 && (taches[i][1] < taches[i-1][1]) )
				elected = i;
	
		}
		// A ce stade, c'est la tâche n°t qui est prioritaire
	
		// Calcul du temps d'exec alloué (min entre le temps d'exécution restant, le temps restant avant la deadline,  et le prochain réveil de tâche)
		int timeAllocated = taches[t][0];
		if( (taches[elected][1] - t_cur) < timeAllocated)
			timeAllocated = (taches[elected][1] - t_cur);
		
	
		t_cur += timeAllocated;	
	
	
		// le temps courant a changé, il faut modifier les valeurs de la matrice (il se peut qu'il y ait de nouvelles deadlines)
		for(int i = 0 ; i < nbTaches ; i++) {
		
			// Si la deadline de la tache a été passée, on charge en mémoire la deadline suivante
			if(taches[i][1] < t_cur) {
				taches[i][1] += vector.at(i).getDi();
			
				// Si, alors que la deadline a été passée, et que Ci n'est pas égal à zéro, alors le système n'est pas ordonnançable
				if(taches[i][0] > 0) {
					cout << "ERREUR FATALE :  la tâche T" << i << " n'a pas pu terminer son exécution. Arrêt du système" << endl;
					return -1;
				}
				else
					taches[i][0] = vector.at(i).getCi(); // réinitialisation du temps d'exécution restant
					
		}
			
	}

}
