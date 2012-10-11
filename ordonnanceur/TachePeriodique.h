#ifndef _TACHEPERIODIQUE_H_
#define _TACHEPERIODIQUE_H_

#include <string>
#include <sstream>

#include "Tache.h"

using namespace std;

class TachePeriodique : public Tache {

public:
	TachePeriodique();
	TachePeriodique(int Ci, int Pi, int Di);
	~TachePeriodique();
	
	int getCi();
	int getPi();
	int getDi();
	string toString();
	
private:
	int Pi_;
	int Di_;
};

#endif
