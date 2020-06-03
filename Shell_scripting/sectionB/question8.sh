#!bin/sh

#############################################################################
#
# To check given year is leap or not
#
############################################################################

#take input from user
echo Enter the year
read year

if [ `expr $year % 4` == 0 ] &&  [ `expr $year % 100` != 0 ] || [ `expr $year % 400` == 0 ] 
then
	echo $year is a leap year
else
	echo $year is not a leap year
fi
exit 0
