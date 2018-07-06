a = input()
b = input()

Ans = b - (a % b) 
if Ans == b:
    print 0
else:
    print Ans
