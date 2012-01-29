TARGET=headquarters
CCFLAGS=-Wall -Wextra -Wuninitialized -g
all:	$(TARGET)
$(TARGET):	$(TARGET).cpp
	g++ $(TARGET).cpp -o $(TARGET) ${CCFLAGS}
clean:
	rm $(TARGET)
tests:
	./$(TARGET) < testcases/input${TEST}.txt
	@cat testcases/output${TEST}.txt
