#include "Ordonnanceur.hpp"

Ordonnanceur::Ordonnanceur(Conteneur* conteneur, Traceur* traceur) : conteneur(conteneur), traceur(traceur) {
	
}

Ordonnanceur::~Ordonnanceur() {
	// TODO : Faire un vrai destructeur parce que là, bonjour les fuites mémoires :D 
}

int Ordonnanceur::RM(int serveur) {
	
	// initialisation du fichier de trace
	int hyperPeriode = this->conteneur->getHyperPeriode();
	this->traceur->entete(hyperPeriode);

	// Tableau qui contient les taches Periodiques rangées par Ordre de priorité
	ListeTachesPeriodiques tabPrioritePeriodique = this->ordonnerTachesPeriodiquesPi();
	// Tableau qui contient les taches Aperiodiques rangées par Ordre de priorité
	ListeTachesAperiodiques tabPrioriteAperiodique = this->ordonnerTachesAperiodiques();
	
	// Tableau qui contient le temps d'execution restant de chaque tache (periodique et aperiodique) rangé par ordre de priorité
	vector<int> tabTpsRestantExec(tabPrioritePeriodique.size() + tabPrioriteAperiodique.size());
	
	// initialisation du temps d'exécution restant aux taches periodiques
	// Ajout du nom de chaque tache dans l'entete du fichier de trace
	for(int i = 0 ; i < tabPrioritePeriodique.size() ; i++) {
		tabTpsRestantExec[i] = tabPrioritePeriodique[i]->getCi();
		this->traceur->declarationTache(i, tabPrioritePeriodique[i]->formatKTR());
	}
	
	// initialisation du temps d'exécution restant aux taches aperiodiques
	for(int i = tabPrioritePeriodique.size() ; i < tabPrioriteAperiodique.size() + tabPrioritePeriodique.size() ; i++) {
		tabTpsRestantExec[i] = tabPrioriteAperiodique[i-tabPrioritePeriodique.size()]->getCi();
	}		 
	
	// Ajout de la tache "BG" dans l'entete du fichier de trace
	if (serveur == BG) {
		this->traceur->declarationTache(tabPrioritePeriodique.size(),"BG");
	}

	//
	// Début de l'algorithme RM
	//
	
	// Initialisation du temps courant et du numéro de la tâche en cours d'éxécution
	unsigned int t = 0;
	unsigned int task_executed = -1; // -1 signifie qu'aucune tâche ne s'exécute
	
	bool need_to_poll;
	bool tacheElue = false;
	//numero de la tache representant l'execution des taches aperiodiques 
	// ce numero correspond a celui utilisé dans le fichier de trace
	unsigned int numTacheBG = tabPrioritePeriodique.size();
	unsigned int resteAperiodique_a_exec = 0;

	while(t < hyperPeriode) {	
		// On vérifie si l'ordonnanceur doit choisir une tâche
		// Seulement si une tâche se réveille ou se termine
		need_to_poll = false;
			
		if(task_executed != -1) {
			//Tache se termine
			if(tabTpsRestantExec[task_executed] == 0) {
				//si tache Aperiodique
				if(task_executed >= tabPrioritePeriodique.size()) {
					this->traceur->finExecution(t,numTacheBG);
					resteAperiodique_a_exec--;
					// a la fin de l'execution de la tache aperiodique la plus prioritaire
					// s'il y a encore des taches aperiodiques en attente
					// on simule un reveil sur le fichier de trace
					// pour pouvoir differencier l'exécution des differentes taches aperiodiques
					if(resteAperiodique_a_exec != 0) {
						this->traceur->reveil(t, numTacheBG);
					}
				}
				else {
					this->traceur->finExecution(t,task_executed);
				}
				need_to_poll = true;
			}
		}
		
		//Verification du reveil d'une tache Periodique
		for(int i = 0 ; i < tabPrioritePeriodique.size() ; i++) {
			if((t % tabPrioritePeriodique[i]->getPi()) == 0) {// correspond au réveil d'une tâche périodique
				if (t != 0) {
					this->traceur->dateEcheance(t,i);
				}
				this->traceur->reveil(t,i);
				need_to_poll = true;
			}
		}
	
		// Election de la tâche la plus prioritaire
		if(need_to_poll) {
			
			tacheElue = false;
			for(int i = 0 ; i < tabPrioritePeriodique.size() ; i++) {
				// On retient la première tâche qui n'a pas terminé son exécution
				if(!tacheElue && tabTpsRestantExec[i] != 0) {
					if(t==0) {
						task_executed = i;
						this->traceur->execution(t,task_executed);
					}
					//verification si la tache en cours d'execution est préemptée
					if(task_executed != i) {
						if(task_executed == -1) {
							this->traceur->execution(t,i);
						}
						else {
							if(tabTpsRestantExec[task_executed] != 0) {
								//preemption
								if(task_executed >= tabPrioritePeriodique.size()) {
									this->traceur->preemption(t,numTacheBG);
								}
								else {
									this->traceur->preemption(t,task_executed);
								}
								this->traceur->execution(t,i);
							}
							else {
								this->traceur->execution(t,i);
							}
						}
						task_executed = i;
					}
				tacheElue = true;
				}
			}
			if (tacheElue == false) {
				//Temps Creux
				task_executed = -1;
			}
			
		}
		
		if(serveur == BG) {
			//test si une tache aperiodique se reveille
			for(int i = 0 ; i < tabPrioriteAperiodique.size() ; i++) {
				if (tabPrioriteAperiodique[i]->getri() == t) {
					//reveil de tache aperiodique
					if(resteAperiodique_a_exec != 0) {
						this->traceur->reveilAperiodiqueAttente(t,tabPrioriteAperiodique[i]->getCi(),numTacheBG);
						resteAperiodique_a_exec++;
					}
					else {
						this->traceur->reveilAperiodiqueExec(t,tabPrioriteAperiodique[i]->getCi(),numTacheBG);
						resteAperiodique_a_exec++;
					}	
				}
			}
		}
		// Si on est sur du BG et qu'on a un temps creux, on essaie d'élire une tâche apériodique
		if(serveur == BG && task_executed == -1) {
		
			for(int i = 0 ; i < tabPrioriteAperiodique.size() ; i++) {
			
				// Si la tâche n'a pas terminé son exécution et si elle est réveillée, on la choisie
				if( (tabTpsRestantExec[i+tabPrioritePeriodique.size()] > 0) && (tabPrioriteAperiodique[i]->getri() <= t) ) {
					// On ajoute le nombre de taches périodiques pour différencier périodiques et apériodiques
					task_executed = i + tabPrioritePeriodique.size();
					this->traceur->execution(t,numTacheBG);
					break;
				}
			}
		}
		
		
		// Affichage
		if(task_executed == -1) {
			cout << "t=" << t << " : temps creux" << endl;
		}
		else if(task_executed >= tabPrioritePeriodique.size()) {
			cout << "t=" << t << " : R" << tabPrioriteAperiodique[task_executed-tabPrioritePeriodique.size()]->getNum() << endl;
			tabTpsRestantExec[task_executed]--;
		}
		else {
			cout << "t=" << t << " : T" << tabPrioritePeriodique[task_executed]->getNum() << endl;
			tabTpsRestantExec[task_executed]--;
		}
	
		
		// Mise à jour du contexte d'exécution
		t++;
		
		for(int i = 0 ; i < tabPrioritePeriodique.size() ; i++) {
			if(t % (tabPrioritePeriodique[i]->getDi()) == 0 && t != 0) {
				if(tabTpsRestantExec[i] > 0) {
					cout << "ERREUR FATALE : la tâche T" << tabPrioritePeriodique[i]->getNum() << " n'a pas pu terminer son exécution. Arrêt du système" << endl;
					return 1;
				}
				else
					tabTpsRestantExec[i] = tabPrioritePeriodique[i]->getCi();
			}
		}
	}
	return 0;
}

