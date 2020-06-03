#!bin/sh

################################################################
#
# Write a program to find sum and product of two no.s using 
# a) expr b) let c) bc
#
################################################################

# take input from user

echo Enter two numbers

read num1 num2

# using expr
sum_expr=`expr $num1 + $num2` 
echo "Sum using expr = $sum_expr"

#using let
let "sum_let = $num1 + $num2"
echo "Sum using let = $sum_let"

#using bc
sum_bc=`echo "$num1 + $num2" | bc`
echo -n "Sum using bc = $sum_bc"
