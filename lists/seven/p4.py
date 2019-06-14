# -*- coding: utf-8 -*-

def dice_roll(ev1, ev2, last1, last2, at, d, prob, deep = 0):
    if (deep > 30):
        return 0

    if ev1 <= 0:
        return 0

    if ev2 <= 0:
        return prob
    
    win  = 0
    lose = 0

    l1 = [last1[1], ev1]
    l2 = [last2[1], ev2]
    
    if ev1 == last1[0] and (ev1 - d) == last1[1]:
        win = 0
        lose = 0
    elif ev1 == last1[0] and (ev1 + d) == last1[1]:
        win = 0
        lose = 0
    else:
        win  = dice_roll(ev1 + d, ev2 - d, l1, l2, at, d, prob * (at / 6), deep+1)
        lose = dice_roll(ev1 - d, ev2 + d, l1, l2, at, d, prob * (1 - (at / 6)), deep+1)

    return win + lose

while (True):
    ev1, ev2, at, d = input().split()
    ev1 = int(ev1)
    ev2 = int(ev2)
    at  = int(at)
    d   = int(d)

    if not ev1 and not ev2 and not at and not d:
        break

    last1 = [ev1 + 2*d, ev1]
    last2 = [ev2 - 2*d, ev2]

    win  = dice_roll(ev1 + d, ev2 - d, last1, last2, at, d, (at / 6))

    last1 = [ev1 - 2*d, ev1]
    last2 = [ev2 + 2*d, ev2]

    lose = dice_roll(ev1 - d, ev2 + d, last1, last2, at, d, (1 - (at / 6)))

    prob = (win + lose) * 100

    print("%.1f" % prob)