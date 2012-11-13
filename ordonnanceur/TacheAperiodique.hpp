/*******************************************************
Nom ......... : TacheAperiodique.hpp
Role ........ : défini les attributs et les méthodes applicables aux taches apériodiques
Auteur ...... : BONCORPS, CHARON, PAGES 
********************************************************/

#ifndef _TACHEAPERIODIQUE_H_
#define _TACHEAPERIODIQUE_H_

#include <string>
#include <sstream>

#include "Tache.hpp"

using namespace std;

class TacheAperiodique : public Tache {

public:
	TacheAperiodique();
	TacheAperiodique(int num, int ri, int Ci);
	~TacheAperiodique();
	
	int getri();
	int getCi();
	string toString();
	string formatKTR();
	
private:
	int Ci_;
	int ri_;
};

#endif
