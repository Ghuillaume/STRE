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
