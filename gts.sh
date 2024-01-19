#!/bin/bash

echo "git add . "
git add . 
echo "git commit -m \"$1\""
git commit -m "$1"
echo "git pull -r"
git pull -r
echo "git push "
git push 



