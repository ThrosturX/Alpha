#!/bin/bash
cd ~/git/Alpha
echo "Pulling latest release..."
git pull

echo "Build log" > build.log
echo "Testing build..."
make test-build >> build.log 2>&1

echo "Build completed"


if grep -Fxq "Error" build.log
then
	echo "Sending email..."
	mutt -a build.log -s "Build error!" $(cat emails) < build.log
else
	echo "Tests seem to have passed."
fi

rm -rf build.log
