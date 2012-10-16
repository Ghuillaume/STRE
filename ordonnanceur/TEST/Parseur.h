#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <fstream>
#include <iostream>

#include "ConteneurTacheAperiodique.h"
#include "ConteneurTachePeriodique.h"

using namespace std;

class Parseur {
public:
	Parseur(string nomFichier, ConteneurTacheAperiodique* conteneurApe, ConteneurTachePeriodique* conteneurPe);
	~Parseur();
	
	void lireFichier();
	
private:
	string nomFichier_;
	ConteneurTacheAperiodique* conteneurApe_;
	ConteneurTachePeriodique* conteneurPe_;
	
	static void ajouterTachePeriodique(int Ci, int Pi, int Di);
	static void ajouterTacheAperiodique(int ri, int Ci);
	static bool verifierSyntaxe(string line);
};

#endif
