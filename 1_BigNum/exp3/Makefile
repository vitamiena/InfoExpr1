cc = gcc
opt1 = -o LongInt
opt2 = -o BigNum -D_ope=2

LongInt: LongInt.c
	$(cc) $(opt1) LongInt.c

BigNum: BigNumMain.c BigNumLib.c
	$(cc) $(opt2) BigNumMain.c BigNumLib.c

Exp3-01: exp3-01.c BigNumLib.c
	$(cc) -o Exp3-01 exp3-01.c BigNumLib.c

Exp3-03: exp3-03.c BigNumLib.c
	$(cc) -o Exp3-03 exp3-03.c BigNumLib.c

Exp3-04: exp3-04.c BigNumLib.c
	$(cc) -o Exp3-04 exp3-04.c BigNumLib.c

Exp3-05: exp3-05.c BigNumLib.c
	$(cc) -o Exp3-05 exp3-05.c BigNumLib.c

Exp3-06: exp3-06.c BigNumLib.c
	$(cc) -o Exp3-06 exp3-06.c BigNumLib.c

Exp3-07: exp3-07.c BigNumLib.c
	$(cc) -o Exp3-07 exp3-07.c BigNumLib.c

Exp3-08: exp3-08.c BigNumLib.c
	$(cc) -o Exp3-08 exp3-08.c BigNumLib.c
