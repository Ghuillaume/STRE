#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "common.h"

#include "Conteneur.hpp"

using namespace std;

class Ordonnanceur {
	public: 
		Ordonnanceur(Conteneur* conteneur_);
		~Ordonnanceur();
		int RM();
		int RM_BG();
		int EDF(int serveur);
		
		void verifierCondNecessaireRM();
		void verifierCondSuffisanteRM();
		void verifierConditionEDF();
		void verifierConditionEDF_TBS(double Us);
		
	private:
		Conteneur* conteneur_;
		
		void afficherOrdonnancement(ListeTachesPeriodiques tabOrdonnancement);
		ListeTachesPeriodiques* getOrdrePrioPeriodique();
		ListeTachesAperiodiques* getOrdrePrioAperiodique();
		
		 double calculerU();
		 double calculerU2();
		 double calculerUBound();
};
#endif

