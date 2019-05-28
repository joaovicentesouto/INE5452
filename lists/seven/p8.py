# -*- coding: utf-8 -*-
import math

cases = int(input())

for i in range(cases):
    n, m = input().split()
    n = int(n)
    m = int(m)

    # r = 2 * m * math.factorial(n - m)
    r = 2 * m * (math.factorial(n) // (math.factorial(m) * math.factorial(n - m)))

    print(r % 1300031)
   