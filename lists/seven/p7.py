# -*- coding: utf-8 -*-
import math

result = ""
rounds = int(input())
lucas = 0
pedro = 0

for i in range(rounds):

    a, b = input().split("^")
    a = int(a)
    b = int(b)
    n = int(input()[:-1])

    exp = b * math.log10(a)

    fact = 1

    while n > 0 and fact < exp:
        fact += math.log10(n)
        n -= 1
    
    if n:
        pedro += 1
        result += "Rodada #" + str(i+1) + ": Pedro foi o vencedor\n"
    else:
        lucas += 1
        result += "Rodada #" + str(i+1) + ": Lucas foi o vencedor\n"

if lucas == pedro:
    print("A competicao terminou empatada!")
elif lucas < pedro:
    print("Campeao: Pedro!")
else:
    print("Campeao: Lucas!")

print(result, end="")