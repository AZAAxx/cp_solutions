#does not work on a windows platform according to reddit
CC = g++
CFILES = *.c
OBJS = *.o


%.exe: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $@ $^

clean:
	rm $(CFILES) $(OBJS)