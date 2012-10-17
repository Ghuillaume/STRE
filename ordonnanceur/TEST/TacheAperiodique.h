#ifndef _TACHEAPERIODIQUE_H_
#define _TACHEAPERIODIQUE_H_

#include <string>
#include <sstream>

#include "Tache.h"

using namespace std;

class TacheAperiodique : public Tache {

public:
	TacheAperiodique();
	TacheAperiodique(int ri, int Ci, int numTache);
	~TacheAperiodique();
	
	int getri();
	int getCi();
	int getNumTache();
	string toString();
	
private:
	int Ci_;
	int ri_;
	int numTache_;
};

#endif
