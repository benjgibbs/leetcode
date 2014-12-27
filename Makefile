CC=c++
CXXFLAGS=--std=c++11
CPPS=$(wildcard src/*.cpp)
BINS=$(patsubst src/%.cpp,bin/%,$(CPPS))

all : $(BINS)

#Using a static pattern rule
$(BINS) : bin/% : src/%.cpp
	$(CC) $(CXXFLAGS) $< -o $@

bindir: 
	mkdir bin

clean : 
	rm $(BINS)
