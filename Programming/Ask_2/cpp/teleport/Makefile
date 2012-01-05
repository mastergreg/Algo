#CCFLAGS=-Wall -Wextra -Wuninitialized -O3
CC=c++
CCFLAGS=-g
all:	teleport
teleport:	teleport.cpp
	$(CC) teleport.cpp -o teleport ${CCFLAGS}
clean:
	rm teleport
tests:
	./teleport < testcases/input${TEST}.txt
	@cat testcases/output${TEST}.txt
