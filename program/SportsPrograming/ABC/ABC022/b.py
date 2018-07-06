ans = 0
hist =[0]*100001
for i in range(input()):
    x = input()
    if hist[x] > 0:
        ans += 1
    hist[x] = 1
print ans
