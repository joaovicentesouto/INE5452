# -*- coding: utf-8 -*-

amount = int(input())
board = []

for i in range(amount):
    board.append(int(input()))

for i in range(amount):
    bombs = 0
    
    if i > 0:
        bombs += board[i-1]

    if i < (amount-1):
        bombs += board[i+1]

    bombs += board[i]

    print(bombs)
