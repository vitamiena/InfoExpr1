#! /bin/sh

#val=(10 20 30 40 50 60 70 80 90 100)
val=(21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40)

for i in ${val[@]}
do
    echo "./exp04_2dp $1 $2 $3 $i $i $i"
    ./exp04_2dp $1 $2 $3 $i $i $i
done

# echo ""
# echo "./exp04_3memo $1 $2 $3"
# ./exp04_3memo $1 $2 $3
