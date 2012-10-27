CXX = g++

Ordonnanceur: main.o Conteneur.o TacheAperiodique.o Conteneur.o TachePeriodique.o Parseur.o Ordonnanceur.o Traceur.o
	$(CXX) -o Ordonnanceur $^
	
Conteneur: Conteneur.hpp Conteneur.cpp TachePeriodique.hpp TacheAperiodique.hpp common.h
	$(CXX) -c Conteneur.cpp -o Conteneur.o
	
TacheAperiodique.o: TacheAperiodique.hpp TacheAperiodique.cpp Tache.hpp common.h
	$(CXX) -c TacheAperiodique.cpp -o TacheAperiodique.o
	
TachePeriodique.o: TachePeriodique.hpp TachePeriodique.cpp Tache.hpp common.h
	$(CXX) -c TachePeriodique.cpp -o TachePeriodique.o
	
Parseur.o: Parseur.cpp Parseur.hpp Conteneur.hpp common.h
	$(CXX) -c Parseur.cpp -o Parseur.o
	
Ordonnanceur.o: Ordonnanceur.hpp Ordonnanceur.cpp Traceur.hpp Conteneur.hpp common.h
	$(CXX) -c Ordonnanceur.cpp -o Ordonnanceur.o

Traceur.o: Traceur.hpp Traceur.cpp
	$(CXX) -c Traceur.cpp -o Traceur.o
	
	
clean:
	-rm -rf *.o
