#!/bin/bash

FILE=number;
LOCK=numbers.lock;

if [ ! -f $FILE ]; then
  echo "0" >> $FILE;
fi

while true
do
# to avoid race condition we check if file LOCK exists
# if yes then the critical region is occupied by other process
# and we exit from the scenario
	if [ -f $LOCK ]; then
		exit 150
	else
		touch $LOCK

		NUMBER=$(tail -n 1 $FILE)
		NEWNUMBER=$((NUMBER + 1));
		echo $NEWNUMBER >> $FILE;
		rm -f $LOCK
	fi
done