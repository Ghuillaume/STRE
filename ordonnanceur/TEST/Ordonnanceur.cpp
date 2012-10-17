#include "Ordonnanceur.h"

Ordonnanceur::Ordonnanceur() {

}

Ordonnanceur::~Ordonnanceur() {

}

void Ordonnanceur::OrdonnancementRM(ConteneurTachePeriodique* conteneur) {
	vector<int> tabPrio(conteneur->getSize());
	vector<int> tabOrdo(conteneur->getHyperPeriode());
	cout << "TabPrio ";
	for(int i = 0 ; i < conteneur->getSize() ; i++) {
		tabPrio[i] = conteneur->getTache(i)->getCi();
		cout << i << " " << tabPrio[i] << endl;
	}
	
	for(int i = 0 ; i < conteneur->getHyperPeriode() ; i++) {
		// Verification que la tache ne s'est pas reveillée
		for(int t = 0 ; t < conteneur->getSize() ; t++) {
			if ((i%(conteneur->getTache(t)->getPi())) == 0) {
				//reveil
				tabPrio[t] = conteneur->getTache(t)->getCi();
			}
		}
		bool sortir = false;
		int t = 0;
		
		while ((sortir==false) && (t<conteneur->getSize())) {
			if (tabPrio[t] = 0) {
				t++;
			}
			else {
				sortir = true;
			}
		}
		if (sortir == true) {
			tabOrdo[i] = t + 1;
			tabPrio[t] = tabPrio[t] - 1;
		}
	}
	
	for(int i = 0 ; i < tabOrdo.size() ; i++) {
		cout << "t=" << i << " : Tache" << tabOrdo[i] << endl;
	}	

}
