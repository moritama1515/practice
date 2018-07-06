import sys
N = input()
NG1 = input()
NG2 = input()
NG3 = input()

if N == NG1 or N == NG2 or N == NG3:
    print 'NO'
    sys.exit()

for i in range(100):
    N = N - 3
    if N == NG1 or N == NG2 or N == NG3:
        N = N + 1
        if N == NG1 or N == NG2 or N == NG3:
            N = N + 1 
            if N == NG1 or N == NG2 or N == NG3:
                print 'NO'
                sys.exit()


if N <= 0:
    print 'YES'
else:
    print 'NO'
