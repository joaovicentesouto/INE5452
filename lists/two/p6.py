# -*- coding: utf-8 -*-

def insert_order(_list, _element):
	pos = 0

	for i in range(len(_list)):
		pos = i
		if _element[1] >= _list[i][1]:
			break

		if i == len(_list)-1:
			pos = len(_list)

	_list.insert(pos, _element)

board = []
amount = int(input())

for i in range(amount):
	line = input().split(" ")
	country = line.pop(0)
	medals = list(map(lambda x: int(x), line))

	insert_order(board, [country, medals])

for country in board:
	print("%s %d %d %d" % (country[0], country[1][0], country[1][1], country[1][2]))