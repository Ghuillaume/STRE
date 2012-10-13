#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <fstream>
#include <iostream>

#include "ConteneurTache.h"

using namespace std;

class Parseur {
public:
	Parseur(string nomFichier, ConteneurTache* conteneur);
	~Parseur();
	
	void lireFichier();
	
private:
	string nomFichier_;
	ConteneurTache* conteneur_;
	
	static void ajouterTachePeriodique(int Ci, int Pi, int Di);
	static void ajouterTacheAperiodique(int ri, int Ci);
	static bool verifierSyntaxe(string line);
};

#endif
