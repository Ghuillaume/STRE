#ifndef _TACHEPERIODIQUE_H_
#define _TACHEPERIODIQUE_H_

#include <string>
#include <sstream>

#include "Tache.hpp"

using namespace std;

class TachePeriodique : public Tache {

public:
	TachePeriodique();
	TachePeriodique(int num, int Ci, int Pi, int Di);
	~TachePeriodique();
	
	int getCi();
	int getPi();
	int getDi();
	string toString();
	
private:
	int Pi_;
	int Ci_;
	int Di_;
};

#endif
