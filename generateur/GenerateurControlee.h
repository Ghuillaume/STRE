#ifndef GENERATEUR_CONTROLEE_H
#define GENERATEUR_CONTROLEE_H


#define FILEOUT jeuDeTaches.txt

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef vector<int> Tableau;

class GenerateurControlee {
	
	public:
		GenerateurControlee(int nbTachesP, int nbTachesA);
		~GenerateurControlee();
		
	private:
		void generation();
		void ecritureFichier();
		
		Tableau tabCiP_, tabPiP_, tabDiP_;
		Tableau tabriA_, tabCiA_;
		int nbTachesP_, nbTachesA_;

};
#endif
