# -*- coding: utf-8 -*-

from fractions import Fraction

a, b, c, d = input().split(' ')

x = Fraction(int(a), int(b))
y = Fraction(int(c), int(d))
z = x + y

print(z.numerator, z.denominator)