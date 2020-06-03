#!bin/sh

#############################################################################
#
# Use echo to list the all files of /etc/ directory with extension name .conf
#
############################################################################

#access all files using wildcard *i

for files in $(ls /etc/*.conf)
do
        if [ -f $files ]
        then
                echo $files
        fi
done
exit 0

