# -*- coding: utf-8 -*-

rafael = lambda x, y : pow(3 * x, 2) + pow(y, 2)
beto   = lambda x, y : 2 * pow(x, 2) + pow(5 * y, 2)
carlos = lambda x, y : -100 * x + pow(y, 3)

n = int(input())

for _ in range(n):
    x, y = input().split()
    x = int(x)
    y = int(y)

    answer = "Rafael ganhou"

    if beto(x, y) > rafael(x, y):
        if beto(x, y) > carlos(x, y):
            answer = "Beto ganhou"
        else:
            answer = "Carlos ganhou"
    elif carlos(x, y) > rafael(x, y):
        answer = "Carlos ganhou"

    print(answer)