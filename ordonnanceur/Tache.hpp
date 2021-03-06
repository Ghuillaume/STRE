/*******************************************************
Nom ......... : Tache.hpp
Role ........ : Défini des méthodes et des attributs partagés par les taches périodiques et apériodiques
Auteur ...... : BONCORPS, CHARON, PAGES 
********************************************************/

#ifndef _TACHE_H_
#define _TACHE_H_

#include <string>

using namespace std;

class Tache {

	public:
		virtual ~Tache() {};
	
		virtual string toString() = 0;
		int getNum() { return num_; }
	
	protected:
		int num_;
	
};

#endif
