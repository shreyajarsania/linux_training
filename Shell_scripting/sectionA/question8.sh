#!bin/sh

#############################################################################
#
# Use echo to list the files of /proc/
#
############################################################################

#access all files using wildcard *i

for files in $(ls /proc/*)
do
        if [ -f $files ]
        then
                echo $files
        fi
done
exit 0
