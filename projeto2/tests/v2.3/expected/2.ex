int array: a (size: 5)
int var: i = 0
for: = i 0, < i 10, = i + i 1
do:
  switch: i
case: 1
then:
  = [index] a i i
case: 2
then:
  = [index] a i i
case: 3
then:
  = [index] a i i
case: 4
then:
  = [index] a i i
default: 
then:
  if: < i 5
  then:
    = [index] a 0 0
  end switch 
$ R: a(0) = 0
$ R: a(1) = 1
$ R: a(2) = 2
$ R: a(3) = 3
$ R: a(4) = 4

