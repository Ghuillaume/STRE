#include "TacheAperiodique.h"

TacheAperiodique::TacheAperiodique() {

}

TacheAperiodique::~TacheAperiodique() {

}

void TacheAperiodique::setValeurs(int ri, int Ci) {
	ri_ = ri;
	Ci_ = Ci;
}

int TacheAperiodique::getri() {
	return ri_;
}
	
int TacheAperiodique::getCi() {
	return Ci_;
}

