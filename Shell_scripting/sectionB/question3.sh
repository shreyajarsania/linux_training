#!bin/sh

################################################################
#
# Write a program to print calendar of current month in next year
# ,previous years. For eg:- sep 2014,sep 2012 if current month 
# is sep 2013
#
################################################################

# take input from user
set $(date)

echo $(date)

echo calender of this year for $2 month is: 
cal  $2 $6

echo "calender of pervious year for $2 month is :"
year=$6
cal $2 `expr $year - 1` 

echo "calender of next year for $2 month is :"
cal $2 `expr $year + 1`
exit 0
