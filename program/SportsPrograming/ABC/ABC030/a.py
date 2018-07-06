N = map(int,raw_input().split())

TAKAHASHI = N[1]*1.0/N[0]
AOKI = N[3]*1.0/N[2]

if AOKI > TAKAHASHI:
    print "AOKI"
elif AOKI < TAKAHASHI:
    print "TAKAHASHI"
else:
    print "DRAW"
