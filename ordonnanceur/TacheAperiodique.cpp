#include "TacheAperiodique.h"

TacheAperiodique::TacheAperiodique(int ri, int Ci) : Tache() {
	ri_ = ri;
	Ci_ = Ci;
}

TacheAperiodique::~TacheAperiodique() { }

int TacheAperiodique::getri() {
	return ri_;
}
	
int TacheAperiodique::getCi() {
	return Ci_;
}

