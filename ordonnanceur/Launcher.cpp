#include <iostream>

#include "TacheAperiodique.h"
#include "TachePeriodique.h"

using namespace std;

int main(void) {
	TacheAperiodique tacheAp = TacheAperiodique(5, 3);
	cout << tacheAp.toString() << endl;
	TachePeriodique tacheP = TachePeriodique(1, 2, 3);
	cout << tacheP.toString() << endl;
}
