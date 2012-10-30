CXX = g++

Generateur:main.o GenerateurAleatoire.o GenerateurControlee.o
	$(CXX) -o Generateur $^
	
GenerateurAleatoire: GenerateurAleatoire.cpp GenerateurAleatoire.h
	$(CXX) -c GenerateurAleatoire.cpp -o GenerateurAleatoire.o

GenerateurControlee: GenerateurControlee.cpp GenerateurControlee.h
	$(CXX) -c GenerateurControlee.cpp -o GenerateurControlee.o
	
clean:
	-rm *.o
