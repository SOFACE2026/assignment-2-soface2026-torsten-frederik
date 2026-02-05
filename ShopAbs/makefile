CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -Wpedantic -g
LDFLAGS :=

TARGET  := main
OBJS    := main.o ShoeShop.o

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

main.o: main.c ShoeShop_C.h Shop_C.h
	$(CC) $(CFLAGS) -c main.c -o main.o

ShoeShop.o: ShoeShop.c ShoeShop_C.h Shop_C.h
	$(CC) $(CFLAGS) -c ShoeShop.c -o ShoeShop.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)