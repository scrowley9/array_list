
CFILES=main.c ArrayList.c

.PHONY: run run-valgrind

run:
	gcc $(CFILES) -o run -g

run-valgrind: run
	valgrind --leak-check=full --error-exitcode=1 --show-leak-kinds=all --errors-for-leak-kinds=all ./run

clean:
	rm run