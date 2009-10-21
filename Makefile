CC     = gcc

CFLAGS  = -Wall
LDFLAGS = 

SRC = $(notdir $(wildcard *.c))
BIN = $(patsubst %.c,%,$(SRC))

all: $(BIN)

clean: $(BIN)
	rm $^

test: all
	@(rm  -f *~)
	@(sh ./autotest)

.PHONY: clean test
