# -*- coding: utf-8 -*-

# Quicksort ref = https://stackoverflow.com/questions/18262306/quicksort-with-python

def partition(array, begin, end):
    pivot = begin
    for i in range(begin+1, end+1):
        if array[i] <= array[begin]:
            pivot += 1
            array[i], array[pivot] = array[pivot], array[i]
    array[pivot], array[begin] = array[begin], array[pivot]
    return pivot

def quicksort(array, begin, end):
	if begin >= end:
		return
	pivot = partition(array, begin, end)
	quicksort(array, begin, pivot-1)
	quicksort(array, pivot+1, end)

# Init algorithm
amount = int(input())

even = []
odd = []

for _ in range(amount):
    number = int(input())

    if number % 2 == 0:
        even.append(number)
    else:
        odd.append(number)

quicksort(even, 0, len(even) - 1)
quicksort(odd, 0, len(odd) - 1)

for number in even:
    print(number)

for number in reversed(odd):
    print(number)