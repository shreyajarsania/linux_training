#!bin/sh

#####################################################################################
#
# Write a script to perform the following
#a) To count no.of processes which are running or ready in the system (Hint:- ps -e
#-o pid,ppid,cmd,stat, grep )
#b) List out foreground processes running in the system (ps suffix + in the state for
#the foreground processes)
#c) List out all processes whose parent is init
#
####################################################################################

# a)To count no.of processes which are running or ready in the system
echo total processes using prep
count=0
all_pro=`ps -e -o pid`
for process in $all_pro
do
	count=$(($count+1))
done
echo $count

echo total process using ppid
count=0
all_pro=`ps -e -o ppid`
for process in $all_pro
do
        count=$(($count+1))
done
echo $count

echo total processes using stat
count=0
all_pro=`ps -e -o stat`
for process in $all_pro
do
        count=$(($count+1))
done
echo $count

#b)List out foreground processes running in the system

echo total processess are :
ps -es | grep + | awk '{print $10}'


#c)List out all processes whose parent is init
echo total processes whose parent proccess is init
ps --ppid 1
