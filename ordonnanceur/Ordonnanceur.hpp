#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "common.h"

#include "ConteneurTachePeriodique.hpp"
#include "ConteneurTacheAperiodique.hpp"

typedef vector<TachePeriodique*> TableauPrioritePeriodique;
typedef vector<TacheAperiodique*> TableauPrioriteAperiodique;
using namespace std;

class Ordonnanceur {
	public: 
		Ordonnanceur(ConteneurTachePeriodique* conteneurPeriodique, ConteneurTacheAperiodique* conteneurAperiodique);
		~Ordonnanceur();
		int RM();
		int RM_BG();
		int EDF(int serveur);
		
	private:
		ConteneurTachePeriodique* conteneur_;
		
		void afficherOrdonnancement(vector<TachePeriodique*> tabOrdonnancement);
		TableauPrioritePeriodique getOrdrePrioPeriodique();
		TableauPrioriteAperiodique getOrdrePrioAperiodique();
		ConteneurTachePeriodique* conteneurPeriodique_;
		ConteneurTacheAperiodique* conteneurAperiodique_;
		void verifierOrdonnancabilite(ConteneurTachePeriodique* conteneur);
		
		static void verifierCondNecessaireRM(ConteneurTachePeriodique* conteneur);
		static void verifierCondSuffisanteRM(ConteneurTachePeriodique* conteneur);
		static void verifierConditionEDF(ConteneurTachePeriodique* conteneur);
		static double calculerU(ConteneurTachePeriodique* conteneur);
		static double calculerU2(ConteneurTachePeriodique* conteneur);
		static double calculerUBound(double n);
};
#endif

