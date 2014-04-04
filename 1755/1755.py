a1, b1, a2, b2 = map( int, raw_input().split() )
x, y = map( int, raw_input().split() )

def calY1( x1 ):
    return min( ( b2 * y + a2 * x - 2.0 * a2 * x1 ) / ( 2.0 * b2 ), y )

def cal1( x1, y1 ):
    return a1 * x1 + b1 * y1

if a2 == 0 :
    if b2 == 0 :
        print "0 0"
    else:
        print "0 %.8f" % ( y / 2.0 )
elif b2 == 0:
    print "%.8f 0" % ( x / 2.0 )
else:
    aX1 = min( x, ( a2 * x + b2 * y ) / ( 2.0 * a2 ) )
    aX2 = max( 0, ( a2 * x - b2 * y ) / ( 2.0 * a2 ) )
    aY1 = calY1( aX1 );
    aY2 = calY1( aX2 );
    if cal1( aX1, aY1 ) > cal1( aX2, aY2 ):
        print "%.8f %.8f" % ( aX1, aY1 )
    else:
        print "%.8f %.8f" % ( aX2, aY2 )
