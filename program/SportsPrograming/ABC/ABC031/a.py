N = map(int,raw_input().split())

A = (N[0]+1)*N[1]
D = N[0]*(N[1]+1)

if A>=D:
    print A
else:
    print D
