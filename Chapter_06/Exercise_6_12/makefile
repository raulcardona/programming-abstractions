CC=g++
CFLAGS=-c -Wall -I/Users/fuzzyllama/dev/lib/StanfordCPPLib
LDFLAGS= -lStanfordCPPLib -L/Users/fuzzyllama/dev/lib/StanfordCPPLib -I/Users/fuzzyllama/dev/lib/StanfordCPPLib
SOURCES=6_12.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=6_12

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

