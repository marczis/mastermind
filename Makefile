cc = g++
prog = mm
utprog = mm-ut

incs = 
libs =
flags = -Wall -std=c++0x
objdir = ./objs
srcs = main.cpp

testsrcs = test/test.cpp
testincs = 
testlibs = -lcppunit

objs = $(subst .cpp,.o,$(srcs))


.PHONY: clean test pre

$(prog): $(objdir)/$(objs)
	make pre
	$(cc) $(flags) $^ $(libs) -o $@

$(objdir)/%.o: %.cpp
	 $(cc) $(flags) $(incs) -c -o $@ $<

pre:
	mkdir -p objs objs/test

test:
	make srcs=$(testsrcs) libs=$(testlibs) incs=$(testincs) prog=$(utprog)

clean:
	rm -f $(objdir)/*.o $(prog) $(utprog)
