a, b, n = map( int, raw_input().split() )
ans = 0
for i in xrange(n):
    ra = min( a - 1 - ( i % a ), n - i - 1 )
    rb = min( b - 1 - ( i % b ), n - i - 1 )
    ans += max( ra - rb, 0 )
#    print max( ra - rb, 0 ), i, ra, rb

print ans
