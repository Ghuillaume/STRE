#include "Ordonnanceur.h"

Ordonnanceur::Ordonnanceur() {

}

Ordonnanceur::~Ordonnanceur() {

}

void Ordonnanceur::OrdonnancementRM(ConteneurTachePeriodique* conteneur) {
	vector<int> tabPrio(conteneur->getSize());
	vector<int> tabOrdo(conteneur->getHyperPeriode());
	cout << "TabPrio ";
	for(int i = 0 ; i < conteneur->getSize() ; i++) {
		tabPrio[i] = conteneur->getTache(i)->getCi();
		cout << i << " " << tabPrio[i] << endl;
	}
	
	for(int i = 0 ; i < conteneur->getHyperPeriode() ; i++) {
		// Verification que la tache ne s'est pas reveillée
		for(int t = 0 ; t < conteneur->getSize() ; t++) {
			if ((i%(conteneur->getTache(t)->getPi())) == 0) {
				//reveil
				tabPrio[t] = conteneur->getTache(t)->getCi();
			}
		}
		bool sortir = false;
		int t = 0;
		
		while ((sortir==false) && (t<conteneur->getSize())) {
			if (tabPrio[t] = 0) {
				t++;
			}
			else {
				sortir = true;
			}
		}
		if (sortir == true) {
			tabOrdo[i] = t + 1;
			tabPrio[t] = tabPrio[t] - 1;
		}
	}
	
	for(int i = 0 ; i < tabOrdo.size() ; i++) {
		cout << "t=" << i << " : Tache" << tabOrdo[i] << endl;
	}	

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
}

void Ordonnanceur::verifierOrdonnancabilite(ConteneurTachePeriodique* conteneur) {
	double resultat = 0.0;
	
	verifierCondNecessaireRM(conteneur);
	verifierCondSuffisanteRM(conteneur);
}

void Ordonnanceur::verifierCondNecessaireRM(ConteneurTachePeriodique* conteneur) {
	int Pi = 0;
	int Ci = 0;
	double Up = calculerUp(conteneur);
	
	if (Up <= 1.0) {
		cout << "Condition nécessaire pour RM : on ne peut rien conclure" << endl;
	} else {
		cout << "Pas de condition nécessaire pour RM : non-ordonnançable" << endl;
	}
}

void Ordonnanceur::verifierCondSuffisanteRM(ConteneurTachePeriodique* conteneur) {
	int Pi = 0;
	int Ci = 0;
	double Up = calculerUp(conteneur);
	double UBoundRM = calculerUBound(conteneur->getSize());
	
	if (Up <= UBoundRM) {
		cout << " Test suffisant : ce sera bien ordonnançable" << endl;
	} else {
		cout << "Test suffisant : on ne peut rien conclure" << endl;
	}
}

double Ordonnanceur::calculerUp(ConteneurTachePeriodique* conteneur) {
	int Pi = 0;
	int Ci = 0;
	double Up = 0.0;

	for (int i = 0; i++; i < conteneur->getSize()) {
		Pi = conteneur->getTache(i)->getPi();
		Ci = conteneur->getTache(i)->getCi();
		Up += Pi/Ci;
	}
	return Up;
}

double Ordonnanceur::calculerUBound(double n) {
	double puissance = pow(2.0, (1.0 / n));
	return n * (puissance - 1);
}
