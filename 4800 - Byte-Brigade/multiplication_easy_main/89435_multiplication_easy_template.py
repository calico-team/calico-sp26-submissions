from collections import deque
def solve(N, M, D, cells):
    """
    Return a tuple (A, discards) where:
      A: list of N integers in [1, 10^9]
      discards: list of at most D distinct 1-indexed cell indices to discard

    The discards output line will begin with t, the number of discarded
    cells, followed by those t indices; t is computed and written for
    you in main().

    N: length of the array A
    M: number of cells
    D: maximum number of cells you may discard
    cells: list of M tuples (R, C, V, W); for cell k (1-indexed), the product
           A[R] * A[C] should be close to the target V, with weight W
    """
    graph = [[] for _ in range(N)]
    for idx, (R, C, V, W) in enumerate(cells):
        R -= 1
        C -= 1
        graph[R].append((C, V, idx))
        graph[C].append((R, V, idx))

    A = [0]*N
    visited = [False]*N

    for start in range(N):
        if visited[start]:
            continue

        A[start] = 1
        visited[start] = True

        queue = deque([start])

        while queue:
            u = queue.popleft()

            for v,val,idx in graph[u]:
                if not visited[v]:
                    if A[u] != 0:
                        guess = val // A[u]
                        if guess <= 0:
                            guess = 1
                        if guess > 10**9:
                            guess = 10**9
                        A[v] = guess
                    else:
                        A[v] = 1
                    visited[v] = True
                    queue.append(v)

    errors = []
    for i, (R, C,V,W) in enumerate(cells):
        R -= 1
        C -= 1

        product = A[R] *A[C]
        error = W *abs(product - V) / V
        errors.append((error, i + 1))

    errors.sort(reverse=True)
    discards =[]
    for i in range(min(D, M)):
        discards.append(errors[i][1])

    return A,discards


def main():
    N, M, D = map(int, input().split())
    cells = []
    for _ in range(M):
        R, C, V, W = map(int, input().split())
        cells.append((R, C, V, W))
    A, discards = solve(N, M, D, cells)
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + list(discards)))


if __name__ == '__main__':
    main()
