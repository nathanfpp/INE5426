float double array fun: f1 (params: float [index][index] c 10 10)
  ret c
float array: a (size: 10, 10)
float array: b (size: 10, 10)
int var: i = 0, j = 0
for: = i 0, < i 10, = i + i 1
do:
  for: = j 0, < j 10, = j + j 1
  do:
    if: == i 0
    then:
      = [index][index] a i j [float] j
    else:
      = [index][index] a i j [float] i
$ R: a(0,8) = 8
$ R: a(1,1) = 1
$ R: a(2,2) = 2
$ R: a(3,3) = 3
$ R: a(4,4) = 4
$ R: a(5,5) = 5
$ R: a(6,6) = 6
$ R: a(7,7) = 7
$ R: a(8,8) = 8
$ R: a(9,9) = 9
$ R: a(2,9) = 2
= [index][index] b 10 10 [index][index] a 10 10
$ R: b(0,8) = 8
$ R: b(1,1) = 1
$ R: b(2,2) = 2
$ R: b(3,3) = 3
$ R: b(4,4) = 4
$ R: b(5,5) = 5
$ R: b(6,6) = 6
$ R: b(7,7) = 7
$ R: b(8,8) = 8
$ R: b(9,9) = 9
$ R: b(2,9) = 2

