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
		Ordonnanceur(Controleur* controleur_);
		~Ordonnanceur();
		int RM();
		int RM_BG();
		int EDF(int serveur);
		
	private:
		Conteneur* controleur_;
		
		void afficherOrdonnancement(vector<TachePeriodique*> tabOrdonnancement);
		TableauPrioritePeriodique getOrdrePrioPeriodique();
		TableauPrioriteAperiodique getOrdrePrioAperiodique();
		
		void verifierOrdonnancabilite();
		
		static void verifierCondNecessaireRM();
		static void verifierCondSuffisanteRM();
		static void verifierConditionEDF();
		static double calculerU();
		static double calculerU2();
		static double calculerUBound(double n);
};
#endif

