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
		TacheAperiodique recupererTache(int index);
		
		
	private:
		TabTacheAperiodique tabTacheAperiodique_;
};
#endif

