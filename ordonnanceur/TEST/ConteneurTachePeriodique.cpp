#include "ConteneurTachePeriodique.h"

ConteneurTachePeriodique::ConteneurTachePeriodique() {
	tabTachePeriodique_ = TabTachePeriodique();
}
ConteneurTachePeriodique::~ConteneurTachePeriodique() {

}

void ConteneurTachePeriodique::ajouterTachePeriodique(TachePeriodique* tachePe) {
	tabTachePeriodique_.push_back(tachePe);
}

TachePeriodique ConteneurTachePeriodique::recupererTache(int index) {
	
}
