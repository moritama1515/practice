N,A,B = map(int,raw_input().split())
a = []
for i in range(N):
    a.append(raw_input().split())

P = 0
Move = 0
for i in range(N):
    if int(a[i][1]) < A:
        Move = A
    elif B < int(a[i][1]):
        Move = B
    else:
        Move = int(a[i][1])
    if a[i][0] == 'East':
        P -= Move
    else:
        P += Move
if P > 0:
    print 'West '+str(P)
elif P < 0:
    print 'East '+str(P*(-1))
else:
    print P

