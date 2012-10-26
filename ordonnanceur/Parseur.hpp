#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <regex>

#include "Conteneur.hpp"

using namespace std;

class Parseur {
	public:
		Parseur();
		~Parseur();
	
		void lireFichier(string nomFichier, Conteneur* c);
	
	private:
		static bool verifierSyntaxe(string &line);
};

#endif
