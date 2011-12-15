CCFLAGS=-Wall -Wextra -Wuninitialized -O3
all:	books
books:	books.cpp
	g++ books.cpp -o books ${CCFLAGS}
tests:books
	./books < testcases/input${TEST}.txt
	@cat testcases/output${TEST}.txt
