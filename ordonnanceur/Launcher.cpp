#include "TacheAperiodique.h"
#include "TachePeriodique.h"

using namespace std;

int main(void) {
	TacheAperiodique tacheAp = TacheAperiodique();
	tacheAp.setValeurs(5, 3);
	TachePeriodique tacheP = TachePeriodique();
	tacheP.setValeurs(1, 2, 3); 
}
