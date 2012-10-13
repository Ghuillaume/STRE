#ifndef _CONTENEURTACHE_H_
#define _CONTENEURTACHE_H_

#include <vector>
#include <iostream>

#include "TacheAperiodique.h"
#include "TachePeriodique.h"

using namespace std;

typedef vector<Tache*> TabTaches;

class ConteneurTache {
public:
	ConteneurTache();
	~ConteneurTache();
	
	void ajouterTachePeriodique(int Ci, int Pi, int Di);
	void ajouterTacheAperiodique(int ri, int Ci);
	
private:
	TabTaches* tabTaches_;
};

#endif
