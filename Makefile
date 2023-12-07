CC = gcc
CFLAGS = -Wall -Wextra
SRCS = main.c
OBJS = ${SRCS:.c=.o}
MAIN = main.bin

$(MAIN) : ${OBJS}
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) *.o *~ $(MAIN)
