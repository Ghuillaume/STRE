#include <iostream>

#include "ConteneurTache.h"
#include "TacheAperiodique.h"
#include "TachePeriodique.h"

using namespace std;

int main(void) {
	ConteneurTache ct = ConteneurTache();
	ct.addTacheAperiodique(5, 3);
	ct.addTachePeriodique(1, 2, 3);
}
