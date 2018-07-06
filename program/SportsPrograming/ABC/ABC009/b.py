N = input()
a = [raw_input() for i in range(N)]

b = list(set(a))
s_b = sorted(b,key=int,reverse=True)
print s_b[1]

