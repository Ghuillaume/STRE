#include "TacheAperiodique.h"

TacheAperiodique::TacheAperiodique() {
	num_ = -1;
	ri_ = 0;
	Ci_ = 0;
}

TacheAperiodique::TacheAperiodique(int num, int ri, int Ci) {
	num_ = num;
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
	stringstream s_ri, s_Ci, s_numTache;
	s_numTache << num_;
    s_ri << ri_;
    s_Ci << Ci_;
    
	string chaine = "R " + s_numTache.str()  
				+ " ri : " + s_ri.str()
				+ ", Ci : " + s_Ci.str();
	return chaine;
}
