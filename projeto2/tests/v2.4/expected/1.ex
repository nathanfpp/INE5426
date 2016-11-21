int fun: somatorio (params: int p)
  int var: r = 1
  if: > p 1
  then:
    = r + somatorio[1 params] - p 1 p
  ret r
$ R: 6
$ R: 10

