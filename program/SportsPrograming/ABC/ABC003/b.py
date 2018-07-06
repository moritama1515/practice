S = raw_input()
T = raw_input()

slist = ['a','t','c','o','d','e','r','@']
Ans = True
for i in range(len(S)):
  if Ans == False:
    break
  if T[i] == S[i]:
    continue
  else:
    if T[i] == '@' or S[i] == '@':
      if T[i] in slist:
        if S[i] in slist:
          continue
  Ans = False

if Ans == True:
  print "You can win"
else:
  print "You will lose"
