all: main.o serieLin.o zig.o
	g++ -o appli main.o serieLin.o zig.o \
	-lpthread -std=c++11 \
	-lmosquitto -lmysqlclient \
	-D_REENTRANT

serieLin.o: serieLin.cpp serieLin.h
	g++ -o serieLin.o -c serieLin.cpp  -std=c++11 -W

zig.o: zig.cpp
	g++ -c zig.cpp  -std=c++11 
	
main.o: main.cpp  structEch.h
	g++ -c main.cpp  -std=c++11 -W
	
clean:
	rm *.o

