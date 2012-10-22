#ifndef _CONTENEUR_HPP_
#define _CONTENEUR_HPP_

#include "common.h"

class Conteneur {

	public:
		Conteneur();
		~Conteneur();
		
		void addTacheP(int num, int Ci, int Pi, int Di);
		void addTacheA(int num, int ri, int Ci);
		
		ListeTachesPeriodiques* getVectorPeriodique();
		ListeTachesAperiodiques* getVectorAperiodique();
		
	private:
		ListeTachesPeriodiques* listeTP_;
		ListeTachesAperiodiques* listeTA_;


};

#endif