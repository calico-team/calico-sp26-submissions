Python 3.12.0 (tags/v3.12.0:0fb18b0, Oct  2 2023, 13:03:39) [MSC v.1935 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> T = int(input())
... for _ in range(T):
...     S = input()
...     A = input()
...     result = ""
...     j = 0
...     for i in range(len(S)):
...         if j < len(A) and S[i] == A[j]:
...             result += S[i]
...             j += 1
...         else:
...             result += "-"
...     print(result)
... def read_your_input():
