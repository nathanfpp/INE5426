int fun: divisaoRec (params: int p, int q)
  int var: r = 1
  if: < p q
  then:
    = r 0
  else:
    = r + divisaoRec[2 params] - p q q 1
  ret r
$ R: 6
$ R: 7
$ R: 8
$ R: 27

