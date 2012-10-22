#ifndef CONTENEUR_TACHE_PERIODIQUE_H
#define CONTENEUR_TACHE_PERIODIQUE_H

#include <vector>
#include "TachePeriodique.hpp"

typedef vector<TachePeriodique*> TabTachePeriodique;


class ConteneurTachePeriodique {
	public: 
		ConteneurTachePeriodique();
		~ConteneurTachePeriodique();
		
		void ajouterTachePeriodique(TachePeriodique* tachePe);
		TachePeriodique* getTache(int index);
		TabTachePeriodique getTabTache();
		int getSize();
		int getHyperPeriode();
		
		
	private:
		TabTachePeriodique tabTachePeriodique_;
		int hyperPeriode_;
		
		int ppcm1(int x, int y);
		void calculHyperPeriode();
		
};
#endif

