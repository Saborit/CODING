#!/bin/bash
for((i=1; ;++i))
do
  python gen.py>int
  
  echo "Testing Number:" $i
  
  .././a < int > out1 
  ./check < int > out2 
  
  if !(diff -w out1 out2) 
  then
	notify-send 'There is a Bug in Your Code!' \
	'Las salidas no concuerdan.' -u normal -t 10000 -i face-devilish
    break
  fi
done
