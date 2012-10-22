#include "ConteneurTacheAperiodique.hpp"

ConteneurTacheAperiodique::ConteneurTacheAperiodique() {
	tabTacheAperiodique_ = TabTacheAperiodique();
}
ConteneurTacheAperiodique::~ConteneurTacheAperiodique() {

}

void ConteneurTacheAperiodique::ajouterTacheAperiodique(TacheAperiodique* tacheApe) {
	tabTacheAperiodique_.push_back(tacheApe);
}

TacheAperiodique* ConteneurTacheAperiodique::getTache(int index) {
	return tabTacheAperiodique_.at(index);
}

TabTacheAperiodique ConteneurTacheAperiodique::getTabTache() {
	return tabTacheAperiodique_;
}

int ConteneurTacheAperiodique::getSize() {
	return tabTacheAperiodique_.size();
}

