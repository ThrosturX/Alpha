#!/bin/sh

e2e=test/e2e
rel=release/TicTacToe
bas=$e2e/base
res=$e2e/res

$rel < $bas/test_1.in > $res/test_1.out
$rel < $bas/test_2.in > $res/test_2.out

if ! $e2e/cmp.sh -b $bas/test_1.out -t $res/test_1.out ; then
	exit 1;
fi

if ! $e2e/cmp.sh -b $bas/test_2.out -t $res/test_2.out ; then
	exit 1;
fi

exit 0;
