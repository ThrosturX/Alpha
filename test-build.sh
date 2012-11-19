#!/bin/bash
echo "Pulling latest build..."
git pull

echo "Testing build..."
make test-build > build.log 2>&1


