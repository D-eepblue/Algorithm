T = int(input())

case = []

for _ in range(0, T):
    case.append(int(input()))

for c in case:
    i = 0 if c != 0 else 1
    n = 1 if c != 0 else 0
    for _ in range(0, c-1):
        n += i
        i = n - i
    print(i, n)