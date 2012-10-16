#ifndef CONTENEUR_TACHE_PERIODIQUE_H
#define CONTENEUR_TACHE_PERIODIQUE_H

#include <vector>
#include "TachePeriodique.h"

typedef vector<TachePeriodique*> TabTachePeriodique;


class ConteneurTachePeriodique {
	public: 
		ConteneurTachePeriodique();
		~ConteneurTachePeriodique();
		void ajouterTachePeriodique(TachePeriodique* tachePe);
		TachePeriodique recupererTache(int index);
		
		
	private:
		TabTachePeriodique tabTachePeriodique_;
};
#endif