int Ordonnanceur::EDF(int serveur, int bandePassanteTBS) {
	
	int hyperPeriode = this->conteneur->getHyperPeriode();
	this->traceur->entete(hyperPeriode);

	ListeTachesPeriodiques tachesP = *this->conteneur->getVectorPeriodique();
	int nbTachesP = tachesP.size();
	ListeTachesAperiodiques tachesA = this->ordonnerTachesAperiodiques();
	int nbTachesA = tachesA.size();
	int nbTaches = nbTachesP + nbTachesA;
	unsigned int numTacheA = nbTachesP;

	// Initialisation d'une matrice représentant le contexte d'exécution
	// [i]	temps d'exec restant		prochaine deadline		-> pour les tâches périodiques
	// [i]	temps d'exec restant		date de réveil			-> pour les tâches apériodiques
	int** context = new int* [ nbTaches ];
	for (int i = 0 ; i < nbTaches ; i++){
		context[i] = new int[ 3 ];
	}

		
	// Parcours des tâches périodiques pour les mettre dans cette matrice
	for(int i = 0 ; i < nbTachesP ; i++) {
		context[i][0] = tachesP.at(i)->getCi();
		context[i][1] = tachesP.at(i)->getDi();	
		context[i][2] = tachesP.at(i)->getPi();
		this->traceur->declarationTache(i, tachesP[i]->formatKTR());
	}
	
	if(serveur != NO_SERV) {
		if (serveur == BG) {
			this->traceur->declarationTache(numTacheA,"BG");
		}
		else {
			this->traceur->declarationTache(numTacheA,"TBS");
		}
		// TODO : classer les tâches apériodique par ordre de Ri
		// Parcours des tâches apériodiques pour les mettre dans la matrice
		for(int i = nbTachesP ; i < nbTaches ; i++) {
			context[i][0] = tachesA.at(i-nbTachesP)->getCi();
			context[i][1] = tachesA.at(i-nbTachesP)->getri();
			//di
			context[i][2] = 0;
		}
	}
	
	//
	// Début de l'algorithme EDF
	//
	
	// Initialisation du temps courant et du numéro de la tâche en cours d'éxécution
	unsigned int t = 0;
	unsigned int task_executed = -1; // -1 signifie qu'aucune tâche ne s'exécute
	bool need_to_poll;
	int deadlineProche = 0;
	ListeTachesPretes tabTachesPretes(0);
	queue<int> tabTachesApPretes;
	int former_executedTask = task_executed;
	int dk = 0;
	int UTC = 0;
	int totalUTC = 0;
	
	while( t < hyperPeriode ) {
	
		// Affichage du contexte pour debuggage
		/*cout << "\t\tN\tExec\tDeadline" << endl;
		for(int i = 0 ; i < nbTaches ; i++)
			cout << "\t\tT" << i+1 << "\t" << context[i][0] << "\t" << context[i][1] << endl;*/
		
		// On vérifie si l'ordonnanceur doit élire une tâche (seulement si une tache se réveille ou se termine)
		// Une tache se réveille si t=0 (toutes les tâches se réveillent à t=0 dans le tp) ou si on est sur sa deadline
		// On sait qu'une tache se termine si son temps d'exec restant = 0
		need_to_poll = false;
		
		if(t == 0) {
			need_to_poll = true;
		}
		
		if(task_executed != -1) {
			//Tache se termine
			if(context[task_executed][0] == 0) {
				//si tache Aperiodique
				if(task_executed >= nbTachesP) {
					this->traceur->finExecution(t,numTacheA);
					tabTachesApPretes.pop();
					// a la fin de l'execution de la tache aperiodique la plus prioritaire
					// s'il y a encore des taches aperiodiques en attente
					// on simule un reveil sur le fichier de trace
					// pour pouvoir differencier l'exécution des differentes taches aperiodiques
					if(tabTachesApPretes.size() != 0) {
						this->traceur->reveil(t, numTacheA);
					}
				}
				else {
					this->traceur->finExecution(t,task_executed);
					for(int i = 0 ; i < tabTachesPretes.size() ; i++) {
						if(tabTachesPretes[i] == task_executed) {
							tabTachesPretes.erase(tabTachesPretes.begin() + i);
						}
					}
				}
				need_to_poll = true;	
			}
		}
		
		//Verification du reveil d'une tache Periodique
		//remplissage du tableau des tâches prêtes
		for(int i = 0 ; i < nbTachesP ; i++) {
			 
			int ri = context[i][2] - tachesP[i]->getPi();
			if(ri == t) {// correspond au réveil d'une tâche périodique
				this->traceur->reveil(t,i);
				need_to_poll = true;
				tabTachesPretes.push_back(i);
			}
		}
		
		//Verification du reveil d'une tache Aperiodique
		// remplissage du tableau des tâches prêtes
		if ( serveur != NO_SERV ) {
			for (int i = nbTachesP ; i < nbTaches ; i++) {
				if(context[i][1] == t) {
					//reveil de tache Aperiodique
					if(tabTachesApPretes.size() == 0) {
						this->traceur->reveilAperiodiqueExec(t,context[i][0],numTacheA);
					}
					else {
					 	this->traceur->reveilAperiodiqueAttente(t,context[i][0],numTacheA);
					}
					tabTachesApPretes.push(i);
					//calcul dk
					if(bandePassanteTBS != 0) {
						int division = ((context[i][0])*100)/bandePassanteTBS; 
						dk = max(context[i][1],dk) + division;
						cout << "dk de " << i << " : "<< dk << endl;
						context[i][2] = dk;
					}
				}
			}
		}
		
		// Election de la tâche la plus prioritaire
		if(need_to_poll) {
			if(tabTachesPretes.size() == 0) {
				if(tabTachesApPretes.size() == 0) {
					//pas de taches pretes -> temps creux
					task_executed = -1;
				}
				else {
					task_executed = tabTachesApPretes.front();
				}
			}
			else {
				deadlineProche = context[tabTachesPretes[0]][1];
				task_executed = tabTachesPretes[0];
				if(tabTachesPretes.size() != 1) {
					for(int i = 1 ; i < tabTachesPretes.size() ; i++) {
						if(context[tabTachesPretes[i]][1] < deadlineProche) {
							deadlineProche = context[tabTachesPretes[i]][1];
							task_executed = tabTachesPretes[i];
						}
						else if(context[tabTachesPretes[i]][1] == deadlineProche) {
							
							int  riP = context[tabTachesPretes[i]][2] - tachesP[tabTachesPretes[i]]->getPi();
							int ritask_executed = context[task_executed][2] - tachesP[task_executed]->getPi();
							if(riP < ritask_executed) {
								task_executed = tabTachesPretes[i];
							}
							else if (riP == ritask_executed) {
								if(tabTachesPretes[i] < task_executed) {
									task_executed = tabTachesPretes[i];
								}
							}
						}
					}
				}
				if(serveur == TBS) {
					if(tabTachesApPretes.size() != 0) {
						if(context[tabTachesApPretes.front()][2] < deadlineProche) {
							//la tache aperiodique est plus prio
							task_executed = tabTachesApPretes.front();
						}
						else if (context[tabTachesApPretes.front()][2] == deadlineProche) {
							int ritask_executed = context[task_executed][2] - tachesP[task_executed]->getPi();
							if(context[tabTachesApPretes.front()][1] < ritask_executed) {
								task_executed = tabTachesApPretes.front();
							}
						}
					}
				}
						
			}
			
			if(former_executedTask != task_executed) {
				if(former_executedTask == -1) {
					if(task_executed >= nbTachesP) {
						this->traceur->execution(t,numTacheA);
					}
					else {
						this->traceur->execution(t,task_executed);
					}
				totalUTC = totalUTC + (t - UTC);
				UTC = 0;
				}
				else {
					if(task_executed != -1) {
						if(context[former_executedTask][0] != 0) {
							//preemption
							if(former_executedTask >= nbTachesP) {
								//tache Aperiodique
								this->traceur->preemption(t,numTacheA);
							}
							else {
								this->traceur->preemption(t,former_executedTask);
							}
						}
						if(task_executed >= nbTachesP) {
							this->traceur->execution(t,numTacheA);
						}
						else {
							this->traceur->execution(t,task_executed);
						}		
					}
					else {
						UTC = t;
					}
				}
			}
		}
		
		former_executedTask = task_executed;
		
		// Affichage
		if(task_executed == -1)
			cout << "t=" << t << " : temps creux" << endl;
		else if(task_executed >= nbTachesP)
			cout << "t=" << t << " : R" << tachesA[(task_executed+1)-nbTachesP-1]->getNum() << endl;
		else
			cout << "t=" << t << " : T" << tachesP[task_executed]->getNum() << endl;

		// Mise à jour du contexte
		t++;	
		
		if(task_executed != -1)
			context[task_executed][0]--;
			
		for(int i = 0 ; i < nbTachesP ; i++) {
		
			// Si la deadline de la tache a été passée, on charge en mémoire la deadline suivante
			if(context[i][1] == t) {
			// Si, alors que la deadline a été passée, et que Ci n'est pas égal à zéro, alors le système n'est pas ordonnançable
				if(context[i][0] > 0) {
					cout << "ERREUR FATALE : la tâche T" << i << " n'a pas pu terminer son exécution. Arrêt du système" << endl;
					return 1;
				}
				this->traceur->dateEcheance(t,i);
			} 
			if(context[i][2] == t) {
				context[i][0] = tachesP.at(i)->getCi(); // réinitialisation du temps d'exécution restant
				context[i][1] = t + tachesP.at(i)->getDi();
				context[i][2] = t + tachesP.at(i)->getPi();		
			}
		}
		
		if(serveur == TBS) {
			for(int i = nbTachesP ; i < nbTaches ; i++) {
		
				// Si la deadline de la tache a été passée, on charge en mémoire la deadline suivante
				if(context[i][2] == t) {
				// Si, alors que la deadline a été passée, et que Ci n'est pas égal à zéro, alors le système n'est pas ordonnançable
					if(context[i][0] > 0) {
						cout << "ERREUR FATALE : la tâche R" << i << " n'a pas pu terminer son exécution. Arrêt du système" << endl;
						return 1;
					}
					this->traceur->dateEcheance(t,numTacheA);
				}
			}
		}	
	}
	
	if(task_executed != -1) {
		if(task_executed >= nbTachesP) {
			this->traceur->finExecution(t,numTacheA);
		}
		else {
			this->traceur->finExecution(t,task_executed);
		}
	}
	else {
		totalUTC = totalUTC + (t - UTC);
	}
	cout << "UTC total: " << totalUTC << endl;
	return 0;
}
	
