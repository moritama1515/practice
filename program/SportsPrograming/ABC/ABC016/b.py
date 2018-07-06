N = map(int,raw_input().split())

A = N[0]
B = N[1]
C = N[2]

if (A + B) == C:
    if (A - B) == C:
        print "?"
    else:
        print "+"
else:
    if (A - B) == C:
        print "-"
    else:
        print "!"
