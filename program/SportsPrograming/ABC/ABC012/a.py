l = map(int,raw_input().split())
tmp = l[0]
l[0] = l[1]
l[1] = tmp
print l[0],l[1]
