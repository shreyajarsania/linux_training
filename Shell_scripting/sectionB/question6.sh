#!bin/sh

#############################################################################
#
# Write a script to check type of a traingle.Sides of the triangle should be 
# provided as command line arguments.
#
############################################################################

# take 1st 2nd and 3rd argument to check the lengths

# if all lengths are equal- equilateral triangle
if [ ${1} -eq ${2} ] && [ ${1} -eq ${3} ]
then
	echo This is eqilateral triangle
#if any 2 side are same - isosceles
elif [ ${1} -eq ${2} ] || [ ${1} -eq ${3} ] || [ ${2} -eq ${3} ]
then
	echo This is Isosceles triangle
else
#if no side are same - scalene
	echo This is scalene triangle
fi
exit 0
