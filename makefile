CC = gcc
CFLAGS = -Wall -g

TARGET = game.exe

OBJS = main.o utilities.o gameplay.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
main.o: main.c utilities.h
	$(CC) $(CFLAGS) -c main.c
utilities.o: utilities.c utilities.h
	$(CC) $(CFLAGS) -c utilities.c
gameplay.o: gameplay.c gameplay.h utilities.h
	$(CC) $(CFLAGS) -c gameplay.c

# Clean
clean:
	rm -f $(OBJS) $(TARGET)