CFLAGS =
LDFLAGS =

time: time.c
	gcc$(CFLAGS) time.c -o time$(LDFLAGS)

.PHONY: run clean

run: time
	./time

clean:
	rm -f time
