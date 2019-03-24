# -*- coding: utf-8 -*-

def _sort(_list, _pilot, _points):
	position = 0
	for i in range(len(_list)):
		if _list[i][1] < _points:
			break
		
		elif _list[i][1] == _points:
			if _pilot < _list[i][0]:
				break
		
		position = i+1
	
	_list.insert(position, [_pilot, _points])


while True:
	G, P = input().split(" ")
	G = int(G)
	P = int(P)

	if G == 0 and P == 0 :
		break;
	
	awards  = []
	systems = []

	for i in range(G):
		awards.append(list(map(lambda x: int(x), input().split(" "))))
	
	S = int(input())
	for i in range(S):
		system = list(map(lambda x: int(x), input().split(" ")))
		Last = system.pop(0)

		sys_awards = awards

		sys_awards = list(
			map(lambda _list:
				list(
					map(lambda x: if x <= Last: sys_awards)
					)
			)
		)

		Last = system.pop(0)
		points = [0] * P

		for l in range(G):
			for j in range(Last):
				for k in range(P):
					if (awards[l][k] == (j+1)):
						points[k] = points[k] + system[j]
		
		order = []
		for p in range(P):
			_sort(order, p, points[p])
		
		max_points = 0
		for pilot in order:
			if max_points <= pilot[1]:
				max_points = pilot[1]
				print("%d " % (pilot[0]+1), end='')
			else:
				break
		print("")

