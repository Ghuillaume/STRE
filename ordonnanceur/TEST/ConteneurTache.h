#ifndef CONTENEUR_TACHE_H
#define CONTENEUR_TACHE_H
#include <vector>
#include "Tache.h"

using namespace std;

typedef vector<Tache*> TabTache;

class ConteneurTache {
	public:
		virtual ~ConteneurTache();
		virtual TabTache getTabTache() = 0;
	
	private:
		TabTache tabTache_;

};
#endif
	
	
