#include "GenerateurAleatoire.hpp"

GenerateurAleatoire::GenerateurAleatoire(int nbTachesP,int nbTachesA,int utCPUP, int utCPUA) : nbTachesP_(nbTachesP), nbTachesA_(nbTachesA), hyperPeriode_(0), utCPUP_(utCPUP), utCPUA_(utCPUA) {
	tabCiP_ = Tableau(nbTachesP);
	tabPiP_ = Tableau(nbTachesP);
	tabDiP_ = Tableau(nbTachesP);
	tabriA_ = Tableau(nbTachesA);
	tabCiA_ = Tableau(nbTachesA);
	this->generationPeriodique();
	this->generationAperiodique();
	this->ecritureFichier();
}
GenerateurAleatoire::~GenerateurAleatoire() {

}
		
		
void GenerateurAleatoire::generationPeriodique() {
	int ciMax = 0;
	int nb_genere = 0;
	int limite_maj = utCPUP_;
	int nb_taches_restantes = nbTachesP_ - 1;
	int diviseur = 0;
	int somme = 0;

	srand(time(NULL));
	
	// Pour les taches Periodiques
	for(int i = 0; i < nbTachesP_ - 1; i++) {
		// On enlève 1 pour le rajouter ensuite au nombre généré
		// valeurs possibles : de 1 à ciMax
		ciMax = limite_maj - (nb_taches_restantes);
		nb_taches_restantes--;
		nb_genere = (rand() % ciMax) + 1;
		// On calcul et on stocke les différents parametres générés dans les tableaux respectifs
		
		diviseur = pgcd(nb_genere,100);
		tabCiP_[i] = (nb_genere / diviseur);
		tabPiP_[i] = (100/diviseur);	
		tabDiP_[i] = (100/diviseur);
		
		limite_maj -= nb_genere;
	}

	// Pour le dernier, on rajoute le reste
	diviseur = pgcd(limite_maj,100);
	tabCiP_[nbTachesP_ - 1] = (limite_maj / diviseur);
	tabPiP_[nbTachesP_ - 1] = (100/diviseur);	
	tabDiP_[nbTachesP_ - 1] = (100/diviseur);
	
	// calcul hyperperiode
	int ppcm = tabPiP_[0];
	for (int i = 0 ; i < nbTachesP_ - 1 ; i++) {
		ppcm = ppcm1(ppcm,tabPiP_[i+1]);
	}
	this->hyperPeriode_ = ppcm;
	cout << "hyperPeriode : " << this->hyperPeriode_ << endl;
}

void GenerateurAleatoire::generationAperiodique() {
	int ciMax = 0;
	int nb_genere = 0;
	int limite_maj = (utCPUA_ * this->hyperPeriode_)/100;
	int nb_taches_restantes = nbTachesA_ - 1;

	srand(time(NULL));
	
	// Pour les taches Aperiodiques
	for(int i = 0; i < nbTachesA_ - 1; i++) {
		// On enlève 1 pour le rajouter ensuite au nombre généré
		// valeurs possibles : de 1 à ciMax
		ciMax = limite_maj - (nb_taches_restantes);
		nb_taches_restantes--;
		nb_genere = (rand() % ciMax) + 1;
		// On calcul et on stocke les différents parametres générés dans les tableaux respectifs
		
		tabCiA_[i] = nb_genere;
		
		tabriA_[i] = (rand() % (this->hyperPeriode_ - nb_genere) );	
		
		limite_maj -= nb_genere;
	}

	// Pour le dernier, on rajoute le reste
	tabCiA_[nbTachesA_ - 1] = limite_maj;
	
	tabriA_[nbTachesA_ - 1] = (rand() % (this->hyperPeriode_ - limite_maj) );	
	
}

void GenerateurAleatoire::ecritureFichier() {
	ofstream fichier;
	fichier.open(FILEOUT);
	for (int i = 0 ; i < nbTachesP_; i++) {
		fichier << "T" << i+1 << ": " << tabCiP_[i] << "," << tabPiP_[i] << "," << tabDiP_[i] << endl;
	}
	for (int i = 0 ; i < nbTachesA_; i++) {
		fichier << "R" << i+1 << ": " << tabriA_[i] << "," << tabCiA_[i] << endl;
	}
	fichier.close();
}

int GenerateurAleatoire::pgcd(int x, int y) {
	if(x < y)
		return pgcd(y,x);
	else if(x % y == 0)
		return y;
	else
		return pgcd(x-y, y);
}

int GenerateurAleatoire::ppcm1(int x,int y)
{
	int A=x;
	int B=y;
	while (A!=B)
	{
		while (A>B) B=B+y;
		while (A<B) A=A+x;
	}
	return A;
} 



