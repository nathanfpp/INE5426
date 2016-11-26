int var: a = 0
int fun: fibonacci (params: int p)
  = a + a 1
  int var: r = 1
  if: > p 1
  then:
    = r + fibonacci[1 params] - p 2 fibonacci[1 params] - p 1
  ret r
$ R: 5
$ R: 8
$ R: 13
$ R: a = 49

