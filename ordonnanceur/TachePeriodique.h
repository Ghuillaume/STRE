#ifndef _TACHEPERIODIQUE_H_
#define _TACHEPERIODIQUE_H_

#include "Tache.h"

class TachePeriodique : virtual public Tache {

public:
	TachePeriodique(int Ci, int Pi, int Di);
	~TachePeriodique();
	
	int getCi();
	int getPi();
	int getDi();
	
private:
	int Pi_;
	int Di_;
};

#endif
