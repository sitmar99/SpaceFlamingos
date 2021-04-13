CC= g++
CFLAGS= -std=c++17 -Wall -w -O2
INCLUDE= -I include/
SFML= -lsfml-graphics -lsfml-window -lsfml-system
THREAD= -lpthread
SOURCE:= $(wildcard source/*.cpp)
OBJ:= obj
EXE= Game

all:	$(EXE)
	./$(EXE)

$(EXE):	
	$(CC) -c $(CFLAGS) $(INCLUDE) $(SOURCE)
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) -o $(EXE) $(SFML)
	mv *.o $(OBJ)

clean:
	rm *.o
	rm obj/*.o
	rm $(EXE)
	clear

compile:	$(EXE)