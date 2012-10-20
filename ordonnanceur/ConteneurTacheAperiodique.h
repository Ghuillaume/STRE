#ifndef CONTENEUR_TACHE_APERIODIQUE_H
#define CONTENEUR_TACHE_APERIODIQUE_H

#include <vector>
#include "TacheAperiodique.h"

typedef vector<TacheAperiodique*> TabTacheAperiodique;


class ConteneurTacheAperiodique {
	public: 
		ConteneurTacheAperiodique();
		~ConteneurTacheAperiodique();
		void ajouterTacheAperiodique(TacheAperiodique* tacheApe);
		TacheAperiodique* getTache(int index);
		TabTacheAperiodique getTabTache();
		int getSize();
		
		
	private:
		TabTacheAperiodique tabTacheAperiodique_;
};
#endif
