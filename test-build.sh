#!/bin/bash
echo "Running one-time setup..."
mkdir -p ~./mutt/cache/headers
mkdir ~/.mutt/cache/bodies
touch ~/.mutt/certificates

cp ./temp ~/.muttrc

echo "Pulling latest build..."
git pull

echo "Testing build..."
make test-build > build.log 2>&1

if grep -Fxq "Error"
then
	echo "Sending email..."
	mutt -a build.log -s "Build error!" $(cat emails) < build.log
else
	mutt -S "All tests fine" $(cat emails) < build.log
	echo "Tests seem to have passed."
fi
