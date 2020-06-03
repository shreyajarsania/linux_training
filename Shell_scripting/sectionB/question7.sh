#!bin/sh

#############################################################################
#
# Write a script to print day of the week using a) elif b) case
#
############################################################################

#take input from user
echo Enter the day number
read day

echo "Output using elif"

if test $day -eq 1
then
	echo Monday
elif test $day -eq 2
then
	echo Tuesday
elif test $day -eq 3
then
	echo Wednesday
elif test $day -eq 4
then
	echo Thursday
elif test $day -eq 5
then
	echo Friday
elif test $day -eq 6
then
	echo Saturday
elif test $day -eq 7
then
	echo Sunday
else
	echo Enter number between 1 to 7
fi



echo "Output using case"

case "$day" in
	1) echo Monday;;
	2) echo tuesday;;
	3) echo wednesday;;
	4) echo thurday;;
	5) echo friday;;
	6) echo saturday;;
	7) echo sunday;;
	*) echo enter number between 1 to 7
esac		
exit 0
