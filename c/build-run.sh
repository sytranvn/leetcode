#!/usr/bin/env bash

PROB=$1
FLAGS=${FLAGS:-}

if [ ! -d "$PROB" ]; then
	echo "$1 must be a directory"
	exit 1
fi

if [ ! -f "$PROB/$PROB.c" ]; then
	echo "$PROB/$PROB.c file not found"
	exit 1
fi

gcc ${FLAGS} "$PROB/$PROB.c" -o "./bin/$PROB"

for f in $PROB/in*; do
	"./bin/$PROB" < "$f" | diff ${f/in/out} -
	if [ "$?" -ne 0 ]; then 
		echo $f Failed 
		exit 1
	else
		echo $f Passed 
	fi
done

echo OK
