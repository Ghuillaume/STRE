#include "Conteneur.hpp"

Conteneur::Conteneur() {
	ListeTP_ = new ListeTachesPeriodiques();
	ListeTA_ = new ListeTachesAperiodiques();
}

Conteneur::~Conteneur() {
	for(int i = 0 ; i < ListeTP_->size() ; i++)
		delete listeTP_[i];
	listeTP_.erase(listeTP_.begin(),listeTP_.end());
}

void Conteneur::addTacheP(int num, int Ci, int Pi, int Di) {
	ListeTP_->push_back(new TachePeriodique(num,Ci,Pi,Di));
}

void Conteneur::addTacheA(int num, int ri, int Ci) {
	ListeTA_->push_back(new TacheAperiodique(num,ri,Ci));
}
		
ListeTachesPeriodiques* Conteneur::getVectorPeriodique() {
	return ListeTP_;
}

ListeTachesAperiodiques* Conteneur::getVectorAperiodique() {
	return ListeTA_;
}
