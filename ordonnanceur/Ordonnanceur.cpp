#include "Ordonnanceur.hpp"

Ordonnanceur::Ordonnanceur(ConteneurTachePeriodique* conteneurPeriodique, ConteneurTacheAperiodique* conteneurAperiodique) : 
	conteneurPeriodique_(conteneurPeriodique), conteneurAperiodique_(conteneurAperiodique)	
{
	
}

Ordonnanceur::~Ordonnanceur() {

}

int Ordonnanceur::RM() {
	
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
						cout << "Pour la Tache : " << tabPrioritePeriodique[t]->getNum() << endl;
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
		}
	}
	afficherOrdonnancement(tabOrdo);
	return 0;
}

int Ordonnanceur::RM_BG() {
	
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
						cout << "Pour la Tache : " << tabPrioritePeriodique[t]->getNum() << endl;
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
					cout << "Pour la Tache : " << tabPrioriteAperiodique[t]->getNum()<< endl;
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
				tabOrdo[i] = tabPrioritePeriodique[numTachePeriodique]->getNum();
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
					tabOrdo[i] = tabPrioriteAperiodique[numTacheAperiodique]->getNum();
					tabTpsRestantExecAperiodique[numTacheAperiodique] -= 1;
					cout << "t=" << i << " : Tache R" << tabOrdo[i] << endl;
					tacheAperiodiquePlacee = true;
				}
			}
			if (numTacheAperiodique >= tabTpsRestantExecAperiodique.size()) {
				//Temps Creux
				TachePeriodique* TempsCreux = new TachePeriodique();
				tabOrdo[i] = TempsCreux->getNum();
				cout << "t=" << i << " : Temps Creux" << endl;
			}
		}
	}
	//afficherOrdonnancement(tabOrdo);
	return 0;

}

int Ordonnanceur::EDF(int serveur) {

	TabTachePeriodique tachesP = this->conteneurPeriodique_->getTabTache();
	int nbTachesP = tachesP.size();
	TabTacheAperiodique tachesA = this->conteneurAperiodique_->getTabTache();
	int nbTachesA = tachesA.size();
	int nbTaches = nbTachesP + nbTachesA;

	// Initialisation d'une matrice représentant le contexte d'exécution
	// [i]	temps d'exec restant		prochaine deadline		-> pour les tâches périodiques
	// [i]	temps d'exec restant		date de réveil			-> pour les tâches apériodiques
	int** context = new int* [ nbTaches ];
	for (int i = 0 ; i < nbTaches ; i++)
		context[i] = new int[ 2 ];
		
	// Parcours des tâches périodiques pour les mettre dans cette matrice
	for(int i = 0 ; i < nbTachesP ; i++) {
		context[i][0] = tachesP.at(i)->getCi();
		context[i][1] = tachesP.at(i)->getDi();	
	}
	
	// Parcours des tâches apériodiques pour les mettre dans la matrice
	for(int i = nbTachesP ; i < nbTaches ; i++) {
		context[i][0] = tachesA.at(i-nbTachesP)->getCi();
		context[i][1] = tachesA.at(i-nbTachesP)->getri();
	}
	
	
	
	//
	// Début de l'algorithme EDF
	//
	
	// Initialisation du temps courant et du numéro de la tâche en cours d'éxécution
	unsigned int t = 0;
	unsigned int task_executed; // -1 signifie qu'aucune tâche ne s'exécute
	bool need_to_poll;
	
	while( t < conteneurPeriodique_->getHyperPeriode() ) {
		
		// Affichage du contexte pour debuggage
		/*cout << "\t\tN\tExec\tDeadline" << endl;
		for(int i = 0 ; i < nbTaches ; i++)
			cout << "\t\tT" << i+1 << "\t" << context[i][0] << "\t" << context[i][1] << endl;*/
	
	
		// On vérifie si l'ordonnanceur doit élire une tâche (seulement si une tache se réveille ou se termine)
		// Une tache se réveille si t=0 (toutes les tâches se réveillent à t=0 dans le tp) ou si on est sur sa deadline
		// On sait qu'une tache se termine si son temps d'exec restant = 0
		need_to_poll = false;
		
		if(t == 0)
			need_to_poll = true;
			
		else if(task_executed != -1) {
			if(context[task_executed][0] == 0)
				need_to_poll = true;
		}
		
		else {
			for(int i = 0 ; i < nbTachesP ; i++) {
				if(context[i][1] == t) {
					need_to_poll = true;
					break;
				}
			}
		}
		
				
		
		// Recherche de la tache dont la prochaine deadline est la plus proche
		if(need_to_poll) {
		
			// réinitialisation de la tâche élue
			task_executed = -1;
			
			for(int i = 0 ; i < nbTachesP ; i++) {
		
				// On retient d'abord la première tâche qui n'a pas terminé son exécution
				if(task_executed == -1 && context[i][0] != 0)
					task_executed = i;
		
				// Ensuite, on cherche une tâche dont la deadline est plus proche (et dont l'exécution n'est pas terminée)
				if( context[i][0] != 0 && (context[i][1] < context[task_executed][1]) )
					task_executed = i;
	
			}
		}
		
		
		// Si on est sur du BG et qu'on a un temps creux, on essaie d'élire une tâche apériodique
		if(serveur == BG && task_executed == -1) {
			
			for(int i = nbTachesP ; i < nbTaches ; i++) {
				
				if(context[i][0] == 0) // Si la tâche a terminé son exécution, on passe à la suivante
					continue;
				else if(context[i][1] > t) // Si elle n'est pas encore réveillée, on passe à la suivante
					break;
				
				else {
					task_executed = i;
				
				}
				
			}
		}
		
		
		// Affichage
		// TODO : remplacer par une écriture fichier ou par un enregistrement mémoire du résultat
		if(task_executed == -1)
			cout << "t=" << t << " : temps creux" << endl;
		else if(task_executed >= nbTachesP)
			cout << "t=" << t << " : R" << (task_executed+1)%nbTachesP << endl;
		else
			cout << "t=" << t << " : T" << task_executed+1 << endl;

		
		// Mise à jour du contexte
		t++;
		
		if(task_executed != -1)
			context[task_executed][0]--;
			
		for(int i = 0 ; i < nbTachesP ; i++) {
		
			// Si la deadline de la tache a été passée, on charge en mémoire la deadline suivante
			if(context[i][1] < t) {
				context[i][1] += tachesP.at(i)->getDi();
				
				// Si, alors que la deadline a été passée, et que Ci n'est pas égal à zéro, alors le système n'est pas ordonnançable
				if(context[i][0] > 0) {
					cout << "ERREUR FATALE : la tâche T" << i << " n'a pas pu terminer son exécution. Arrêt du système" << endl;
					return 1;
				}
				else
					context[i][0] = tachesP.at(i)->getCi(); // réinitialisation du temps d'exécution restant
			} 
		}
		
	}
	
	return 0;

}

	

