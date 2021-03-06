/*******************************************************
Nom ......... : Conteneur.hpp
Role ........ : Conteneur des taches Periodiques et Apériodiques
Auteur ...... : BONCORPS, CHARON, PAGES 
********************************************************/

#ifndef _CONTENEUR_HPP_
#define _CONTENEUR_HPP_

#include "common.h"
#include <iostream>

class Conteneur {

	public:
		Conteneur();
		~Conteneur();
		
		void addTacheP(int num, int Ci, int Pi, int Di);
		void addTacheA(int num, int ri, int Ci);
		
		ListeTachesPeriodiques* getVectorPeriodique();
		ListeTachesAperiodiques* getVectorAperiodique();
		
		void toString();
		
		int getHyperPeriode();
		
	private:
		ListeTachesPeriodiques* listeTP_;
		ListeTachesAperiodiques* listeTA_;
		
		
		int ppcmPerso(int x, int y);

};

#endif
