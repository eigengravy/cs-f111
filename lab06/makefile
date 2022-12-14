# Set compiler to g++ or clang++ as needed
CXX := g++
CXXFLAGS := -g -O2 -Wall -std=c++20
LDFLAGS := 

ifeq ($(CXX), clang++)
# Use the LLD linker
LDFLAGS := -fuse-ld=lld
endif

ERRORS = errors.txt
OUTPUT = output.txt
RT_ERR = runtime_err.txt

PROG = Lab06
MAIN = main
LIB = cp

run: $(PROG)		
	./$(PROG) > $(OUTPUT) 2> $(RT_ERR)

$(PROG): $(MAIN).cpp
	$(CXX) $(MAIN).cpp $(CXXFLAGS) $(LDFLAGS) -l$(LIB) -o $(PROG) > $(ERRORS) 2>&1


clean: 
	rm $(PROG)

.phony: run
