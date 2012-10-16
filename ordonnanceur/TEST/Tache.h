#ifndef _TACHE_H_
#define _TACHE_H_

#include <string>

using namespace std;

class Tache {

	public:
	virtual ~Tache() { }
	
	virtual string toString() = 0;
	
};

#endif
