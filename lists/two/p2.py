# -*- coding: utf-8 -*-

from sys import stdin

letters = {1: 'A', 2: 'B', 3: 'C', 4: 'D', 5: 'E'}

while True:
    amount = int(input())

    if not amount:
        break

    for i in range(amount):
        answers = list(map(lambda x: int(x), input().split()))
        markeds = []
        
        for j in range(5):
            if answers[j] <= 127:
                markeds.append(j+1)

        if len(markeds) == 1:
            print(letters[markeds[0]])
        else:
            print("*")

