TARGET=synthetic
LIBS=
CC=gcc
CXX=g++
LNKR=$(CXX)
WARNGS =-Wno-format -Wno-parentheses -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast
CFLAGS=-g $(WARNGS) -fsigned-char -D__LINUX__ -I.
CXXFLAGS=-g -Wall -fsigned-char -D__LINUX__ -I.
OBJECTSCXX=$(patsubst %.cpp, %.o, $(wildcard *.cpp))
OBJECTSC=$(patsubst %.c, %.o, $(wildcard *.c))
HEADERS=$(wildcard *.h)
OBJECTS=$(OBJECTSC) $(OBJECTSCXX)
default: $(TARGET)

# Link
$(TARGET) : $(OBJECTS)
	$(LNKR) $(OBJECTS) -Wall $(LIBS) -o $@

# Compile cpp
%.o : %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile c
%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	-rm -f *.o
	-rm -f $(TARGET)
