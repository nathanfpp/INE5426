float double array fun: f1 (params: float double array [index][index] c 10 10)
  ret [index][index] c 10 10
float array: a (size: 10, 10)
float array: b (size: 10, 10)
int var: i = 0
for: = i 0, < i 10, = i + i 1
do:
  = [index][index] a i i [float] i
$ R: 0
$ R: 1
$ R: 2
$ R: 3
$ R: 4
$ R: 5
$ R: 6
$ R: 7
$ R: 8
$ R: 9
= [index][index] b 10 10 [index][index] c 10 10
$ R: 0
$ R: 1
$ R: 2
$ R: 3
$ R: 4
$ R: 5
$ R: 6
$ R: 7
$ R: 8
$ R: 9

