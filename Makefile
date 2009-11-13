CC     = gcc

CFLAGS  = -Wall
LDFLAGS =  -lm

SRC = $(notdir $(wildcard *.c))
BIN = $(patsubst %.c,%,$(SRC))

all: help build

build: $(BIN)

help:
	@(echo "命令说明：")	
	@(echo "make               编译")
	@(echo "make help          显示帮助")
	@(echo "make update        更新代码")
	@(echo "make test          运行测试")
	@(echo "make clean         清除临时文件")
	@(echo "--------------------------------")

update:
	@(printf "\033[1;1m正在更新代码, 请稍候... \033[1;0m\n" >&2)
	@(a=$$(readlink Makefile); cd $${a%Makefile}; svn update)

clean:
	rm $(BIN)

test: build
	@(rm -f *~)
	@(sh ./autotest)

.PHONY: clean test help update
