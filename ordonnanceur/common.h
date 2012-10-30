#ifndef _COMMON_H_
#define _COMMON_H_

#include <sstream>
#include <vector>
#include <string>
#include "TachePeriodique.hpp"
#include "TacheAperiodique.hpp"

#define NO_SERV 0
#define BG		1
#define TBS		2

typedef std::vector<TachePeriodique*> ListeTachesPeriodiques;
typedef std::vector<TacheAperiodique*> ListeTachesAperiodiques;
typedef std::vector<std::string> ListOfString;

ListOfString explode(const std::string& str, const char& delimiter);



#endif
