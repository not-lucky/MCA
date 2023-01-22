from math import sqrt

a, b = 0, 1
c = 1
n = 100
while (c != n):
    c += 1
    t = b
    b = a + b
    a = t

x = ((1 + sqrt(5)) / 2)**n
y = ((1 - sqrt(5)) / 2)**n
z = 1 / sqrt(5)
print(b)
print(z * (x - y)/100000)
