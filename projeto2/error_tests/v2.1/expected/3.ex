int array fun: f1 (params: int array [index] b 10)
  int var: i, j = 0
  for: = i 0, < i 10, = i + i 1
  do:
    = [index] b i i
  ret b
int array: a (size: 10)
= a + a f1[1 params] a
$ R: 0
$ R: 0
$ R: 0
$ R: 0
$ R: 0
$ R: 0
$ R: 0
$ R: 0
$ R: 0
$ R: 0

