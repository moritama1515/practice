N = input()
x = 0
if N % 2 == 0:
    while N > 0:
        N = N-2
        x+=1
    print x
    for i in range(x):
        print 2
else:
    N = N - 1
    while N > 0:
        N = N-2
        x+=1
    print x+1
    print 1
    for i in range(x):
        print 2
