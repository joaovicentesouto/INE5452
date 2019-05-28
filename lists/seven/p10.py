# -*- coding: utf-8 -*-

while True:
    a, b, c, d = input().split()
    a = int(a)
    b = int(b)
    c = int(c)
    d = int(d)

    if (a + b + c + d) == 0:
        break
    
    x = c * (a/2 + b) / d

    print("%.5f" % x)