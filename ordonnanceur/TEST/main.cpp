#include "Parseur.h"

#include "TacheAperiodique.h"
#include "TachePeriodique.h"

#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	ConteneurTacheAperiodique* contAper = new ConteneurTacheAperiodique();
	ConteneurTachePeriodique* contPer = new ConteneurTachePeriodique();
	TacheAperiodique* tacheA = new TacheAperiodique(12,45);
	cout << "tache 1" << tacheA->toString() << endl;
	Parseur* parse = new Parseur("fichierTestAlea.txt",contAper,contPer);
	parse->lireFichier();

}
