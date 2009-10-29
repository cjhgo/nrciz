CC     = gcc

CFLAGS  = -Wall
LDFLAGS = -lgmp

SRC = $(notdir $(wildcard *.c))
BIN = $(patsubst %.c,%,$(SRC))

all: $(BIN)

clean: $(BIN)
	rm $^

.PHONY: clean
