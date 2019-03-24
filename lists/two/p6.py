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

# for country in board:
# 	print("%s " % country[0], end="")
# 	for medal in country[1]:
# 		print("%s " % medal, end="")
# 	print("")

for i in range(len(board)-1):
	print(board[i][0], end=" ")
	for medal in board[i][1]:
		print(medal, end=" ")
	print("")

print(board[-1][0], end=" ")
for medal in board[-1][1]:
	print(medal, end=" ")
print("")
