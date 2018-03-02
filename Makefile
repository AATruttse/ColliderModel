CC=g++
CFLAGS=`root-config --libs` `root-config --cflags`

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=colmodel

all:	$(EXECUTABLE)

obj:	$(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(CFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o $(EXECUTABLE)
	
rebuild: clean all
