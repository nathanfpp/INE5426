int var: count = 0
int fun: sum (params: int [index] vector 10, int tamanho)
  int var: r = 0
  = count + count 1
  if: > tamanho 0
  then:
    = r + [index] vector - tamanho 1 sum[2 params] [index] vector 10 - tamanho 1
  ret r
int array: a (size: 10)
int array: b (size: 10)
int var: i
for: = i 0, < i 10, = i + i 1
do:
  = [index] a i i
  = [index] b i * i i
$ R: 45
$ R: 285
$ R: count = 22

