CC = gcc
CFLAGS = -Wall
DEPS = auth.h handlers.h
LDEPS = `pkg-config --libs --cflags gtk+-2.0`
LSTATIC = -lpam -lpam_misc
OBJ = auth.o handlers.o
MAIN = pu2.c

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(LDEPS) $(LSTATIC) -c -o $@ $<

pu2: $(OBJ)
	gcc $(CFLAGS) $(LDEPS) $(LSTATIC) -o $@ $(MAIN) $^