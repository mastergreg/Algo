TARGET=vacation
CCFLAGS=-Wall -Wextra -Wuninitialized -O3
all:	$(TARGET)
$(TARGET):	$(TARGET).cpp
	g++ $(TARGET).cpp -o $(TARGET) ${CCFLAGS}
clean:
	rm $(TARGET)
tests:
	./$(TARGET) < testcases/input${TEST}.txt
	@cat testcases/output${TEST}.txt
