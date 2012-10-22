CXX = g++

Ordonnanceur: main.o ConteneurTacheAperiodique.o TacheAperiodique.o ConteneurTachePeriodique.o TachePeriodique.o Parseur.o Ordonnanceur.o
	$(CXX) -o Ordonnanceur $^
	
ConteneurTacheAperiodique.o: ConteneurTacheAperiodique.hpp ConteneurTacheAperiodique.cpp TacheAperiodique.hpp common.h
	$(CXX) -c ConteneurTacheAperiodique.cpp -o ConteneurTacheAperiodique.o
	
ConteneurTachePeriodique.o: ConteneurTachePeriodique.hpp ConteneurTachePeriodique.cpp TachePeriodique.hpp  common.h
	$(CXX) -c ConteneurTachePeriodique.cpp -o ConteneurTachePeriodique.o
	
TacheAperiodique.o: TacheAperiodique.hpp TacheAperiodique.cpp Tache.hpp common.h
	$(CXX) -c TacheAperiodique.cpp -o TacheAperiodique.o
	
TachePeriodique.o: TachePeriodique.hpp TachePeriodique.cpp Tache.hpp common.h
	$(CXX) -c TachePeriodique.cpp -o TachePeriodique.o
	
Parseur.o: Parseur.cpp Parseur.hpp ConteneurTacheAperiodique.hpp ConteneurTachePeriodique.hpp common.h
	$(CXX) -c Parseur.cpp -o Parseur.o
	
Ordonnanceur.o: Ordonnanceur.hpp Ordonnanceur.cpp ConteneurTachePeriodique.hpp ConteneurTacheAperiodique.hpp common.h
	$(CXX) -c Ordonnanceur.cpp -o Ordonnanceur.o
	
	
	
clean:
	-rm -rf *.o
