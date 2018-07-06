N = input()

a,b,c = 0,0,1
m = 0
while m < N:
    ans = a
    c = c % 10007
    a,b,c = b,c,(a+b+c)
    m += 1

print ans % 10007


