float:float hash: a
int:float hash: b
= [key] a 10.0 1.001
$ R: 1.901
= [key] b 33 + * [float] 22 [key] a 10.0 [float] 8
$ R: b(33) = 30.022
$ R: a(10) = 1.001
$ R: 30.022
$ R: 32.2
= [key] a [float] 10 [float] 2
int var: i = 5
float var: v = + [float] i [float] i
$ R: 2
$ R: a(10) = 2

