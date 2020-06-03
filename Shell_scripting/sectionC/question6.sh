#!bin/sh

#############################################################################
#
# Write a script to check each entry of a directory is a file or directory.
#
############################################################################

# check for all files in the current directory
for check in *
do
	if test -f "$check"
	then
        	echo "$check" is a regular file
	elif test -d "$check"
	then
        	echo "$check" is a directory
	else
        	echo "$check" is neither a regular file nor a directory
	fi
done
exit 0

