int var: c = 10
int fun: f1 (params: int p)
  = c 5
  int var: k = + 1000 p
  ret k
int fun: f2 (params: int p)
  int var: k = + 100 f1[1 params] p
  ret k
int fun: f3 (params: int p)
  int var: k = + 10 f2[1 params] p
  ret k
$ R: 1111
int fun: f (params: int x, int y)
  int var: a = + x y
  ret + + x y a
int var: b = 9
= b f[2 params] + 33 3 * b + b 2
$ R: c = 5

