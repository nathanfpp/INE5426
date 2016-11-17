int array: a (size: 5)
int var: i = 0
for: = i 0, < i 10, = i + i 1
do:
  switch: i
    case: 1
    then:
      = [null] a i i
    case: 2
    then:
      = [null] a i i
    case: 3
    then:
      = [null] a i i
    case: 4
    then:
      = [null] a i i
    default: 
    then:
      if: < i 5
      then:
        = [index] a 0 0
  end switch 

