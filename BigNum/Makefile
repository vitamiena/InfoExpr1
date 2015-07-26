cc = gcc
opt1 = -o LongInt
opt2 = -o BigNum

LongInt: LongInt.c
	$(cc) LongInt.c $(opt1)

BigNum: BigNumMain.c BigNumLib.c
	$(cc) BigNumMain.c BigNumLib.c $(opt2)
