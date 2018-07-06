S = raw_input()
listS = list(S)
N = input()
a = []
for i in range(N):
    a.append(map(int,raw_input().split()))
    listS[a[i][0]-1],listS[a[i][1]-1] = listS[a[i][1]-1],listS[a[i][0]-1]
    if a[i][0] != a[i][1]:
        for j in range((a[i][1]-a[i][0])/2):
            listS[a[i][0]-1+(j+1)],listS[a[i][1]-1-(j+1)] = listS[a[i][1]-1-(j+1)],listS[a[i][0]-1+(j+1)]
print ''.join(listS)
