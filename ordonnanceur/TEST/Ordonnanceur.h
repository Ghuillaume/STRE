#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H
#include <iostream>
#include "ConteneurTachePeriodique.h"

using namespace std;

class Ordonnanceur {
	public: 
		Ordonnanceur();
		~Ordonnanceur();
		void OrdonnancementRM(ConteneurTachePeriodique* conteneur);
		
	private:
	
		ConteneurTachePeriodique* conteneur_;
		

};
#endif

