#include "ConteneurTache.h"

ConteneurTache::ConteneurTache() {
	tabTaches_ = new TabTaches();
}

ConteneurTache::~ConteneurTache() {
	delete tabTaches_;
	cout << "Libération de la mémoire." << endl;
}

void ConteneurTache::addTachePeriodique(int Ci, int Pi, int Di) {
	TachePeriodique* tacheP = new TachePeriodique(Ci, Pi, Di);
	cout << "Creation de la tâche T : " << tacheP->toString() << endl;
	tabTaches_->push_back(tacheP);
}

void ConteneurTache::addTacheAperiodique(int ri, int Ci) {
	TacheAperiodique* tacheA = new TacheAperiodique(ri, Ci);
	cout << "Creation de la tâche T : " << tacheA->toString() << endl;
	tabTaches_->push_back(tacheA);
}
