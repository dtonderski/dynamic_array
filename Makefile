CC=gcc
CFLAGS=-Wall

EXECUTABLE=dynarr.out
DEPS=dynarr.h
SRCS=dynarr.c main.c
OBJ=$(SRCS:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)

