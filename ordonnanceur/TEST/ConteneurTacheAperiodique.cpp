#include "ConteneurTacheAperiodique.h"

ConteneurTacheAperiodique::ConteneurTacheAperiodique() {
	tabTacheAperiodique_ = TabTacheAperiodique();
}
ConteneurTacheAperiodique::~ConteneurTacheAperiodique() {

}

void ConteneurTacheAperiodique::ajouterTacheAperiodique(TacheAperiodique* tacheApe) {
	tabTacheAperiodique_.push_back(tacheApe);
}

TacheAperiodique ConteneurTacheAperiodique::recupererTache(int index) {
	
}
