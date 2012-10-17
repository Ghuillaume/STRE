#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H
#include <iostream>
#include <vector>
#include "ConteneurTachePeriodique.h"
#include "ConteneurTacheAperiodique.h"

typedef vector<TachePeriodique*> TableauPriorite;
using namespace std;

class Ordonnanceur {
	public: 
		Ordonnanceur(ConteneurTachePeriodique* conteneurPeriodique, ConteneurTacheAperiodique* conteneurAperiodique);
		~Ordonnanceur();
		void OrdonnancementRM();
		void OrdonnancementEDF();
		
	private:
		void afficherOrdonnancement(vector<TachePeriodique*> tabOrdonnancement);
		TableauPriorite getOrdrePrio();
		ConteneurTachePeriodique* conteneurPeriodique_;
		ConteneurTacheAperiodique* conteneurAperiodique_;
		

};
#endif

