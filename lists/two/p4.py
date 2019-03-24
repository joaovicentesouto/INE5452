# -*- coding: utf-8 -*-

amount = int(input())
order = []

for i in range(amount):
    number = int(input())

    number_is_even = number % 2 == 0

    pos = 0
    for j in range(len(order)):
        pos = j
        if number_is_even:
            if order[j] % 2 != 0:
                break
            elif number < order[j]:
                break
        else:
            if order[j] % 2 != 0:
                if number > order[j]:
                    break
        pos = j+1

    order.insert(pos, number)

for n in order:
    print(n)