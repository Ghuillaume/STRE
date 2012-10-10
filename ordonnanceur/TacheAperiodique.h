#ifndef _TACHEAPERIODIQUE_H_
#define _TACHEAPERIODIQUE_H_

#include "Tache.h"

class TacheAperiodique : public Tache {

public:
	TacheAperiodique(int ri, int Ci);
	~TacheAperiodique();
	
	int getri();
	int getCi();
	
private:
	int ri_;
};

#endif
