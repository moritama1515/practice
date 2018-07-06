import sys
W,H=map(int,raw_input().split())
if W % 4 == 0:
    if H % (W/4) == 0:
        print '4:3' 
        sys.exit()        
print '16:9'
