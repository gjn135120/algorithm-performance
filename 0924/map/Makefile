.PHONY:clean
CC=g++
CFLAGS=-Wall -g
BIN=test
OBJS=main.o str.o map.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
