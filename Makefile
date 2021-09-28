
CFILES=main.c ArrayList.c

run:
	gcc $(CFILES) -o run

clean:
	del /f run.exe