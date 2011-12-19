CCFLAGS=-Wall -Wextra -Wuninitialized -O3
all:	xmasshopping
xmasshopping:	xmasshopping.cpp
	g++ xmasshopping.cpp -o xmasshopping ${CCFLAGS}
clean:
	rm xmasshopping
tests:
	./xmasshopping < testcases/input${TEST}.txt
	@cat testcases/output${TEST}.txt
