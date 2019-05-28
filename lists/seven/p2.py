# -*- coding: utf-8 -*-
def to_int(x):
    return int(x)

while True:
    a, b = input().split()

    if int(a) == 0 and int(b) == 0:
        break
    
    minor = a if len(a) <= len(b) else b
    major = a if len(a) > len(b)  else b

    count = 0
    carry = 0

    for i in range(len(minor)):
        pos = -(i+1)
        n = int(minor[pos]) + int(major[pos]) + carry

        if n > 9:
            carry = 1
            count += 1
        else:
            carry = 0

    for i in range(len(major) - len(minor)):
        pos = -(i + 1 + len(minor))
        n = int(major[pos]) + carry

        if n > 9:
            carry = 1
            count += 1
        else:
            carry = 0

    if count == 0:
        print("No carry operation.")
    elif count == 1:
        print("1 carry operation.")
    else:
        print(count, "carry operations.")
