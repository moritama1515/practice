S = map(int,raw_input().split())
N = map(int,raw_input().split())

ans = S[0]*N[0] + S[1]*N[1]
if N[0]+N[1] >= S[3]:
    print ans - (N[0]+N[1])*S[2]
else:
    print ans
