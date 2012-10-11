#ifndef _TACHEAPERIODIQUE_H_
#define _TACHEAPERIODIQUE_H_

#include "Tache.h"

class TacheAperiodique : public Tache {

public:
	TacheAperiodique();
	~TacheAperiodique();
	
	void setValeurs(int ri, int Ci);
	int getri();
	int getCi();
	
private:
	int ri_;
};

#endif
