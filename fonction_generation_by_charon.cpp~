
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void) {

	srand(time(NULL));
	
	int N = 8;
	int Up = 75;
	int ci, pi, Upi, minPi, maxPi;
	int sommeUpi = 0;
	
	
	// Pour les N-1 premières taches
	for(int i = 1 ; i < N ; i++) {
		ci = (rand() % 15) + 3; // Tirage aléatoire du Ci (entre 3 et 18)
		maxPi = 100;
		minPi = (int)( ((double)ci / (double)(Up-sommeUpi) )*100 + (N-i) ); // Upi doit avoir un max de Up-sommeUpi, donc Pi un min de Ci / ce max.
		pi = (rand() % maxPi) + minPi;
		Upi = (int)((double)ci*100 / (double)pi); // Calcule de Upi à partir de Ci et Pi pour pouvoir en tenir compte dans les prochains calculs
		sommeUpi += Upi;
		
		cout << "ci" << i << " = " << ci << "  ;  pi" << i << " = " << pi << "  ->  " << Upi << "/100" << endl;
	
	}
	
	// Pour la dernière tache (meme algo, sauf que Pi est calculé plutôt que généré)
	ci = (rand() % 25) + 1;
	Upi = Up - sommeUpi;
	pi = (int) ( (double)ci / ((double)Upi/100.0));
	sommeUpi += Upi;
	cout << "ci" << N << " = " << ci << "  ;  pi" << N << " = " << pi << "  ->  " << Upi << "/100" << endl;
	
	cout << "Total Up : " << sommeUpi << "/100" << endl;
	

}