#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include "ConteneurTachePeriodique.h"

using namespace std;

class Ordonnanceur {
	public: 
		Ordonnanceur();
		~Ordonnanceur();
		void OrdonnacementRM(ConteneurTachePeriodique* conteneur);
		
	private:
		ConteneurTachePeriodique* conteneur_;

};
#endif

