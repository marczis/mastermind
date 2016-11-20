cc = g++
prog = mm
utprog = mm-ut

incs = 
libs = 
flags = -Wall -std=c++11 -g

commonsrcs = Line.cpp Game.cpp
srcs = main.cpp $(commonsrcs)

testsrcs = test/test.cpp test/utLine.cpp Line.cpp
testincs = 
testlibs = -lcppunit

objs = $(srcs:.cpp=.o)

.PHONY: clean test pre

$(prog): $(objs)
	echo $(objs)
	$(cc) $(flags) $^ $(libs) -o $@

%.o: %.cpp
	 $(cc) $(flags) $(incs) -c -o $@ $<

test:
	make srcs="$(testsrcs) $(commonsrcs)" libs="$(testlibs)" incs="$(testincs)" prog=$(utprog) && ./$(utprog)

clean:
	rm -f *.o $(prog) $(utprog)
