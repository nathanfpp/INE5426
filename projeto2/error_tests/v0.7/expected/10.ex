integer double array fun: f0 (params: )
  int array: a (size: 10, 10)
  ret a
integer double array fun: f1 (params: )
  int array: a (size: 10)
  ret a
integer double array fun: f2 (params: )
  int var: a
  ret a
integer double array fun: f3 (params: int [index][index] a 10 10)
  ret a
integer double array fun: f4 (params: int [index] a 10)
  ret a
integer double array fun: f5 (params: int a)
  ret a
int array: a (size: 10, 10), b (size: 10), c
= a f0[0 params]
= a f1[0 params]
= a f2[0 params]
= a f3[1 params] a
= a f4[1 params] b
= a f5[1 params] c
= b f0[0 params]
= b f1[0 params]
= b f2[0 params]
= b f3[1 params] a
= b f4[1 params] b
= b f5[1 params] c
= c f0[0 params]
= c f1[0 params]
= c f2[0 params]
= c f3[1 params] a
= c f4[1 params] b
= c f5[1 params] c

