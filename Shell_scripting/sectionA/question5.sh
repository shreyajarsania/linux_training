#!bin/sh

################################################################
#
# Use echo to list the all files of /etc/ directory
#
################################################################

#access all files using wildcard *

for files in $(ls /etc/*)
do
	if [ -f $files ]
	then
		echo $files
	fi
done
exit 0
