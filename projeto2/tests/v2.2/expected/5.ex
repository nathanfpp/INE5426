int:int hash: a
float:int hash: b
= [key] a [int] 10.0 [int] 1.001
$ R: 1
= [key] b [float] 33 [int] + * 22.46 [float] [key] a [int] 10.0 [float] 8
$ R: b(33) = 30
$ R: 30
= [key] a [int] 10 2
float var: f = [float] 5
int var: v = [int] + f [float] [int] f
$ R: 1
$ R: a(10) = 1
$ R: 1

