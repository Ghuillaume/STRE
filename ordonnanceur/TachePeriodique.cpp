#include "TachePeriodique.h"

TachePeriodique::TachePeriodique() {
	Ci_ = 0;
	Pi_ = 0;
	Di_ = 0;
}

TachePeriodique::TachePeriodique(int Ci, int Pi, int Di) {
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

string TachePeriodique::toString() {
	stringstream s_Ci, s_Pi, s_Di;
    s_Ci << Ci_;
    s_Pi << Pi_;
    s_Di << Di_;

	string chaine =  "Ci : " + s_Ci.str()
				+ ", Pi : " + s_Pi.str()
				+ ", Di : " + s_Di.str();
	return chaine;
}
