#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include <iostream>
#include <vector>
#include <cmath>

#include "ConteneurTachePeriodique.h"
#include "ConteneurTacheAperiodique.h"

typedef vector<TachePeriodique*> TableauPriorite;
using namespace std;

class Ordonnanceur {
	public: 
		Ordonnanceur(ConteneurTachePeriodique* conteneurPeriodique, ConteneurTacheAperiodique* conteneurAperiodique);
		~Ordonnanceur();
		void OrdonnancementRM();
		void OrdonnancementRM_BG();
		void OrdonnancementEDF();
		
	private:
		void afficherOrdonnancement(vector<TachePeriodique*> tabOrdonnancement);
		TableauPriorite getOrdrePrio();
		ConteneurTachePeriodique* conteneurPeriodique_;
		ConteneurTacheAperiodique* conteneurAperiodique_;
		void verifierOrdonnancabilite(ConteneurTachePeriodique* conteneur);
		
	private:
		ConteneurTachePeriodique* conteneur_;
		
		static void verifierCondNecessaireRM(ConteneurTachePeriodique* conteneur);
		static void verifierCondSuffisanteRM(ConteneurTachePeriodique* conteneur);
		static void verifierConditionEDF(ConteneurTachePeriodique* conteneur);
		static double calculerUp(ConteneurTachePeriodique* conteneur);
		static double calculerUBound(double n);
};
#endif

