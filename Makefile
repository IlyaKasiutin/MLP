C_SOURCES = $(wildcard matrix/*.c network/*.c images/*.c *.c)
HEADERS = $(wildcard matrix/*.h network/*.h images/*.h *.h)
OBJ = ${C_SOURCES:.c=.o}
CFLAGS = 

MAIN = main
CC = /usr/bin/gcc
LINKER = /usr/bin/ld

run: ${MAIN}
	./${MAIN}

main: ${OBJ}
	${CC} ${CFLAGS} $^ -o $@ -lm

# Generic rules
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@ -lm

clean:
	rm matrix/*.o *.o neural/*.o util/*.o ${MAIN}