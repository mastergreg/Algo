#CCFLAGS=-Wall -Wextra -Wuninitialized -O3
CC=g++
CCFLAGS=-O3 -Wall -Wextra -Wuninitialized
all:	teleport
teleport:	teleport.cpp
	$(CC) teleport.cpp -o teleport ${CCFLAGS}
clean:
	rm teleport
tests:
	./teleport < testcases/input${TEST}.txt
	@cat testcases/output${TEST}.txt
