import sys
L = map(int,raw_input().split())

for i in range(3): 
    if L.count(L[i])==1:
        print L[i]
    elif L.count(L[i])==3:
        print L[i]
        sys.exit()
