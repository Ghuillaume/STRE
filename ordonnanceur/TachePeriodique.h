#ifndef _TACHEPERIODIQUE_H_
#define _TACHEPERIODIQUE_H_

#include "Tache.h"

class TachePeriodique : public Tache {

public:
	TachePeriodique();
	~TachePeriodique();
	
	void setValeurs(int Ci, int Pi, int Di);
	int getCi();
	int getPi();
	int getDi();
	
private:
	int Pi_;
	int Di_;
};

#endif
