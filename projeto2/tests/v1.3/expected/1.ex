int array: b (size: 10)
= [index] b 1 3
int array: a (size: 10, 10)
int var: i, j
for: = i 0, < i 10, = i + i 1
do:
  for: = j 0, < j 10, = j + j 1
  do:
    = [index][index] a i j + i j

