#! /bin/sh

val=(0 10 20 30 40 50 60 70 80 90 100)

for i in ${val[@]}
do
    echo "./exp04_2dp 400 15 20 $i $i $i"
    ./exp04_2dp 400 15 20 $i $i $i
done
