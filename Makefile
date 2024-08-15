BASE_NAME=divedeeper

CC=gcc

SRC_C=$(BASE_NAME).c 

HEADERS= structdef.h combatfunc.h 

EXECUTABLE=$(BASE_NAME)

VALG=valgrind

CFLAGS= -g 

$(EXECUTABLE): $(SRC_C) $(HEADERS)
	$(CC) -o $(EXECUTABLE) $(SRC_C) $(HEADERS) $(CFLAGS)

clean:
	rm -f $(EXECUTABLE)