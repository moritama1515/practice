a = input()
b = input()

if a < b:
    print min(b-a,a+10-b)
else:
    print min(a-b,10-a+b)
