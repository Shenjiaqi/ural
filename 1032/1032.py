n = input()
pre = [ -1 for x in xrange(n) ]
updated = [ -1 for x in xrange(n) ]

def pt ( v, cnt ) :
    if v == 0 and cnt > 0:
        print cnt
    else :
        pt( ( v - ( pre[v] % n ) + n ) % n, cnt + 1 )
        print pre[v]

pre[0] = 0
for i in xrange(n):
    v = int( raw_input() )
    for j in xrange(n) :
        if pre[j] >= 0 and updated[j] != i :
            t = ( j + v ) % n
            if pre[t] <= 0 :
                pre[t] = v
                updated[t] = i
                if t == 0 :
                    break
    if pre[0] > 0 :
        break

if pre[0] == 0:
    print 0
else:
    pt(0, 0)
