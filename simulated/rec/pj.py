# -*- coding: utf-8 -*-

import re

n = int(input())

for i in range(n):

	match = re.match(r"([a-z]+)([0-9]+)([a-z]+)([0-9]+)([a-z]+)([0-9]+)", input(), re.I)
	
	items = match.groups()

	print(int(items[1]) + int(items[3]) + int(items[5]))