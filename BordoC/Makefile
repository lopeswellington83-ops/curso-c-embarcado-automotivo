CC = clang
CFLAGS = -Wall -Wextra -Wpedantic
TARGET = bordoc
OBJECTS = main.o bordoc.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

main.o: main.c bordoc.h
	$(CC) $(CFLAGS) -c main.c -o main.o

bordoc.o: bordoc.c bordoc.h
	$(CC) $(CFLAGS) -c bordoc.c -o bordoc.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean
