CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -Wpedantic -g
LDFLAGS :=

TARGET  := main
OBJS    := main.o ShoeShop_C.o

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

main.o: main.c ShoeShop_C.h
	$(CC) $(CFLAGS) -c main.c -o main.o

ShoeShop_C.o: ShoeShop_C.c ShoeShop_C.h
	$(CC) $(CFLAGS) -c ShoeShop_C.c -o ShoeShop_C.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)