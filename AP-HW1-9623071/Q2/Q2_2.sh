#!/bin/sh
filename="diction.txt"
while read -r line;do
echo $line

done< "$filename"