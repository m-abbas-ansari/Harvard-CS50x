from cs50 import get_float

while True:
    cg = (get_float("Change owed: ")) * 100
    if cg > 0 and cg != 0.00:
        break;

n = round(cg)
a = n % 25
p = (n - a) / 25
b = a % 10
q = (a - b) / 10
c = b % 5
r = (b - c) / 5
s = c
ans = round(p + q + r + s)
print(f"{ans} ")






