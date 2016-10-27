int:int fun: myfun1 (params: bool b, int c)
  ret c
int:int hash: a
= a myfun1[1 params] a
= a myfun1[1 params] [null] a 3
int:int fun: myfun2 (params: bool b, int c)
  ret [ref] c
int:intd
= a [ref] myfun2[2 params] d a

