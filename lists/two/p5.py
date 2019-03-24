# -*- coding: utf-8 -*-

from sys import stdin

for line in stdin:
    plays = line.replace("\n", "").split(" ")

    if plays[0] == plays[1] and plays[0] == plays[2]:
        print("*")

    elif plays[0] != plays[1] and plays[0] != plays[2]:
        print("A")

    elif plays[1] != plays[0] and plays[1] != plays[2]:
        print("B")

    elif plays[2] != plays[0] and plays[2] != plays[1]:
        print("C")