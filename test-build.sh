#!/bin/bash
echo "Pulling latest build..."
git pull

echo "Testing build..."
make test-build > build.log 2>&1

if grep -Fxq "Error"
then
	echo "Sending email..."
	mutt -a build.log -s "Build error!" $(cat emails)
else
	echo "Tests seem to have passed."
fi
