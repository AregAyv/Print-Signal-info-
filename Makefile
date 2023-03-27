all: main.cpp

main.cpp: main.cpp
	g++ -o main.cpp main.cpp.cpp

clean:
       rm -f main.cpp
