#ifndef GENERATEUR_ALEATOIRE_H
#define GENERATEUR_ALEATOIRE_H

#define FILEOUT "jeuDeTaches.txt"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
typedef vector<int> Tableau;

class GenerateurAleatoire {
	public:
		GenerateurAleatoire(int nbTachesP,int nbTachesA,int utCPUP, int utCPUA);
		~GenerateurAleatoire();
		
	private:
		void generationPeriodique();
		void generationAperiodique();
		void ecritureFichier();
		int pgcd(int x, int y);
		int ppcm1(int x, int y);
		
		Tableau tabCiP_,tabPiP_,tabDiP_;
		Tableau tabriA_,tabCiA_;
		int nbTachesP_, nbTachesA_;
		int utCPUP_, utCPUA_;
		int hyperPeriode_;
		
};
#endif
