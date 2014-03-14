n = input()
# red or white
v = 1
# blue 
pre = 0
for i in xrange(n - 1):
    tmp = v
    v += pre
    pre = tmp
print v * 2
