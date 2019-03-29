import functools

def givemaior(m):

    def mabs(x, y):
        if x < 0: return -(abs(x) % y)
        return x % y

    def maior(a, b):
        if mabs(a, m) == mabs(b, m):
            if a == b: return 0
            if a % 2 == 0 and b % 2 == 1: return 1
            if a % 2 == 0 and b % 2 == 0: return 1 if a > b else -1
            return 1 if a < b else -1
        if mabs(a, m) > mabs(b, m): return 1
        return -1
    return maior

while True:
    n, k = [int(k) for k in input().split()]
    if n == k == 0: break
    m = abs(k)
    xs = []
    for i in range(n):
        x = int(input())
        xs.append(x)
    xs = sorted(xs, key = functools.cmp_to_key(givemaior(m)))
    print(str(n) + ' ' + str(k))
    for i in range(n):
        print(xs[i])
print('0 0')