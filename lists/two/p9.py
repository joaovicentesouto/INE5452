# -*- coding: utf-8 -*-

from sys import stdin

for line in stdin:
    ns = list(map(lambda x: int(x), line.replace("\n", "").split(" ")))
    
    order = "X"
    for i in range(len(ns)-1):
        if ns[i] < ns[i+1]:
            if order == "X" or order == "C":
                order = "C"
                continue
            else:
                order = "N"
                break
        else:
            if order == "X" or order == "D":
                order = "D"
                continue
            else:
                order = "N"
                break
    
    print(order)