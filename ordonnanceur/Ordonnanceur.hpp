/*******************************************************
Nom ......... : Ordonnanceur.hpp
Role ........ : Permet de Verifier l'ordonnancabilite
				Environnement de simulation selon plusieurs algorithme d'ordonnancement
Auteur ...... : BONCORPS, CHARON, PAGES 
********************************************************/

#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

#include "common.h"
#include "Traceur.hpp"
#include "Conteneur.hpp"

using namespace std;
typedef vector<int> ListeTachesPretes;

class Ordonnanceur {
	public: 
		Ordonnanceur(Conteneur* conteneur, Traceur* traceur);
		~Ordonnanceur();
		int RM(int serveur);
		int EDF(int serveur, int bandePassanteTBS = 0);
		
		void verifierCondNecessaireRM();
		void verifierCondSuffisanteRM();
		void verifierConditionEDF();
		void verifierConditionEDF_TBS(double Us);
		
	private:
		Conteneur* conteneur;
		Traceur* traceur;
		
		void afficherOrdonnancement(ListeTachesPeriodiques tabOrdonnancement);
		ListeTachesPeriodiques ordonnerTachesPeriodiquesPi();
		ListeTachesAperiodiques ordonnerTachesAperiodiques();
		
		 double calculerU();
		 double calculerU2();
		 double calculerUBound();
};
#endif

