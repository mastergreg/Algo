TARGET=main
CCFLAGS=-Wall -Wextra -Wuninitialized -O3
all:	$(TARGET)
$(TARGET):	$(TARGET).c
	g++ $(TARGET).c -o $(TARGET) ${CCFLAGS}
clean:
	rm $(TARGET)
tests:
	./$(TARGET) < testcases/in${TEST}.txt
	@cat testcases/out${TEST}.txt
