int:int hash: a, b
int var: c
= c + [key] a 1 [key] b 2
= c [key] a [key] a 1
int array: values (size: 100)
= c [index] values [index] values 12
= c [index] values 5
int array: v (size: 20, 20)
= c [index][index] v 5 5
= c [index][index] v [index][index] v 1 1 5
= c [index][index] v [index][index] v 1 1 [key] a 1
= c [index][index] v [index][index] v 1 1 [index][index] v 1 1
int fun: f (params: int x)
  ret 0
= c f[1 params] f[1 params] 0
