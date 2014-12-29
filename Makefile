CC=c++
CXXFLAGS=--std=c++11
CPPS=$(wildcard src/*.cpp)
BINS=$(patsubst src/%.cpp,bin/%,$(CPPS))

all : $(BINS)

#Using a static pattern rule
$(BINS) : bin/%  :  src/%.cpp
	if [ ! -d bin ]; then mkdir bin; fi
	$(CC) $(CXXFLAGS) $< -o $@

clean : 
	rm $(BINS)
