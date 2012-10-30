#include "Conteneur.hpp"

Conteneur::Conteneur() {
	listeTP_ = new ListeTachesPeriodiques();
	listeTA_ = new ListeTachesAperiodiques();
}

Conteneur::~Conteneur() {
	/*for(int i = 0 ; i < listeTP_->size() ; i++)
		delete listeTP_[i];
	listeTP_.erase(listeTP_.begin(),listeTP_.end());*/
}

void Conteneur::addTacheP(int num, int Ci, int Pi, int Di) {
	listeTP_->push_back(new TachePeriodique(num,Ci,Pi,Di));
}

void Conteneur::addTacheA(int num, int ri, int Ci) {
	listeTA_->push_back(new TacheAperiodique(num,ri,Ci));
}
		
ListeTachesPeriodiques* Conteneur::getVectorPeriodique() {
	return listeTP_;
}

ListeTachesAperiodiques* Conteneur::getVectorAperiodique() {
	return listeTA_;
}

void Conteneur::toString() {

	std::cout << "Hyperperiode = " << this->getHyperPeriode() << endl;

	for(int i = 0 ; i < listeTP_->size() ; i++)
		std::cout << "T" << listeTP_->at(i)->getNum() << ": " << listeTP_->at(i)->getCi() << "," << listeTP_->at(i)->getPi() << "," << listeTP_->at(i)->getDi() << endl;
	for(int i = 0 ; i < listeTA_->size() ; i++)
		std::cout << "R" << listeTA_->at(i)->getNum() << ": " << listeTA_->at(i)->getri() << "," << listeTA_->at(i)->getCi() << endl;


}

int Conteneur::getHyperPeriode() {
	int hyperPeriode = listeTP_->at(0)->getPi();
	for (int i = 0 ; i < listeTP_->size() - 1 ; i++) {
		hyperPeriode = ppcmPerso(hyperPeriode,listeTP_->at(i+1)->getPi());
	}
	return hyperPeriode;
}


int Conteneur::ppcmPerso(int x,int y)
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

