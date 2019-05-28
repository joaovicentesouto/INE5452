# -*- coding: utf-8 -*-

a, b = input().split()
a = int(a)
b = int(b)

c = b * (b + 1) / 2 - a * (a - 1) / 2

print(round(c))