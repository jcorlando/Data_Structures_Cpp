CFLAGS = -Wpedantic -Wall -Wextra -Werror
LDFLAGS =

my_pid_manager: my_pid_manager.c
	gcc $(CFLAGS) my_pid_manager.c -o my_pid_manager$(LDFLAGS)

.PHONY: run clean

run: my_pid_manager
	./my_pid_manager

clean:
	rm -f my_pid_manager
