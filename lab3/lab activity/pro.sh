#!/bin/bash
echo "Entre Number1"
read num1
echo "Entre Number2"
read num2
pro=0
for((i=1;i<=$num1;i++))
do
pro=`expr $pro + $num2`
done
echo $pro
