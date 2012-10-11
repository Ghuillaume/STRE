#ifndef _TACHE_H_
#define _TACHE_H_

class Tache {

public:
	Tache() { }
	virtual ~Tache() { }
	
	virtual int getCi() = 0;
	
protected:
	int Ci_;
};

#endif
