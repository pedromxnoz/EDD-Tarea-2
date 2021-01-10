all:
	g++ -c lista.cpp
	g++ -c Horario.cpp
	g++ -o ejecutable lista.o Horario.o
	./ejecutable