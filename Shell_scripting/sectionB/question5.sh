#!bin/sh

################################################################
#
#.___________
#a) Write a script to find biggest of three no.s
#b) To find avg of 3 no.s, read no.s from keyboard#
#
################################################################

#take input from user

echo Enter 3 numbers
read num1 num2 num3

if test $num1 -ge $num2 
then
	if test $num1 -ge $num3
	then
		echo $num1 is greater
	else
		echo $num3 is greater
	fi
else
	if test $num2 -ge $num3
	then
		echo $num2 is greater
	else
		echo $num3 is greater
	fi
fi
	
exit 0
