SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.c, %.o, $(SRC))

dina.out: $(OBJ)
	gcc -o $@ $^
clean:
	rm -f *.exe *.o
