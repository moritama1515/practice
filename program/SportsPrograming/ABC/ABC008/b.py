from collections import Counter

N = input()
a = [raw_input() for i in range(N)]

for word, cnt in Counter(a).most_common(1):
    print word
