import csv
from sys import argv

data_read = open(argv[1], 'r')  # opening database file
data_head = csv.reader(data_read)  # reading header of database
head = next(data_head)  # storing header list

data_read.close()
seq = open(argv[2], 'r')
s = seq.read()

dna = {}  # dictionary to store str from header as keys and max counts of str as values
for i in range(len(head)-1):
    dna[head[i+1]] = 0  # storing keys in dict. i.e. str and default value


# iterating through each char in dna sequence
for j in range(len(s)):
    # iterating through each str in database
    for k in range(len(head)-1):
        tandem = head[k+1]
        n = len(tandem)
        c = s[j: j+n]  # c is the substring of length n
        p = 1
        count = 0
        while c == tandem:
            count += 1  # increment no. of str repeats i.e. count

            # checking the next following substring
            q = j + p*n
            c = s[q: q + n]
            p += 1
        # storing max no of str repeats
        if count > dna[head[k+1]]:
            dna[head[k+1]] = count

dread = open(argv[1], 'r')
dataf = csv.DictReader(dread)  # reading database as a dictionary


z = 0
# iterating through each row in dataf dictionary
for row in dataf:
    name = row['name']
    for m in range(len(head)-1):
        # comparing respective columns
        if int(row[head[m+1]]) == int(dna[head[m+1]]):
            z += 1

    if z == (len(head)-1):  # Checking if correct no of columns matched
        print(name)
        break
    z = 0
# if no correct no of columns matched in dictionary:
if z == 0:
    print("No match")

dread.close()