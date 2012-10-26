CXX = g++
CXXFLAGS = -std=c++0x

Ordonnanceur: main.o Conteneur.o TacheAperiodique.o Conteneur.o TachePeriodique.o Parseur.o 
	$(CXX) -o Ordonnanceur $^
	
Conteneur: Conteneur.hpp Conteneur.cpp TachePeriodique.hpp TacheAperiodique.hpp common.h
	$(CXX) $(CXXFLAGS) -c Conteneur.cpp -o Conteneur.o
	
TacheAperiodique.o: TacheAperiodique.hpp TacheAperiodique.cpp Tache.hpp common.h
	$(CXX) $(CXXFLAGS) -c TacheAperiodique.cpp -o TacheAperiodique.o
	
TachePeriodique.o: TachePeriodique.hpp TachePeriodique.cpp Tache.hpp common.h
	$(CXX) $(CXXFLAGS) -c TachePeriodique.cpp -o TachePeriodique.o
	
Parseur.o: Parseur.cpp Parseur.hpp Conteneur.hpp common.h
	$(CXX) $(CXXFLAGS) -c Parseur.cpp -o Parseur.o
	
	
	
clean:
	-rm -rf *.o
