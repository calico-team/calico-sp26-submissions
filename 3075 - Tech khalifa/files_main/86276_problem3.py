import io
import sys

# Reset input to default first!
if 'input' in dir(__builtins__):
    del __builtins__.input

test_input = """5
ccaalliiccoo
calico
big_bens_bday
bbb
job
jb
include_over_californication
ilovecalico
six_seven_rizzler_sigma_banned_discord_skibidi_toilet
severance
"""

sys.stdin = io.StringIO(test_input)
input = sys.stdin.readline  # rebind cleanly

T = int(input())
for _ in range(T):
    S = input().strip()
    A = input().strip()
    
    r = []
    g = 0
    v = len(A)
    
    for j in range(len(S)):
        if g < v and S[j] == A[g]:
            r.append(S[j])
            g += 1
        else:
            r.append('-')
    
    print("".join(r))