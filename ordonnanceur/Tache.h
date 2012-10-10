#ifndef _TACHE_H_
#define _TACHE_H_

class Tache {

public:
	Tache();
	Tache(int Ci);
	virtual ~Tache();
	
	virtual int getCi();
	
protected:
	int Ci_;
};

#endif
