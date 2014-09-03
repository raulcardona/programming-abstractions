CC=g++
CFLAGS=-c -Wall -lStanfordCPPLib -L/Users/fuzzyllama/dev/lib/StanfordCPPLib -I/Users/fuzzyllama/dev/lib/StanfordCPPLib
LDFLAGS= -lStanfordCPPLib -L/Users/fuzzyllama/dev/lib/StanfordCPPLib -I/Users/fuzzyllama/dev/lib/StanfordCPPLib
SOURCES=6_07.cpp labelgen.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=6_07

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

