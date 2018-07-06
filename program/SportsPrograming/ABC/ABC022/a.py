N,S,T = map(int,raw_input().split())
W = input()
A = []
ans = 0
weight = W
if weight >= S and weight <= T:
    ans += 1
for i in range(N-1):
    A.append(input())
    weight += A[i]
    if weight >= S and weight <= T:
        ans += 1
print ans
