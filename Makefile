# Makefile created by watson on 03/05/2020
# Standard format 

CC = gcc
RM = rm
SRC = $(wildcard *.c)
OBJS = $(patsubst %c, %o, $(SRC))
TARGET = test


all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^
%o:%c
	$(CC) -c $^
clean:
	$(RM) -f $(OBJS) $(TARGET)

.PHONY:all clean
