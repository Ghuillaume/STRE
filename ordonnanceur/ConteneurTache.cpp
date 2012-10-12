#include "ConteneurTache.h"

ConteneurTache::ConteneurTache() {

}

ConteneurTache::~ConteneurTache() {
	// TODO: Libérer la  mémoire (tâches ajoutées dynamiquement /!\)
}

void ConteneurTache::addTachePeriodique(int Ci, int Pi, int Di) {
	TachePeriodique* tacheP = new TachePeriodique(Ci, Pi, Di);
	cout << "Creation de la tâche T : " << tacheP->toString() << endl;
	//tabTaches_.push_back(*tacheP);
}

void ConteneurTache::addTacheAperiodique(int ri, int Ci) {

}

void ConteneurTache::deleteTache(TachePeriodique tache) {

}

void ConteneurTache::deleteTache(TacheAperiodique tache) {

}
