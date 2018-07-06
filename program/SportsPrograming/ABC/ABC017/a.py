a = []
for i in range(3):
    a.append(map(int,raw_input().split()))
ans = (a[0][0]*a[0][1]+a[1][0]*a[1][1]+a[2][0]*a[2][1])/10   
print ans
