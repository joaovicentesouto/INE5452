# -*- coding: utf-8 -*-
import math
from sys import stdin

for line in stdin:
    r, la, lo = line.split()
    r  = float(r)
    la = math.radians(float(la))
    lo = math.radians(float(lo))

    x = r * math.sin(la) * math.cos(lo)
    y = r * math.sin(la) * math.sin(lo)
    z = r * math.cos(la)

    print(round(x, 2), round(y, 2), round(z, 2))
