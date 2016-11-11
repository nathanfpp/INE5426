int var: a
int fun: thisIsFun (params: int n, bool c)
  int var: i = 0
  switch: c
case: false
then:
  = n + n 1
case: true
then:
  = n + n 3
default: 
then:
  = n * n n
  end switch 
  ret n
= a thisIsFun[2 params] 2 true
$ R: a = 5
$ R: 234

