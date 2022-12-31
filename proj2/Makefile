CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
LDFLAGS=	
SHELL=		bash
PROGRAMS=	volsort
SOURCES=	main.cpp stl.cpp qsort.cpp quick.cpp merge.cpp list.cpp
OBJECTS=	$(SOURCES:.cpp=.o)

all:		$(PROGRAMS)

%.o:		%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

volsort:	$(OBJECTS) 
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

clean:
	rm -f $(PROGRAMS) $(OBJECTS)

test:		test-output test-memory

test-output:	$(PROGRAMS)
	@echo "Testing output (stl string)..."
	@diff --suppress-common-lines -y <(./volsort -m stl      < input) output.string
	@echo "Testing output (stl number)..."
	@diff --suppress-common-lines -y <(./volsort -m stl -n   < input) output.number
	@echo "Testing output (qsort string)..."
	@diff --suppress-common-lines -y <(./volsort -m qsort    < input) output.string
	@echo "Testing output (qsort number)..."
	@diff --suppress-common-lines -y <(./volsort -m qsort -n < input) output.number
	@echo "Testing output (merge string)..."
	@diff --suppress-common-lines -y <(./volsort -m merge    < input) output.string
	@echo "Testing output (merge number)..."
	@diff --suppress-common-lines -y <(./volsort -m merge -n < input) output.number
	@echo "Testing output (quick string)..."
	@diff --suppress-common-lines -y <(./volsort -m quick    < input) output.string
	@echo "Testing output (quick number)..."
	@diff --suppress-common-lines -y <(./volsort -m quick -n < input) output.number

test-memory:	$(PROGRAMS)
	@echo "Testing memory (stl)..."
	@[ `valgrind --leak-check=full ./volsort -m stl   < input < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]
	@echo "Testing memory (qsort)..."
	@[ `valgrind --leak-check=full ./volsort -m qsort < input < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]
	@echo "Testing memory (merge)..."
	@[ `valgrind --leak-check=full ./volsort -m merge < input < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]
	@echo "Testing memory (quick)..."
	@[ `valgrind --leak-check=full ./volsort -m quick < input < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]
