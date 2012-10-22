#ifndef _COMMON_H_
#define _COMMON_H_

#include <vector>
#include "TachePeriodique.hpp"
#include "TacheAperiodique.hpp"

#define NO_SERV 0
#define BG		1
#define TBS		2

typedef std::vector<TachePeriodique*> ListeTachesPeriodiques;
typedef std::vector<TacheAperiodique*> ListeTachesAperiodiques;

#endif
