CC=gcc
CFLAGS=-g -Wall
ntpsync:	ntpsync.c
		$(CC) $(CFLAGS) $< -o $@
