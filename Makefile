CC=c++
CXXFLAGS=--std=c++11
CPPS=$(wildcard src/*.cpp)
BINS=$(patsubst src/%.cpp,bin/%,$(CPPS))

.DEFAULT_GOAL:=all

$(BINS) : $(patsubst bin/%,.src/%.cpp,$@)
	@echo "Compiling to $@."
	$(CC) $(CXXFLAGS) $(patsubst bin/%,src/%.cpp,$@)  -o $@

all : $(BINS)
	@echo $(BINS)

clean : 
	rm $(BINS)
