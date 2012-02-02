TARGET=headquarters
CCFLAGS=-Wall -Wextra -Wuninitialized -Weffc++ -ansi -FORTIFY_SOURCE -g
all:	$(TARGET)
$(TARGET):	$(TARGET).cpp
	g++ $(TARGET).cpp $(CCFLAGS) -o $(TARGET) 
clean:
	rm $(TARGET)
tests:
	./$(TARGET) < testcases/input$(TEST).txt
	@cat testcases/output$(TEST).txt
