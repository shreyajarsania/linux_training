#!bin/sh

################################################################
#
# Write a program to check whether given no.is even or odd
#
################################################################

#take input from user

echo Enter a number to check odd or even
read num 

# check if input is odd or even
if test $(($num % 2)) == 0
then
	echo $num is even
else
	echo $num is odd
fi
exit 0
