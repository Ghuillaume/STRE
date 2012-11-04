/*******************************************************
Nom ......... : Parseur.hpp
Role ........ : Verifie la syntaxe et recupérer les informations sur les taches
				d'un fichier formaté
Auteur ...... : BONCORPS, CHARON, PAGES 
********************************************************/

#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex.h>

#include "common.h"
#include "Conteneur.hpp"

using namespace std;

class Parseur {
	public:
		Parseur();
		~Parseur();
	
		void lireFichier(char* nomFichier, Conteneur* c);
	
	private:
		static bool verifierSyntaxe(string &line);
};

#endif
