from string import ascii_uppercase

a = list(
    map(lambda x: ''.join([c for c in x if c in ascii_uppercase]),
        input().split()))

a.sort()

dic = {}

for i in a:
    for c in i:
        dic[c] = dic.get(c, 0) + 1

a = [k for k in dic.keys()]
for i in range(0, len(a)):
    