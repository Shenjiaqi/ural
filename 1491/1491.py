n = input()
count = dict()
for i in xrange( 1, n + 1 ):
    count[i] = 0

def add( pos, num ):
    while pos <= n:
        count[pos] += num
        pos += ( pos & ( - pos ) )

def que( pos ):
    r = 0
    while pos > 0:
        r += count[pos]
        pos ^= ( pos & ( - pos ) )
    return r

for i in xrange( n + 1 ):
    a, b, c = map( int, raw_input().split() )
    add( a, c)
    add( b + 1, -c)

for i in xrange( 1, n + 1 ):
    print que(i),
