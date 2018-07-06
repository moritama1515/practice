A = input()
B = input()
C = input()

list = [A,B,C]
list.sort(reverse=True)

print list.index(A)+1
print list.index(B)+1
print list.index(C)+1

