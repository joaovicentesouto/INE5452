# -*- coding: utf-8 -*-

amount = int(input())
stair_time = 0
last_sensor = int(input())

for i in range(amount-1):
    sensor = int(input())
    diff = sensor - last_sensor

    if diff >= 10:
        stair_time += 10
    else:
        stair_time += diff
    
    last_sensor = sensor

print(stair_time + 10)