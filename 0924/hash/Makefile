.PHONY:clean
CC=g++
CFLAGS=-Wall -g
BIN=test
OBJS=main.o str.o hash.o
STAND= -std=c++0x
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(STAND)
clean:
	rm -f *.o $(BIN)
