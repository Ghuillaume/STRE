#include <iostream>

#include "ConteneurTache.h"
#include "TacheAperiodique.h"
#include "TachePeriodique.h"

using namespace std;

int main(void) {
	ConteneurTache ct = ConteneurTache();
	ct.ajouterTacheAperiodique(5, 3);
	ct.ajouterTachePeriodique(1, 2, 3);
}
