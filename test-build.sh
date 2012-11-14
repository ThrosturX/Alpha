#!/bin/bash
echo "Testing build..."
make build > build.log 2>&1

echo "Build completed"


if grep -Fxq "Error"
then
	echo "Sending email..."
	mutt -a build.log -s "Build error!" $(cat emails) < build.log
else
	mutt -S "All tests fine" $(cat emails) < build.log
	echo "Tests seem to have passed."
fi
