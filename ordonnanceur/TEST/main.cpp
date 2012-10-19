#include "Parseur.h"

#include "TacheAperiodique.h"
#include "TachePeriodique.h"
#include "Ordonnanceur.h"

#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	
	
/*	
	cout << "tache 1" << tacheA->toString() << endl;
	Parseur* parse = new Parseur("fichierTestAlea.txt",contAper,contPer);
	parse->lireFichier();
*/
	// ajout Tache dans ConteneurPeriodique
	ConteneurTachePeriodique* contPer = new ConteneurTachePeriodique();

	// ajout Tache dans ConteneurPeriodique 
	TachePeriodique* tacheP2 = new TachePeriodique(2,8,8,2);
	TachePeriodique* tacheP1 = new TachePeriodique(2,6,6,1);
	TachePeriodique* tacheP3 = new TachePeriodique(2,12,12,3);
	
	contPer->ajouterTachePeriodique(tacheP1);
	contPer->ajouterTachePeriodique(tacheP2);
	cout << "hyperperiode" << contPer->getHyperPeriode() << endl;
	contPer->ajouterTachePeriodique(tacheP3);
	cout << "hyperperiode" << contPer->getHyperPeriode() << endl;
	
	// ajout Tache Aperiodique
	ConteneurTacheAperiodique* contAper = new ConteneurTacheAperiodique();
	
	TacheAperiodique* tacheA = new TacheAperiodique(1,3,1);
	TacheAperiodique* tacheB = new TacheAperiodique(22,3,2);
	
	contAper->ajouterTacheAperiodique(tacheA);
	contAper->ajouterTacheAperiodique(tacheB);
	
	Ordonnanceur* ordo = new Ordonnanceur(contPer,contAper);
	ordo->OrdonnancementEDF();

}
