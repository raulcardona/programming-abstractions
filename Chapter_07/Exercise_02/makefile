CC=g++
CFLAGS=-c -Wall -I/Users/fuzzyllama/dev/lib/MyStanfordCPPLib
LDFLAGS= -lStanfordCPPLib -L/Users/fuzzyllama/dev/lib/MyStanfordCPPLib -I/Users/fuzzyllama/dev/lib/MyStanfordCPPLib
SOURCES=7_02.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=7_02

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

