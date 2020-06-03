#!bin/sh

################################################################
#
# Write a script to check whether given argument is a regular 
# file or directory
#
################################################################

# take input from command line argument
if test -f "$1"
then
	echo "$1" is a regular file
elif test -d "$1"
then
	echo "$1" is a directory
else
	echo "$1" is neither a regular file nor a directory
fi
exit 0
