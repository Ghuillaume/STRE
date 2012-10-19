#include "ConteneurTachePeriodique.h"

ConteneurTachePeriodique::ConteneurTachePeriodique() {
	tabTachePeriodique_ = TabTachePeriodique();
}
ConteneurTachePeriodique::~ConteneurTachePeriodique() {

}

void ConteneurTachePeriodique::ajouterTachePeriodique(TachePeriodique* tachePe) {
	tabTachePeriodique_.push_back(tachePe);
	this->calculHyperPeriode();
}

TabTachePeriodique ConteneurTachePeriodique::getTabTache() {
	return tabTachePeriodique_;
}

TachePeriodique* ConteneurTachePeriodique::getTache(int index) {
	return tabTachePeriodique_.at(index);	
}

int ConteneurTachePeriodique::getSize()  {
	return tabTachePeriodique_.size();
}

int ConteneurTachePeriodique::getHyperPeriode() {
	return hyperPeriode_;
}

int ConteneurTachePeriodique::ppcm1(int x,int y)
{
	int A=x;
	int B=y;
	while (A!=B)
	{
		while (A>B) B=B+y;
		while (A<B) A=A+x;
	}
	return A;
} 

void ConteneurTachePeriodique::calculHyperPeriode() {
	int ppcm = tabTachePeriodique_[0]->getPi();
	for (int i = 0 ; i < tabTachePeriodique_.size() ; i++) {
		ppcm = ppcm1(ppcm,tabTachePeriodique_[i]->getPi());
	}
	this->hyperPeriode_ = ppcm;
}
