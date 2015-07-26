cc = gcc
opt1 = -o LongInt
opt2 = -o BigNum -D_ope=2

LongInt: LongInt.c
	$(cc) $(opt1) LongInt.c

BigNum: BigNumMain.c BigNumLib.c
	$(cc) $(opt2) BigNumMain.c BigNumLib.c

Exp4-1: exp4-1.c BigNumLib.c
	$(cc) -o Exp4-1 exp4-1.c BigNumLib.c

Exp4-2: exp4-2.c BigNumLib.c
	$(cc) -o Exp4-2 exp4-2.c BigNumLib.c

Exp4-3: exp4-3.c BigNumLib.c
	$(cc) -o Exp4-3 exp4-3.c BigNumLib.c
