import sys
N = raw_input()

if int(N) != 0:
    if int(N) % 1111 != 0:
        print 'DIFFERENT'
        sys.exit()
print 'SAME'
