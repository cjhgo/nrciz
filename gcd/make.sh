#!/bin/sh
for cfile in *.c
do
	gcc  "$cfile" -o "${cfile%.c}"
done
