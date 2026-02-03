Tum: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/QueueBST.o -c ./src/QueueBST.cpp
	g++ -I ./include/ -o ./lib/Hexagon.o -c ./src/Hexagon.cpp
	g++ -I ./include/ -o ./lib/Utils.o -c ./src/Utils.cpp
	g++ -I ./include/ -o ./lib/FileReader.o -c ./src/FileReader.cpp
	g++ -I ./include/ -o ./lib/System.o -c ./src/System.cpp
	g++ -I ./include/ -o ./lib/Main.o -c ./src/Main.cpp

	g++ -I ./include/ -o ./bin/program.exe \
	    ./lib/Node.o ./lib/BST.o ./lib/QueueBST.o ./lib/Hexagon.o \
	    ./lib/Utils.o ./lib/FileReader.o ./lib/System.o ./lib/Main.o

calistir:
	./bin/program.exe

clean:
	del /Q lib\*.o
	del /Q bin\program.exe
