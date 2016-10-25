int array: a (size: false)
int array: b (size: true)
int array: c (size: 20, false)
int array: d (size: false, 30)
int array: e (size: false, false)
int array: f (size: 10, 10)
int array: g (size: 10)
int array: y (size: 10, 20), w (size: 10, true)
= [index] a false 1
= [index][index] f 10 10 [index] g true true
= [index][index] f 10 10 [index] g true
= [index] g 10 [index][index] f true 10
= [index] g 10 10 [index][index] f 10
= [index][index] f true 10 [index] g true true
= [index][index] f 10 10 [index] g true
= [index] g 10 [index][index] f true 10
= [index] g 10 true [index][index] f 10

