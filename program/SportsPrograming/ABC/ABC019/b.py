s = raw_input()
listS = list(s)
listS.append('?')
flag = 1
ans = []
for i in range(len(listS)-1):
    if listS[i] == listS[i+1]:
        flag+=1
    else:
        ans.append(listS[i]+str(flag))
        flag = 1
print ''.join(ans)
    
        
