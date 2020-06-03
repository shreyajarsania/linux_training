#!bin/sh

######################################################################
#
# Write a script to create 10 directories, say exam1,exam2,...,exam10
# Report
# error if a directory/file exists with same name.
#
#####################################################################

# for file from 1 to 10 check if exists
for files in 1 2 3 4 5 6 7 8 9 10
do
	if test -d "exam$files" 
	then
		echo exam$files already exits and cannot be created again
	else
		mkdir -v exam$files
	fi
done
exit 0
