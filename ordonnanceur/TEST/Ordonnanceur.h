#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include <iostream>
#include <cmath>

#include "ConteneurTachePeriodique.h"

using namespace std;

class Ordonnanceur {
	public: 
		Ordonnanceur();
		~Ordonnanceur();
		void OrdonnancementRM(ConteneurTachePeriodique* conteneur);
		void OrdonnancementEDF(ConteneurTachePeriodique* conteneur);
		void verifierOrdonnancabilite(ConteneurTachePeriodique* conteneur);
		
	private:
		ConteneurTachePeriodique* conteneur_;
		
		static void verifierCondNecessaireRM(ConteneurTachePeriodique* conteneur);
		static void verifierCondSuffisanteRM(ConteneurTachePeriodique* conteneur);
		static double calculerUp(ConteneurTachePeriodique* conteneur);
		static double calculerUBound(double n);
};
#endif

