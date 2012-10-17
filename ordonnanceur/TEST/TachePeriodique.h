#ifndef _TACHEPERIODIQUE_H_
#define _TACHEPERIODIQUE_H_

#include <string>
#include <sstream>

#include "Tache.h"

using namespace std;

class TachePeriodique : public Tache {

public:
	TachePeriodique();
	TachePeriodique(int Ci, int Pi, int Di, int numTache);
	~TachePeriodique();
	
	int getCi();
	int getPi();
	int getDi();
	int getNumTache();
	string toString();
	
private:
	int Pi_;
	int Ci_;
	int Di_;
	int numTache_;
};

#endif
