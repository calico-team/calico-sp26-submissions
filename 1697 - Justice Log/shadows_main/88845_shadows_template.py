def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
  """
  Return the maximal and minimal volume of the shape (in that order)
    
  N: max dimensions of shape
  S1: projection (shadow) in X-Z plane
  S2: projection (shadow) in Y-Z plane
  """
  #Maximum
  maxv = 0
  for i in range(N):
    bpr = 0
    for j in range(N):
      if(S2[i][j] == "#"):
        bpr+=1
    for j in range(N):
      if(S1[i][j] == "#"):
        maxv+=bpr
  s1_ttl = 0
  for i in range(N):
    for j in range(N):
      if S1[i][j] == "#": s1_ttl += 1
  s2_ttl = 0
  for i in range(N):
    for j in range(N):
      if S2[i][j] == "#": s2_ttl += 1
  if(maxv%2 == 0):
    return maxv,int((maxv/2))
  else:
    return maxv,max(s1_ttl,s2_ttl)


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
