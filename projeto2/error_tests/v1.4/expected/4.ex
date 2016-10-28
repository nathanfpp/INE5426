int:int fun: myfun1 (params: bool:bool b, int [index] c 10)
  ret c
int:int hash: a
= a myfun1[1 params] a
= a myfun1[1 params] [null] a 3
int:int fun: myfun2 (params: bool:int b, int:int c)
  ret [ref] c
int:int ref hash: d
= d [ref] myfun2[2 params] d a

