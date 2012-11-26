#!/bin/sh

while getopts -t:b: opt
do
	case "$opt" in
		t) cell=$OPTARG;;
		b) base=$OPTARG;;
	esac
done

if diff $base $cell >/dev/null ; then
	echo "End-To-End test with $base passed\n"
	exit 0
else
	echo "End-To-End test with $base failed!!\n"
	exit 1
fi
