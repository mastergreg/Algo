TARGET=eforia2012
CCFLAGS=-Wall -Wextra -Wuninitialized -O3
all:	$(TARGET)
$(TARGET):	$(TARGET).cpp
	g++ $(TARGET).cpp -o $(TARGET) ${CCFLAGS}
clean:
	rm $(TARGET)
tests:
	./$(TARGET) < testcases/in${TEST}.txt
	@cat testcases/out${TEST}.txt
