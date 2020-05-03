#!/bin/sh
echo "start to build code"
if [ ! -f "test" ];then
	echo "no execed file"
else
	rm test
fi
gcc main.c -o test -W
echo "done built" `date`