void Ordonnanceur::afficherOrdonnancement(vector<TachePeriodique*> tabOrdonnancement) {
	for(int i = 0 ; i < tabOrdonnancement.size() ; i++) {
		cout << "t=" << i << " : Tache" << tabOrdonnancement[i]->getNum() << endl;
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
void Ordonnanceur::verifierOrdonnancabilite(ConteneurTachePeriodique* conteneur) {
	double resultat = 0.0;
	
	verifierCondNecessaireRM(conteneur);
	verifierCondSuffisanteRM(conteneur);
	verifierConditionEDF(conteneur);
}

void Ordonnanceur::verifierCondNecessaireRM(ConteneurTachePeriodique* conteneur) {
	int Pi = 0;
	int Ci = 0;
	double Up = calculerU(conteneur);
	
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
	double Up = calculerU(conteneur);
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
	bool superioritePiDi = true;
	int Pi = 0;
	int Di = 0;
	double U = 0.0;

	for (int i = 0; i++; i < conteneur->getSize()) {
		Pi = conteneur->getTache(i)->getPi();
		Di = conteneur->getTache(i)->getDi();
		
		egaliteDiPi &= (Pi == Di);
		superioritePiDi &= (Pi > Di);
	}
	
	if (egaliteDiPi) {
		cout << "Test de condition nécessaire et suffisante pour EDF : ";
		U = calculerU(conteneur);
		
		if (U <= 1.0) {
			cout << "ordonnaçable" << endl;
		} else {
			cout << "non-ordonnançable" << endl;
		}
	}
	else if (superioritePiDi) {
		cout << "Test de condition suffisante pour EDF : ";
		U = calculerU2(conteneur);
		
		if (U <= 1.0) {
			cout << "ordonnaçable" << endl;
		} else {
			cout << "on ne peut rien conclure" << endl;
		}
	}
}

double Ordonnanceur::calculerU(ConteneurTachePeriodique* conteneur) {
	int Pi = 0;
	int Ci = 0;
	double Up = 0.0;

	// Somme de 1 à n des Ci/Pi
	for (int i = 0; i++; i < conteneur->getSize()) {
		Ci = conteneur->getTache(i)->getCi();
		Pi = conteneur->getTache(i)->getPi();
		Up += Ci/Pi;
	}
	return Up;
}

double Ordonnanceur::calculerU2(ConteneurTachePeriodique* conteneur) {
	int Di = 0;
	int Ci = 0;
	double Up = 0.0;

	// Somme de 1 à n des Ci/Di
	for (int i = 0; i++; i < conteneur->getSize()) {
		Ci = conteneur->getTache(i)->getCi();
		Di = conteneur->getTache(i)->getDi();
		Up += Ci/Di;
	}
	return Up;
}

double Ordonnanceur::calculerUBound(double n) {
	double puissance = pow(2.0, (1.0 / n));
	return n * (puissance - 1);
}
