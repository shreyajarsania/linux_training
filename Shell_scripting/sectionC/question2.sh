#!bin/sh

###################################################################
#
# Write a menu based script to perform following string operations
# a) To find length of a string
# c) Copying string
# d) Concatenation of strings
# e) Comparison of two strings
# f) Reversing a string
#
###################################################################

# take input from user
echo Enter 1st string
read string1
echo Enter 2nd string
read string2

#a) length of string
length=`expr length "${string1}"`
echo Length of 1st string is $length
length=`expr length "${string2}"`
echo Length of 2ndst string is $length

#c) copying string into another
copy_string="${string1}"
echo Copying string 1 to another string - $copy_string

#d) concatenation of two string
string_other="${string1} ${string2}"
echo Concating two strings to another string - $string_other

#e)Compare string
if [ "$string1" == "$string2" ]
then
	echo same
else
	echo different
fi

#f)reversing a string

string_rev1=`echo $string1 | rev`
string_rev2=`echo $string2 | rev`
echo $string_rev1
echo $string_rev2
