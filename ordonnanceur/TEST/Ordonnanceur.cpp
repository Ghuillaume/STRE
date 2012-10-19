#include "Ordonnanceur.h"

Ordonnanceur::Ordonnanceur(ConteneurTachePeriodique* conteneurPeriodique, ConteneurTacheAperiodique* conteneurAperiodique) : 
	conteneurPeriodique_(conteneurPeriodique), conteneurAperiodique_(conteneurAperiodique)	
{
	
}

Ordonnanceur::~Ordonnanceur() {

}

int Ordonnanceur::OrdonnancementRM() {
	
	TableauPrioritePeriodique tabPrioritePeriodique = this->getOrdrePrioPeriodique();
	//Tableau qui represente l'ordonnancement 
	// TabOrdo[i] = Tache qui s'execute a l'instant i
	vector<TachePeriodique*> tabOrdo(conteneurPeriodique_->getHyperPeriode());
	//Tableau qui contient le temps d'execution restant de chaque tache
	// rangé par ordre de priorité
	vector<int> tabTpsRestantExec(tabPrioritePeriodique.size());
	//initialisation du tableau du temps restant d'execution
	for(int i = 0 ; i < tabTpsRestantExec.size() ; i++) {
		tabTpsRestantExec[i] = tabPrioritePeriodique[i]->getCi();
	}
	
	//boucle d'ordonnancement
	for(int i = 0 ; i < tabOrdo.size() + 1 ; i++) {
		//vérification du reveil des taches 
		for(int t = 0 ; t < tabTpsRestantExec.size() ; t++) {
			if ( (i % (tabPrioritePeriodique[t]->getPi())) == 0 ) {
				if (i != 0) {
					if ( tabTpsRestantExec[t] != 0 ) {
						//depassement d'echeance
						cout << "Depassement d'echeance" << endl;
						cout << "Pour la Tache : " << tabPrioritePeriodique[t]->getNumTache() << endl;
						return 1;
					}
					else {
						tabTpsRestantExec[t] = tabPrioritePeriodique[t]->getCi();
					}
				}
			}
		}
		
		bool tachePlacee = false;
		int numTache = 0;
		
		while ( (!tachePlacee) && (numTache < tabTpsRestantExec.size()) ) {
			
			if (tabTpsRestantExec[numTache] == 0) {
				numTache++;
			}
			else
			{
				tabOrdo[i] = tabPrioritePeriodique[numTache];
				tabTpsRestantExec[numTache] -= 1;
				tachePlacee = true;
			}
		}
		if (numTache >= tabTpsRestantExec.size()) {
			// Temps Creux representer par une tache vide
			tabOrdo[i] = new TachePeriodique();
			
			
			//si BG : 
			for(int tA = 0 ; tA < conteneurAperiodique_.getize() ; tA++) {
				int Ri = conteneurAperiodique_->getTache(tA)->getri();
				if (i != 0) {
					if (Ri % i) {
						
		}
	}
	afficherOrdonnancement(tabOrdo);
	return 0;
}

int Ordonnanceur::OrdonnancementRM_BG() {
	
	/* TODO 
	Depassement de capacite 
	*/
	
	
	
	TableauPrioritePeriodique tabPrioritePeriodique = this->getOrdrePrioPeriodique();
	TableauPrioriteAperiodique tabPrioriteAperiodique = this->getOrdrePrioAperiodique();
	//Tableau qui represente l'ordonnancement 
	// TabOrdo[i] = numTache Tache qui s'execute a l'instant i
	vector<int> tabOrdo(conteneurPeriodique_->getHyperPeriode());
	//Tableau qui contient le temps d'execution restant de chaque tache
	// rangé par ordre de priorité
	vector<int> tabTpsRestantExecPeriodique(tabPrioritePeriodique.size());
	vector<int> tabTpsRestantExecAperiodique(tabPrioriteAperiodique.size());
	//initialisation du tableau du temps restant d'execution
	for(int i = 0 ; i < tabTpsRestantExecPeriodique.size() ; i++) {
		tabTpsRestantExecPeriodique[i] = tabPrioritePeriodique[i]->getCi();
	}
	
	for(int i = 0 ; i < tabTpsRestantExecAperiodique.size() ; i++) {
		tabTpsRestantExecAperiodique[i] = 0;
	}
	
	//boucle d'ordonnancement
	for(int i = 0 ; i < tabOrdo.size() + 1 ; i++) {
		//vérification du reveil des taches Periodiques
		for(int t = 0 ; t < tabTpsRestantExecPeriodique.size() ; t++) {
			if ( (i % (tabPrioritePeriodique[t]->getPi())) == 0 ) {
				if (i != 0) {
					if ( tabTpsRestantExecPeriodique[t] != 0 ) {
						//depassement d'echeance
						cout << "Depassement d'echeance" << endl;
						cout << "Pour la Tache : " << tabPrioritePeriodique[t]->getNumTache() << endl;
						return 1;
					}
					else {
						tabTpsRestantExecPeriodique[t] = tabPrioritePeriodique[t]->getCi();
					}
				}
			}
		}
		
		//vérification du reveil des taches Aperiodique
		for(int t = 0 ; t < tabTpsRestantExecAperiodique.size() ; t++) {
			if  ( (tabPrioriteAperiodique[t]->getri()) == i )  {
				if ( tabTpsRestantExecAperiodique[t] != 0 ) {
					//depassement d'echeance
					cout << "Depassement d'echeance" << endl;
					cout << "Pour la Tache : " << tabPrioriteAperiodique[t]->getNumTache()<< endl;
					return 1;
				}
				else {
					tabTpsRestantExecAperiodique[t] = tabPrioriteAperiodique[t]->getCi();
				}
			}
		}
		
		bool tachePeriodiquePlacee = false;
		int numTachePeriodique = 0;
		
		while ( (!tachePeriodiquePlacee) && (numTachePeriodique < tabTpsRestantExecPeriodique.size()) ) {
			
			if (tabTpsRestantExecPeriodique[numTachePeriodique] == 0) {
				numTachePeriodique++;
			}
			else
			{
				tabOrdo[i] = tabPrioritePeriodique[numTachePeriodique]->getNumTache();
				tabTpsRestantExecPeriodique[numTachePeriodique] -= 1;
				cout << "t=" << i << " : Tache T" << tabOrdo[i] << endl;
				tachePeriodiquePlacee = true;
			}
		}
		if (numTachePeriodique >= tabTpsRestantExecPeriodique.size()) {
			// Temps Creux --> Tache Aperiodique
			bool tacheAperiodiquePlacee = false;
			int numTacheAperiodique = 0;
			while ( (!tacheAperiodiquePlacee) && (numTacheAperiodique < tabTpsRestantExecAperiodique.size()) ) {
			
				if (tabTpsRestantExecAperiodique[numTacheAperiodique] == 0) {
					numTacheAperiodique++;
				}
				else
				{
					tabOrdo[i] = tabPrioriteAperiodique[numTacheAperiodique]->getNumTache();
					tabTpsRestantExecAperiodique[numTacheAperiodique] -= 1;
					cout << "t=" << i << " : Tache R" << tabOrdo[i] << endl;
					tacheAperiodiquePlacee = true;
				}
			}
			if (numTacheAperiodique >= tabTpsRestantExecAperiodique.size()) {
				//Temps Creux
				TachePeriodique* TempsCreux = new TachePeriodique();
				tabOrdo[i] = TempsCreux->getNumTache();
				cout << "t=" << i << " : Temps Creux" << endl;
			}
		}
	}
	//afficherOrdonnancement(tabOrdo);
	return 0;

}
	

void Ordonnanceur::OrdonnancementRM_BG() {
		
}

void Ordonnanceur::afficherOrdonnancement(vector<TachePeriodique*> tabOrdonnancement) {
	for(int i = 0 ; i < tabOrdonnancement.size() ; i++) {
		cout << "t=" << i << " : Tache" << tabOrdonnancement[i]->getNumTache() << endl;
	}
}
	
TableauPrioritePeriodique Ordonnanceur::getOrdrePrioPeriodique() {
	
	TableauPrioritePeriodique tabPrioPeriodique = conteneurPeriodique_->getTabTache();
	
	
    bool tab_en_ordre = false;
    int taille = tabPrioPeriodique.size();
    cout << "taille tab prio Periodique : " << taille << endl;
    while(!tab_en_ordre)
    {
        tab_en_ordre = true;
        for(int i=0 ; i < taille - 1 ; i++)
        {
            if(tabPrioPeriodique[i]->getPi() > tabPrioPeriodique[i+1]->getPi())
            {
                swap(tabPrioPeriodique[i],tabPrioPeriodique[i+1]);
                tab_en_ordre = false;
            }
        }
        taille--;
    }
    return tabPrioPeriodique;

}

TableauPrioriteAperiodique Ordonnanceur::getOrdrePrioAperiodique() {
	
	TableauPrioriteAperiodique tabPrioAperiodique = conteneurAperiodique_->getTabTache();
	
	
    bool tab_en_ordre = false;
    int taille = tabPrioAperiodique.size();
    cout << "taille tab prio Aperiodique : " << taille << endl;
    while(!tab_en_ordre)
    {
        tab_en_ordre = true;
        for(int i=0 ; i < taille - 1 ; i++)
        {
            if(tabPrioAperiodique[i]->getri() > tabPrioAperiodique[i+1]->getri())
            {
                swap(tabPrioAperiodique[i],tabPrioAperiodique[i+1]);
                tab_en_ordre = false;
            }
        }
        taille--;
    }
    return tabPrioAperiodique;

}

void Ordonnanceur::OrdonnancementEDF() {
/*
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
*/

}

void Ordonnanceur::verifierOrdonnancabilite(ConteneurTachePeriodique* conteneur) {
	double resultat = 0.0;
	
	verifierCondNecessaireRM(conteneur);
	verifierCondSuffisanteRM(conteneur);
	verifierConditionEDF(conteneur);
}

void Ordonnanceur::verifierCondNecessaireRM(ConteneurTachePeriodique* conteneur) {
	int Pi = 0;
	int Ci = 0;
	double Up = calculerUp(conteneur);
	
	cout << "Test de condition nécessaire pour RM : ";
	if (Up <= 1.0) {
		cout << "on ne peut rien conclure" << endl;
	} else {
		cout << "non-ordonnançable" << endl;
	}
}

void Ordonnanceur::verifierCondSuffisanteRM(ConteneurTachePeriodique* conteneur) {
	int Pi = 0;
	int Ci = 0;
	double Up = calculerUp(conteneur);
	double UBoundRM = calculerUBound(conteneur->getSize());
	
	cout << " Test de condition suffisante pour RM : ";
	if (Up <= UBoundRM) {
		cout << "ordonnançable" << endl;
	} else {
		cout << "on ne peut rien conclure" << endl;
	}
}


void Ordonnanceur::verifierConditionEDF(ConteneurTachePeriodique* conteneur) {
	bool egaliteDiPi = true;
	bool superioriteDiPi = true;
	int Pi = 0;
	int Di = 0;
	double Up = calculerUp(conteneur);

	for (int i = 0; i++; i < conteneur->getSize()) {
		Pi = conteneur->getTache(i)->getPi();
		Di = conteneur->getTache(i)->getDi();
		
		egaliteDiPi &= (Pi == Di);
		superioriteDiPi &= (Pi < Di);
	}
	
	if (egaliteDiPi) {
		cout << "Test de condition nécessaire et suffisante pour EDF : ";
		
		if (Up <= 1.0) {
			cout << "ordonnaçable" << endl;
		} else {
			cout << "non-ordonnançable" << endl;
		}
	}
	else if (superioriteDiPi) {
		cout << "Test de condition suffisante pour EDF : ";
		
		if (Up <= 1.0) {
			cout << "ordonnaçable" << endl;
		} else {
			cout << "on ne peut rien conclure" << endl;
		}
	}
}

double Ordonnanceur::calculerUp(ConteneurTachePeriodique* conteneur) {
	int Pi = 0;
	int Ci = 0;
	double Up = 0.0;

	// Somme de 1 à n des Ci/Pi
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
