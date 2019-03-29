# -*- coding: utf-8 -*-

while True:
    
    _init = input()
    print(_init)

    n, m = _init.split(" ")
    n = int(n)
    m = int(m)

    if not n and not m:
        break

    order = []
    for i in range(n):
        order.append(int(input()))
    
    def _sort(x):
        module = 0
        even = 0
        if x >= 0:
            module = x % m
            even = x % 2 == 0
        else:
            module = -((-x) % m)
            even = x % 2 != 0

        diff = 0
        if even:
            diff = x
        else: # odd
            diff = -x

        return module * 10000 + even * 100 + diff
    
    order = sorted(order, key=_sort)
    for number in order:
        print(number)
