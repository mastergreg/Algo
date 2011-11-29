CCFLAGS=-g -Wall -Wextra -Wuninitialized
all:	books
books:	books.cpp books.h
	g++ books.cpp -o books ${CCFLAGS}
tests:
	./books < testcases/input${TEST}.txt
	@cat testcases/output${TEST}.txt
