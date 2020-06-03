#!bin/sh

################################################################
#
#.Use echo to list the all files of your home directory.
#
################################################################

# access all files in home using wildcard * 
for files in $(ls /home/*) 
do
	if [ -f $files ]
	then
		echo $files
	fi
done
exit 0
