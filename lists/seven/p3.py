# -*- coding: utf-8 -*-
from math import trunc
from sys import stdin

t = 0
v = 0
rolled = 0

for line in stdin:
    list = line.split(" ")

    clock = list[0]

    vi = ""
    if len(list) == 2:
        vi = list[1]

    h, m, s = clock.split(":")

    ti = int(h) * 3600 + int(m) * 60 + int(s)
    
    rolled += (ti - t) * v
    t = ti

    if vi == "":
        s = str(t % 60)
        m = str(trunc((t / 60) % 60))
        h = str(trunc((t / 3600) % 60))

        s = s if (len(s) > 1) else ("0" + s)
        m = m if (len(m) > 1) else ("0" + m)
        h = h if (len(h) > 1) else ("0" + h)

        print("%s:%s:%s %.2f km" % (h, m, s, round(rolled, 2)))
    else:
        v = int(vi) / 3600
