CFLAGS = -Wpedantic -Wall -Wextra -Werror
LDFLAGS =

my_pid_manager: my_pid_manager.c
	gcc $(CFLAGS) my_pid_manager.c -o my_pid_manager$(LDFLAGS)


.PHONY: run clean debug

run: my_pid_manager
	./my_pid_manager

clean:
	rm -f my_pid_manager

debug: my_pid_manager.c
	gcc -g $(CFLAGS) my_pid_manager.c -o ./debug/my_pid_manager$(LDFLAGS)
