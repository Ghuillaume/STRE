#include "TacheAperiodique.h"

TacheAperiodique::TacheAperiodique() {
	ri_ = 0;
	Ci_ = 0;
}

TacheAperiodique::TacheAperiodique(int ri, int Ci) {
	ri_ = ri;
	Ci_ = Ci;
}

TacheAperiodique::~TacheAperiodique() {

}

int TacheAperiodique::getri() {
	return ri_;
}
	
int TacheAperiodique::getCi() {
	return Ci_;
}

string TacheAperiodique::toString() {
	stringstream s_ri, s_Ci;
    s_ri << ri_;
    s_Ci << Ci_;
    
	string chaine =  "ri : " + s_ri.str()
				+ ", Ci : " + s_Ci.str();
	return chaine;
}
