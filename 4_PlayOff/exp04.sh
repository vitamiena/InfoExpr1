#! /bin/sh

val=(10 20 30 40 50 60 70 80 90 100)

for i in ${val[@]}
do
    echo "./exp04_2dp $1 $2 $3 $i $i $i"
    ./exp04_2dp $1 $2 $3 $i $i $i
done
