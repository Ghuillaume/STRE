#include "TacheAperiodique.h"

TacheAperiodique::TacheAperiodique() {
	numTache_ = -1;
	ri_ = 0;
	Ci_ = 0;
}

TacheAperiodique::TacheAperiodique(int ri, int Ci, int numTache) {
	numTache_ = numTache;
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

int TacheAperiodique::getNumTache() {
	return numTache_;
}

string TacheAperiodique::toString() {
	stringstream s_ri, s_Ci, s_numTache;
	s_numTache << numTache_;
    s_ri << ri_;
    s_Ci << Ci_;
    
	string chaine = "R " + s_numTache.str()  
				+ " ri : " + s_ri.str()
				+ ", Ci : " + s_Ci.str();
	return chaine;
}
