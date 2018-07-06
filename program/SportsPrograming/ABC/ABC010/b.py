N = input()
l = map(int,raw_input().split())

def calc_amari(n):
    return n % 6

ans = 0
ansl = list(map(calc_amari,l))
for i in range(N):
    if ansl[i] == 0:
        ans+=3
    elif ansl[i] == 2:
        ans+=1
    elif ansl[i] == 4:
        ans+=1
    elif ansl[i] == 5:
        ans+=2
        
print ans
