s = [0] * 3
s[0], s[1], s[2] = map(int, input().split())

s.sort()

if s[0] == s[1] and s[1] == s[2]:
    print(s[0] * 3)
elif s[0] + s[1] > s[2]:
    print(sum(s))
else:
    print((s[0] + s[1])* 2 - 1)

