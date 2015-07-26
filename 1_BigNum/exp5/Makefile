cc = gcc
opt1 = -o LongInt
opt2 = -o BigNum -D_ope=2

LongInt: LongInt.c
	$(cc) $(opt1) LongInt.c

BigNum: BigNumMain.c BigNumLib.c
	$(cc) $(opt2) BigNumMain.c BigNumLib.c

Exp5-1: exp5-1.c BigNumLib.c
	$(cc) -o Exp5-1 exp5-1.c BigNumLib.c

Exp5-2: exp5-2.c BigNumLib.c
	$(cc) -o Exp5-2 exp5-2.c BigNumLib.c
