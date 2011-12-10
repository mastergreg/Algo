CCFLAGS=-g -Wall -Wextra -Wuninitialized
all:	vacation
vacation:	vacation.cpp
	g++ vacation.cpp -o vacation ${CCFLAGS}
clean:
	rm vacation
tests:
	./vacation < testcases/input${TEST}.txt
	@cat testcases/output${TEST}.txt
