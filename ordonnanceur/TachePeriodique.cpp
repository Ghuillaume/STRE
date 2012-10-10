#include "TachePeriodique.h"

TachePeriodique::TachePeriodique(int Ci, int Pi, int Di) : Tache() {
	Ci_ = Ci;
	Pi_ = Pi;
	Di_ = Di;
}

TachePeriodique::~TachePeriodique() { }
	
int TachePeriodique::getCi() {
	return Ci_;
}

int TachePeriodique::getPi() {
	return Pi_;
}

int TachePeriodique::getDi() {
	return Di_;
}
