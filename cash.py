from cs50 import get_float
#Getting and storing valid change
while True:
    cg = (get_float("Change owed: ")) * 100
    if cg > 0 and cg != 0.00:
        break

n = round(cg) 
a = n % 25 
p = (n - a) / 25 #counting number of 25 cent coins
b = a % 10
q = (a - b) / 10 #counting number of 10 cent coins
c = b % 5
r = (b - c) / 5 #counting number of 5 cent coins
s = c #number of 1 cent coins
ans = round(p + q + r + s) #final no of total coins
print(f"{ans} ")