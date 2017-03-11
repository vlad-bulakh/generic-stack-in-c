filename=stack
compiler=gcc
sources=$(wildcard src/*.c)
libraries_linux=
options=-Wall -Wextra -g -ansi -pedantic

all:
	$(compiler) $(options) $(sources) $(libraries_linux) -o $(filename)
	
clean:
	rm -f *.o $(filename)
	
cleanall:
	rm -f *.o $(filename)
