from cs50 import get_int
#getting a valid height
while True:
    n = get_int("Height: ")
    if n > 0 and n < 9 :
        break
#printing pyramid
for i in range(n):
    #left half
    print(" "*(n - (i + 1)), end = "")
    print("#"*(i + 1), end = "")
    print("  ", end = "")
    #right half
    print("#"*(i + 1), end = "")
    print() # newline