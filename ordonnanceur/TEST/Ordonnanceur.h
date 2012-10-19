#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "ConteneurTachePeriodique.h"
#include "ConteneurTacheAperiodique.h"

typedef vector<TachePeriodique*> TableauPrioritePeriodique;
typedef vector<TacheAperiodique*> TableauPrioriteAperiodique;
using namespace std;

class Ordonnanceur {
	public: 
		Ordonnanceur(ConteneurTachePeriodique* conteneurPeriodique, ConteneurTacheAperiodique* conteneurAperiodique);
		~Ordonnanceur();
		int OrdonnancementRM();
		int OrdonnancementRM_BG();
		void OrdonnancementEDF();
		
	private:
		void afficherOrdonnancement(vector<TachePeriodique*> tabOrdonnancement);
		TableauPrioritePeriodique getOrdrePrioPeriodique();
		TableauPrioriteAperiodique getOrdrePrioAperiodique();
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

