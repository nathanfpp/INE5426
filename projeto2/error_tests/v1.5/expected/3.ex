int var: a
int fun: thisIsFun (params: int n, bool c)
  int var: i = 0
  switch: c
case: [int] false
then:
  int var: d = 9
  = n + n 1
case: true
then:
  int var: d = 93
  = n + n 3
default: 
then:
  int var: d = 3
  = n * n n
  end switch 
  ret n

