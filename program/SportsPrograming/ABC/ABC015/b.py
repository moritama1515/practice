import math
N = input()
bag = map(int,raw_input().split())

A = N
SUM = 0
for i in range(N):
    if bag[i] == 0:
        A -= 1
    SUM += bag[i]

ans = SUM*1.0 / A
print int(math.ceil(ans))

        
