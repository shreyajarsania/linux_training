#!bin/sh

################################################################
#
# Write a program to perform floating point division
#
################################################################

# take input from user
echo Enter 2 float numbers

read num1 num2

div=`echo "scale=5;$num1 / $num2" | bc`

echo Division of $num1 and $num2 = $div
