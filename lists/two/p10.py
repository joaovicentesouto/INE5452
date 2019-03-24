# -*- coding: utf-8 -*-

def insert_order(_list, _element):
    pos = 0

    for i in range(len(_list)):
        pos = i
        if _element < _list[i]:
            break
        
        if i == len(_list)-1:
            pos = len(_list)

    _list.insert(pos, _element)

amount = int(input())
names = []
positive = negative = 0
for i in range(amount):
    (signal, name) = input().split(" ")
    if signal == "+":
        positive = positive + 1
    else:
        negative = negative + 1

    insert_order(names, name)

names = list(map(lambda x: print(x), names))
print("Se comportaram: %d | Nao se comportaram: %d" % (positive, negative))
    