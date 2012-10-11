#include "TachePeriodique.h"

TachePeriodique::TachePeriodique() { }

TachePeriodique::~TachePeriodique() { }
	
void TachePeriodique::setValeurs(int Ci, int Pi, int Di) {
	Ci_ = Ci;
	Pi_ = Pi;
	Di_ = Di;
}
	
int TachePeriodique::getCi() {
	return Ci_;
}

int TachePeriodique::getPi() {
	return Pi_;
}

int TachePeriodique::getDi() {
	return Di_;
}
