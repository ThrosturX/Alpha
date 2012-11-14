#!/bin/bash
echo "Pulling latest release..."
git pull

echo "Testing build..."
make build > build.log 2>&1

echo "Build completed"


if grep -Fxq "Error" build.log
then
	echo "Sending email..."
	mutt -a build.log -s "Build error!" $(cat emails) < build.log
else
	mutt -s "All tests fine" $(cat emails) < build.log
	echo "Tests seem to have passed."
fi

rm -rf build.log
