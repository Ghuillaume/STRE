#ifndef _TACHEAPERIODIQUE_H_
#define _TACHEAPERIODIQUE_H_

#include <string>
#include <sstream>

#include "Tache.h"

using namespace std;

class TacheAperiodique : public Tache {

public:
	TacheAperiodique();
	TacheAperiodique(int ri, int Ci);
	~TacheAperiodique();
	
	int getri();
	int getCi();
	string toString();
	
private:
	int ri_;
};

#endif
