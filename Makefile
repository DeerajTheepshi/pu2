CC = gcc
CFLAGS = -Wall
DEPS = auth.h handlers.h
LDEPS = `pkg-config --libs --cflags gtk+-3.0`
LSTATIC = -lpam -lpam_misc
OBJ = auth.o handlers.o
MAIN = pu2.c

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(LDEPS) $(LSTATIC) -c -o $@ $<

pu2: $(MAIN) $(OBJ)
	gcc $(CFLAGS) $(LDEPS) $(LSTATIC) -o $@ $^