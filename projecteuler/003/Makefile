CC     = gcc

CFLAGS  = -Wall
LDFLAGS = -lm

SRC = $(notdir $(wildcard *.c))
BIN = $(patsubst %.c,%,$(SRC))

all: $(BIN)

clean: $(BIN)
	rm $^

.PHONY: clean
