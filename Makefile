
CFILES=main.c ArrayList.c

run:
	gcc $(CFILES) -o run -g

clean:
	rm run