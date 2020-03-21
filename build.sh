#!/bin/sh
echo "start to build code"
if [ ! -f "test" ];then
	echo "no execed file"
else
	echo "execed file existed"
	rm test
fi
gcc main.c -o test -W
echo "end for building code"
