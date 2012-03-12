TARGET=main
CCFLAGS=-Wall -Wextra -Wuninitialized -O3
DEPS=heap.o

all:	$(TARGET)
$(TARGET):	$(TARGET).o $(DEPS)
	gcc $(TARGET).o $(DEPS) -o $(TARGET) 
%.o: %.c
	gcc -c $< $(CCFLAGS)
clean:
	rm $(TARGET)
tests:
	./$(TARGET) < testcases/in${TEST}.txt
	@cat testcases/out${TEST}.txt
