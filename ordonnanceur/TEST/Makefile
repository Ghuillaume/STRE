CXX = g++

Ordonnanceur: main.o ConteneurTacheAperiodique.o TacheAperiodique.o ConteneurTachePeriodique.o TachePeriodique.o Parseur.o Ordonnanceur.o
	$(CXX) -o Ordonnanceur $^
	
ConteneurTacheAperiodique.o: ConteneurTacheAperiodique.h ConteneurTacheAperiodique.cpp TacheAperiodique.h 
	$(CXX) -c ConteneurTacheAperiodique.cpp -o ConteneurTacheAperiodique.o
	
ConteneurTachePeriodique.o: ConteneurTachePeriodique.h ConteneurTachePeriodique.cpp TachePeriodique.h 
	$(CXX) -c ConteneurTachePeriodique.cpp -o ConteneurTachePeriodique.o
	
TacheAperiodique.o: TacheAperiodique.h TacheAperiodique.cpp Tache.h
	$(CXX) -c TacheAperiodique.cpp -o TacheAperiodique.o
	
TachePeriodique.o: TachePeriodique.h TachePeriodique.cpp Tache.h
	$(CXX) -c TachePeriodique.cpp -o TachePeriodique.o
	
Parseur.o: Parseur.cpp Parseur.h ConteneurTacheAperiodique.h ConteneurTachePeriodique.h
	$(CXX) -c Parseur.cpp -o Parseur.o
	
Ordonnanceur.o: Ordonnanceur.h Ordonnanceur.cpp ConteneurTachePeriodique.h ConteneurTacheAperiodique.h
	$(CXX) -c Ordonnanceur.cpp -o Ordonnanceur.o
