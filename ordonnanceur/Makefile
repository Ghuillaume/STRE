CXX = g++
SOURCES = TachePeriodique.cpp TacheAperiodique.cpp

ordonnanceur: Launcher.o $(SOURCES:.cpp=.o)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

TachePeriodique.o: TachePeriodique.cpp TachePeriodique.h Tache.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $@ $^
	
TacheAperiodique.o: TacheAperiodique.cpp TacheAperiodique.h Tache.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $@ $^
	
Launcher.o: Launcher.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $@ $^
	
clean:
	@rm -rf *.o
