#ifndef _TACHE_H_
#define _TACHE_H_

#include <string>

using namespace std;

class Tache {

public:
	Tache() { }
	virtual ~Tache() { }
	
	virtual int getCi() = 0;
	virtual string toString() = 0;
	
protected:
	int Ci_;
};

#endif