ListeTachesPeriodiques Ordonnanceur::ordonnerTachesPeriodiquesPi() {
	
	ListeTachesPeriodiques tabPrioPeriodique = *this->conteneur->getVectorPeriodique();
	
    bool tab_en_ordre = false;
    int taille = tabPrioPeriodique.size();
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

ListeTachesAperiodiques Ordonnanceur::ordonnerTachesAperiodiques() {
	
	ListeTachesAperiodiques tabPrioAperiodique = *this->conteneur->getVectorAperiodique();
	
	
    bool tab_en_ordre = false;
    int taille = tabPrioAperiodique.size();
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


void Ordonnanceur::verifierCondNecessaireRM() {
	int Pi = 0;
	int Ci = 0;
	double Up = calculerU();
	
	cout << "Test de condition nécessaire pour RM : ";
	if (Up <= 1.0) {
		cout << "on ne peut rien conclure" << endl;
	} else {
		cout << "non-ordonnançable" << endl;
	}
}

void Ordonnanceur::verifierCondSuffisanteRM() {
	int Pi = 0;
	int Ci = 0;
	double Up = calculerU();
	
	double UBoundRM = calculerUBound();
	
	cout << "Test de condition suffisante pour RM : ";
	if (Up <= UBoundRM) {
		cout << "ordonnançable" << endl;
	} else {
		cout << "on ne peut rien conclure" << endl;
	}
}


void Ordonnanceur::verifierConditionEDF() {
	bool egaliteDiPi = true;
	bool superioritePiDi = true;
	int Pi = 0;
	int Di = 0;
	double U = 0.0;
	ListeTachesPeriodiques* liste = this->conteneur->getVectorPeriodique();

	// Somme de 1 à n des Ci/Pi
	for (int i = 0; i++; i < liste->size()) {
		Pi = liste->at(i)->getPi();
		Di = liste->at(i)->getDi();
		
		egaliteDiPi &= (Pi == Di);
		superioritePiDi &= (Pi > Di);
	}
	
	if (egaliteDiPi) {
		cout << "Test de condition nécessaire et suffisante pour EDF : ";
		U = calculerU();
		
		if (U <= 1.0) {
			cout << "ordonnançable" << endl;
		} else {
			cout << "non-ordonnançable" << endl;
		}
	}
	else if (superioritePiDi) {
		cout << "Test de condition suffisante pour EDF : ";
		U = calculerU2();
		
		if (U <= 1.0) {
			cout << "ordonnançable" << endl;
		} else {
			cout << "on ne peut rien conclure" << endl;
		}
	}
}

void Ordonnanceur::verifierConditionEDF_TBS(double Us) {
	double Up = calculerU();
	
	cout << "Test de condition nécessaire et suffisante pour EDF-TBS : ";
	if (Up + Us <= 1.0) {
		cout << "ordonnançable" << endl;
	} else {
		cout << "non-ordonnançable" << endl;
	}
}

double Ordonnanceur::calculerU() {
	int Pi = 0;
	int Ci = 0;
	double Up = 0.0;
	ListeTachesPeriodiques* liste = this->conteneur->getVectorPeriodique();

	// Somme de 1 à n des Ci/Pi
	for (int i = 0; i++; i < liste->size()) {
		Ci = liste->at(i)->getCi();
		Pi = liste->at(i)->getPi();
		Up += Ci/Pi;
	}
	return Up;
}

double Ordonnanceur::calculerU2() {
	int Di = 0;
	int Ci = 0;
	double Up = 0.0;
	ListeTachesPeriodiques* liste = this->conteneur->getVectorPeriodique();
	
	// Somme de 1 à n des Ci/Di
	for (int i = 0; i++; i < liste->size()) {
		Ci = liste->at(i)->getCi();
		Di = liste->at(i)->getDi();
		Up += Ci/Di;
	}
	return Up;
}

double Ordonnanceur::calculerUBound() {
	double n = (double) this->conteneur->getVectorPeriodique()->size();
	double puissance = pow(2.0, (1.0 / n));
	return n * (puissance - 1);
}
