#ifndef _TRACEUR_H_
#define _TRACEUR_H_

#include <fstream>
#include <string>
#include <sstream>


using namespace std;

class Traceur {
	public:
		Traceur();
		~Traceur();
		
		void entete(int hyperperiode);
		void declarationTache(int indice, string nameTache);
		void reveil(int time, int numTache );
		void execution(int time, int numTache);
		void dateEcheance(int time, int numTache);
		
		void fermetureFichier();
	private:
		ofstream file_;
		
		void creationFichier();
		
		void ecritureFichier(string line);
		
};
#endif
