CCFLAGS=-Wall -Wextra -Wuninitialized -O3
.PHONY: test
test:
	time -v ./books.py < testcases/input${TEST}.txt
	@cat testcases/output${TEST}.txt
