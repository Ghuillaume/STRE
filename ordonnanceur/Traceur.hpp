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
		void reveilAperiodiqueExec(int time, int Ci, int nbTacheA);
		void reveilAperiodiqueAttente(int time, int Ci, int nbTacheA);
		void execution(int time, int numTache);
		void preemption(int time, int numTache);
		void finExecution(int time, int numTache);
		void dateEcheance(int time, int numTache);
		
		void creationFichier(string nameFile);
		void fermetureFichier();
	private:
		ofstream file_;
		
		void start(int time, int numTache);
		void stop(int time, int numTache);
		void deadline(int time, int numTache);
		void ready_B(int time, int numTache);
		void ready_E(int time, int numTache);
		void exec_B(int time, int numTache);
		void exec_E(int time, int numTache);
		void arrow_Up(int time, int Ci, int nbTacheA);
		
		void ecritureFichier(string line);
		
};
#endif
